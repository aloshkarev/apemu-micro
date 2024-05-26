/*
 * Command line editing and history
 */

#ifndef EDIT_H
#define EDIT_H

int edit_init(void (*cmd_cb)(void *ctx, char *cmd),
              void (*eof_cb)(void *ctx),
              char **(*completion_cb)(void *ctx, const char *cmd, int pos),
              void *ctx, const char *history_file, const char *ps);

void edit_deinit(const char *history_file,
                 int (*filter_cb)(void *ctx, const char *cmd));

void edit_clear_line(void);

void edit_redraw(void);

#endif /* EDIT_H */
