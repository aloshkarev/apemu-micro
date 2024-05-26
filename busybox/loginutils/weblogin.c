/* vi: set sw=4 ts=4: */
/*
 * Licensed under GPLv2 or later, see file LICENSE in this source tree.
 */

//config:config WEBLOGIN
//config:	bool "weblogin"
//config:	default y
//config:	select FEATURE_SYSLOG
//config:	help
//config:	weblogin is used when wee need check credentials for web session.
//config:	Note that Busybox binary must be setuid root for this applet to
//config:	work properly.

//applet:/* Needs to be run by root or be suid root - needs to change uid and gid: */
//applet:IF_WEBLOGIN(APPLET(weblogin, BB_DIR_BIN, BB_SUID_REQUIRE))

//kbuild:lib-$(CONFIG_WEBLOGIN) += weblogin.o

//usage:#define weblogin_trivial_usage
//usage:       " USER"
//usage:#define weblogin_full_usage "\n\n"
//usage:       "Check user credentials for web session\n"

#include "libbb.h"
#include "common_bufsiz.h"
#include <syslog.h>
#include <sys/resource.h>

#if ENABLE_SELINUX
# include <selinux/selinux.h>  /* for is_selinux_enabled()  */
# include <selinux/get_context_list.h> /* for get_default_context() */
# include <selinux/flask.h> /* for security class definitions  */
#endif

#if ENABLE_PAM
/* PAM may include <locale.h>. We may need to undefine bbox's stub define: */
# undef setlocale
/* For some obscure reason, PAM is not in pam/xxx, but in security/xxx.
 * Apparently they like to confuse people. */
# include <security/pam_appl.h>
# include <security/pam_misc.h>
static const struct pam_conv conv = {
	misc_conv,
	NULL
};
#endif

enum {
	/* Some users found 32 chars limit to be too low: */
	USERNAME_SIZE = 64,
};

struct globals {
	struct termios tty_attrs;
} FIX_ALIASING;
#define G (*(struct globals*)&bb_common_bufsiz1)
#define INIT_G() do { } while (0)

static void interrupt_handler(int sig UNUSED_PARAM) {
  tcsetattr_stdin_TCSANOW(&G.tty_attrs);
  exit(-1);
}

static char *get_role(int uid) {
  static char role[256] = {"admin"};
  FILE *f = fopen("/tmp/.user_roles", "r");
  if(f) {
    char buffer[256];
    while(fgets(buffer, sizeof(buffer), f)) {
      char *last = NULL;
      char *token = strtok_r(buffer, ":\n\r", &last);
      if(token) {
        int current_uid = atoi(token);
        if(current_uid == uid) {
          token = strtok_r(NULL, ":\n\r", &last);
          if(token) {
            strncpy(role, token, sizeof(role));
            fclose(f);
            return role;
          }
        }
      }
    }
    fclose(f);
  }
  return role;
}

#if ENABLE_PAM
static void login_pam_end(pam_handle_t *pamh)
{
	int pamret;

	pamret = pam_setcred(pamh, PAM_DELETE_CRED);
	if (pamret != PAM_SUCCESS) {
		bb_error_msg("pam_%s failed: %s (%d)", "setcred",
			pam_strerror(pamh, pamret), pamret);
	}
	pamret = pam_close_session(pamh, 0);
	if (pamret != PAM_SUCCESS) {
		bb_error_msg("pam_%s failed: %s (%d)", "close_session",
			pam_strerror(pamh, pamret), pamret);
	}
	pamret = pam_end(pamh, pamret);
	if (pamret != PAM_SUCCESS) {
		bb_error_msg("pam_%s failed: %s (%d)", "end",
			pam_strerror(pamh, pamret), pamret);
	}
}
#endif /* ENABLE_PAM */

int weblogin_main(int argc, char **argv) MAIN_EXTERNALLY_VISIBLE;
int weblogin_main(int argc UNUSED_PARAM, char **argv)
{
	char username[USERNAME_SIZE];
	int run_by_root;
	struct passwd *pw;
        int is_logout = 0;
	IF_SELINUX(security_context_t user_sid = NULL;)
#if ENABLE_PAM
	int pamret;
	pam_handle_t *pamh;
	const char *pamuser;
	const char *failed_msg;
	struct passwd pwdstruct;
	char pwdbuf[256];
#endif
        {
          const char *value = getenv("SERVER_SOFTWARE");
          if(!value || strcmp(value, "lighttpd")) {
            printf("fail: weblogin can be executed only for web authentication\n");
            return EXIT_FAILURE;
          }
        }
	INIT_G();

        tcgetattr(STDIN_FILENO, &G.tty_attrs);
        signal(SIGINT, interrupt_handler);
	/* More of suid paranoia if called by non-root: */
	/* Clear dangerous stuff, set PATH */
	run_by_root = !sanitize_env_if_suid();

	/* Mandatory paranoia for suid applet:
	 * ensure that fd# 0,1,2 are opened (at least to /dev/null)
	 * and any extra open fd's are closed.
	 * (The name of the function is misleading. Not daemonizing here.) */
	bb_daemonize_or_rexec(DAEMON_ONLY_SANITIZE | DAEMON_CLOSE_EXTRA_FDS, NULL);

	username[0] = '\0';

	if (argc >= 2 && argv[1])
          safe_strncpy(username, argv[1], sizeof(username));

        if (argc >= 3 && argv[2] && !strcmp(argv[2], "logout")) {
          is_logout = 1;
        }

	openlog(applet_name, LOG_PID | LOG_CONS, LOG_AUTH);
        if(is_logout) {
#if ENABLE_PAM
          pamret = pam_start("weblogin", username, &conv, &pamh);
          if (pamret != PAM_SUCCESS) {
            goto logout_failure;
          }
          login_pam_end(pamh);
          return 0;
        logout_failure:
          printf("fail\n");
          return EXIT_FAILURE;
#endif
          return 0;
        }
#if ENABLE_PAM
		pamret = pam_start("weblogin", username, &conv, &pamh);
		if (pamret != PAM_SUCCESS) {
			failed_msg = "start";
			goto pam_auth_failed;
		}
                pamret = pam_authenticate(pamh, 0);
                if (pamret != PAM_SUCCESS) {
                  failed_msg = "authenticate";
                  goto pam_auth_failed;
                  /* TODO: or just "goto auth_failed"
                   * since user seems to enter wrong password
                   * (in this case pamret == 7)
                   */
                }
		/* check that the account is healthy */
		pamret = pam_acct_mgmt(pamh, 0);
		if (pamret != PAM_SUCCESS) {
			failed_msg = "acct_mgmt";
			goto pam_auth_failed;
		}
		/* read user back */
		pamuser = NULL;
		/* gcc: "dereferencing type-punned pointer breaks aliasing rules..."
		 * thus we cast to (void*) */
		if (pam_get_item(pamh, PAM_USER, (void*)&pamuser) != PAM_SUCCESS) {
			failed_msg = "get_item(USER)";
			goto pam_auth_failed;
		}
		if (!pamuser || !pamuser[0])
			goto auth_failed;
		safe_strncpy(username, pamuser, sizeof(username));
		/* Don't use "pw = getpwnam(username);",
		 * PAM is said to be capable of destroying static storage
		 * used by getpwnam(). We are using safe(r) function */
		pw = NULL;
		getpwnam_r(username, &pwdstruct, pwdbuf, sizeof(pwdbuf), &pw);
		if (!pw)
			goto auth_failed;
		pamret = pam_open_session(pamh, 0);
		if (pamret != PAM_SUCCESS) {
			failed_msg = "open_session";
			goto pam_auth_failed;
		}
		pamret = pam_setcred(pamh, PAM_ESTABLISH_CRED);
		if (pamret != PAM_SUCCESS) {
			failed_msg = "setcred";
			goto pam_auth_failed;
		}
		goto exit_success;

 pam_auth_failed:
		/* syslog, because we don't want potential attacker
		 * to know _why_ login failed */
		syslog(LOG_WARNING, "pam_%s call failed: %s (%d)", failed_msg,
					pam_strerror(pamh, pamret), pamret);
		safe_strncpy(username, "UNKNOWN", sizeof(username));
#else /* not PAM */
		pw = getpwnam(username);
		if (!pw) {
			strcpy(username, "UNKNOWN");
			goto fake_it;
		}

		if (pw->pw_passwd[0] == '!' || pw->pw_passwd[0] == '*')
			goto auth_failed;

		/* Don't check the password if password entry is empty (!) */
		if (!pw->pw_passwd[0])
			goto exit_success;
 fake_it:
		/* Password reading and authorization takes place here.
		 * Note that reads (in no-echo mode) trash tty attributes.
		 * If we get interrupted by SIGALRM, we need to restore attrs.
		 */

		if (ask_and_check_password(pw) > 0)
                  goto exit_success;
#endif /* ENABLE_PAM */
 auth_failed:

                printf("fail\n");
                return EXIT_FAILURE;
 exit_success:
#if ENABLE_PAM
                printf("success %s %d\n", get_role(pwdstruct.pw_uid), pwdstruct.pw_uid);
#else
                printf("success %s %d\n", get_role(pw->pw_uid), pw->pw_uid);
#endif
                return 0;
}
