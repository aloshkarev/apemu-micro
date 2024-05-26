/*
 * hostapd / WPA authenticator glue code
 */

#ifndef WPA_AUTH_GLUE_H
#define WPA_AUTH_GLUE_H

int hostapd_setup_wpa(struct hostapd_data *hapd);

void hostapd_reconfig_wpa(struct hostapd_data *hapd);

void hostapd_deinit_wpa(struct hostapd_data *hapd);

#endif /* WPA_AUTH_GLUE_H */
