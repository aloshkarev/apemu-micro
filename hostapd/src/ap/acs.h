/*
 * ACS - Automatic Channel Selection module
 */

#ifndef ACS_H
#define ACS_H

#ifdef CONFIG_ACS

enum hostapd_chan_status acs_init(struct hostapd_iface *iface);
void acs_cleanup(struct hostapd_iface *iface);

#else /* CONFIG_ACS */

static inline enum hostapd_chan_status acs_init(struct hostapd_iface *iface) {
    wpa_printf(MSG_ERROR, "ACS was disabled on your build, rebuild hostapd with CONFIG_ACS=y or set channel");
    return HOSTAPD_CHAN_INVALID;
}

static inline void acs_cleanup(struct hostapd_iface *iface) {
}

#endif /* CONFIG_ACS */

#endif /* ACS_H */
