/*
 * wpa_supplicant - Wi-Fi Display
 */

#ifndef WIFI_DISPLAY_H
#define WIFI_DISPLAY_H

int wifi_display_init(struct wpa_global *global);
void wifi_display_deinit(struct wpa_global *global);
void wifi_display_enable(struct wpa_global *global, int enabled);
struct wpabuf *wifi_display_get_wfd_ie(struct wpa_global *global);
int wifi_display_subelem_set(struct wpa_global *global, char *cmd);
int wifi_display_subelem_set_from_ies(struct wpa_global *global,
				      struct wpabuf *ie);
int wifi_display_subelem_get(struct wpa_global *global, char *cmd,
			     char *buf, size_t buflen);
char * wifi_display_subelem_hex(const struct wpabuf *wfd_subelems, u8 id);

#endif /* WIFI_DISPLAY_H */
