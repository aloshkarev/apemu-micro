/*
 * IEEE 802.1X-2010 KaY Interface
 */

#ifndef WPA_AUTH_KAY_H
#define WPA_AUTH_KAY_H

#ifdef CONFIG_MACSEC

int ieee802_1x_alloc_kay_sm_hapd(struct hostapd_data *hapd,
                                 struct sta_info *sta);

void *ieee802_1x_notify_create_actor_hapd(struct hostapd_data *hapd,
                                          struct sta_info *sta);

void ieee802_1x_dealloc_kay_sm_hapd(struct hostapd_data *hapd);

void *ieee802_1x_create_preshared_mka_hapd(struct hostapd_data *hapd,
                                           struct sta_info *sta);

#else /* CONFIG_MACSEC */

static inline int ieee802_1x_alloc_kay_sm_hapd(struct hostapd_data *hapd,
                                               struct sta_info *sta) {
    return 0;
}

static inline void *
ieee802_1x_notify_create_actor_hapd(struct hostapd_data *hapd,
                                    struct sta_info *sta) {
    return NULL;
}

static inline void ieee802_1x_dealloc_kay_sm_hapd(struct hostapd_data *hapd) {
}

static inline void *
ieee802_1x_create_preshared_mka_hapd(struct hostapd_data *hapd,
                                     struct sta_info *sta) {
    return NULL;
}

#endif /* CONFIG_MACSEC */

#endif /* WPA_AUTH_KAY_H */
