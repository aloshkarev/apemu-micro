/*
 * hostapd / TKIP countermeasures
 */

#ifndef TKIP_COUNTERMEASURES_H
#define TKIP_COUNTERMEASURES_H

int michael_mic_failure(struct hostapd_data *hapd, const u8 *addr, int local);

void ieee80211_tkip_countermeasures_deinit(struct hostapd_data *hapd);

#endif /* TKIP_COUNTERMEASURES_H */
