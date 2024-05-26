/*
 * hostapd / Station client taxonomy
 */

#ifndef TAXONOMY_H
#define TAXONOMY_H

void taxonomy_sta_info_probe_req(const struct hostapd_data *hapd,
                                 struct sta_info *sta,
                                 const u8 *ie, size_t ie_len);

void taxonomy_hostapd_sta_info_probe_req(const struct hostapd_data *hapd,
                                         struct hostapd_sta_info *sta,
                                         const u8 *ie, size_t ie_len);

void taxonomy_sta_info_assoc_req(const struct hostapd_data *hapd,
                                 struct sta_info *sta,
                                 const u8 *ie, size_t ie_len);

int retrieve_sta_taxonomy(const struct hostapd_data *hapd,
                          struct sta_info *sta, char *buf, size_t buflen);

#endif /* TAXONOMY_H */
