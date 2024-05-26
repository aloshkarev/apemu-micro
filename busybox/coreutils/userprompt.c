/* vi: set sw=4 ts=4: */
/*
 * Userprompt implementation for busybox
 */

/* BB_AUDIT SUSv3 N/A -- Matches GNU behavior. */

//usage:#define userprompt_trivial_usage
//usage:       ""
//usage:#define userprompt_full_usage "\n\n"
//usage:       "Print the user prompt"

#include "libbb.h"

/* This is a NOFORK applet. Be very careful! */

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

int userprompt_main(int argc, char **argv) MAIN_EXTERNALLY_VISIBLE;
int userprompt_main(int argc UNUSED_PARAM, char **argv UNUSED_PARAM)
{
  uid_t uid = geteuid();
  if(!uid || !strcmp(get_role(uid), "admin")) {
    printf("#");
    fflush(stdout);
    return 0;
  }
  printf("$");
  fflush(stdout);
  return 0;
}