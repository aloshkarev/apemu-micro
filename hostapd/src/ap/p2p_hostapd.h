/*
 * hostapd / P2P integration
 */

#ifndef P2P_HOSTAPD_H
#define P2P_HOSTAPD_H

#ifdef CONFIG_P2P

int hostapd_p2p_get_mib_sta(struct hostapd_data *hapd, struct sta_info *sta,
                char *buf, size_t buflen);
int hostapd_p2p_set_noa(struct hostapd_data *hapd, u8 count, int start,
            int duration);
void hostapd_p2p_non_p2p_sta_connected(struct hostapd_data *hapd);
void hostapd_p2p_non_p2p_sta_disconnected(struct hostapd_data *hapd);


#else /* CONFIG_P2P */

static inline int hostapd_p2p_get_mib_sta(struct hostapd_data *hapd,
                                          struct sta_info *sta,
                                          char *buf, size_t buflen) {
    return 0;
}

#endif /* CONFIG_P2P */

u8 *hostapd_eid_p2p_manage(struct hostapd_data *hapd, u8 *eid);

#endif /* P2P_HOSTAPD_H */
