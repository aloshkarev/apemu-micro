/*
 * hostapd / Neighboring APs DB
 */

#ifndef NEIGHBOR_DB_H
#define NEIGHBOR_DB_H

struct hostapd_neighbor_entry *
hostapd_neighbor_get(struct hostapd_data *hapd, const u8 *bssid,
                     const struct wpa_ssid_value *ssid);

int hostapd_neighbor_show(struct hostapd_data *hapd, char *buf, size_t buflen);

int hostapd_neighbor_set(struct hostapd_data *hapd, const u8 *bssid,
                         const struct wpa_ssid_value *ssid,
                         const struct wpabuf *nr, const struct wpabuf *lci,
                         const struct wpabuf *civic, int stationary,
                         u8 bss_parameters);

void hostapd_neighbor_set_own_report(struct hostapd_data *hapd);

int hostapd_neighbor_remove(struct hostapd_data *hapd, const u8 *bssid,
                            const struct wpa_ssid_value *ssid);

void hostapd_free_neighbor_db(struct hostapd_data *hapd);

#endif /* NEIGHBOR_DB_H */
