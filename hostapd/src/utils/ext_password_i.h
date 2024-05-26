/*
 * External password backend - internal definitions
 */

#ifndef EXT_PASSWORD_I_H
#define EXT_PASSWORD_I_H

#include "ext_password.h"

struct ext_password_backend {
    const char *name;

    void *(*init)(const char *params);

    void (*deinit)(void *ctx);

    struct wpabuf *(*get)(void *ctx, const char *name);
};

struct wpabuf *ext_password_alloc(size_t len);

/* Available ext_password backends */

#ifdef CONFIG_EXT_PASSWORD_TEST
extern const struct ext_password_backend ext_password_test;
#endif /* CONFIG_EXT_PASSWORD_TEST */

#ifdef CONFIG_EXT_PASSWORD_FILE
extern const struct ext_password_backend ext_password_file;
#endif /* CONFIG_EXT_PASSWORD_FILE */

#endif /* EXT_PASSWORD_I_H */
