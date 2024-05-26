/*
 * wpa_supplicant - WPA/RSN IE and KDE definitions
 */

#ifndef WPA_IE_H
#define WPA_IE_H

struct wpa_sm;

int wpa_gen_wpa_ie(struct wpa_sm *sm, u8 *wpa_ie, size_t wpa_ie_len);
int wpa_gen_rsnxe(struct wpa_sm *sm, u8 *rsnxe, size_t rsnxe_len);
u16 rsn_supp_capab(struct wpa_sm *sm);

#endif /* WPA_IE_H */
