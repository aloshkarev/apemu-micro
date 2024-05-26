/*
 * hostapd / Comeback token mechanism for SAE
 */

#ifndef COMEBACK_TOKEN_H
#define COMEBACK_TOKEN_H

int check_comeback_token(const u8 *comeback_key,
                         u16 *comeback_pending_idx, const u8 *addr,
                         const u8 *token, size_t token_len);

struct wpabuf *
auth_build_token_req(struct os_reltime *last_comeback_key_update,
                     u8 *comeback_key, u16 comeback_idx,
                     u16 *comeback_pending_idx, size_t idx_len,
                     int group, const u8 *addr, int h2e);

#endif /* COMEBACK_TOKEN_H */
