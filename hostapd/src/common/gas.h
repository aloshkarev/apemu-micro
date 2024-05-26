/*
 * Generic advertisement service (GAS) (IEEE 802.11u)
 */

#ifndef GAS_H
#define GAS_H

struct wpabuf *gas_build_initial_req(u8 dialog_token, size_t size);

struct wpabuf *gas_build_comeback_req(u8 dialog_token);

struct wpabuf *gas_build_initial_resp(u8 dialog_token, u16 status_code,
                                      u16 comeback_delay, size_t size);

struct wpabuf *
gas_build_comeback_resp(u8 dialog_token, u16 status_code, u8 frag_id, u8 more,
                        u16 comeback_delay, size_t size);

struct wpabuf *gas_anqp_build_initial_req(u8 dialog_token, size_t size);

struct wpabuf *gas_anqp_build_initial_resp(u8 dialog_token, u16 status_code,
                                           u16 comeback_delay, size_t size);

struct wpabuf *gas_anqp_build_initial_resp_buf(u8 dialog_token,
                                               u16 status_code,
                                               u16 comeback_delay,
                                               struct wpabuf *payload);

struct wpabuf *gas_anqp_build_comeback_resp(u8 dialog_token, u16 status_code,
                                            u8 frag_id, u8 more,
                                            u16 comeback_delay, size_t size);

struct wpabuf *gas_anqp_build_comeback_resp_buf(u8 dialog_token,
                                                u16 status_code,
                                                u8 frag_id, u8 more,
                                                u16 comeback_delay,
                                                struct wpabuf *payload);

void gas_anqp_set_len(struct wpabuf *buf);

u8 *gas_anqp_add_element(struct wpabuf *buf, u16 info_id);

void gas_anqp_set_element_len(struct wpabuf *buf, u8 *len_pos);

#endif /* GAS_H */
