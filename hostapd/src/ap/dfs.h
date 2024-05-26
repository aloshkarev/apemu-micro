/*
 * DFS - Dynamic Frequency Selection
 */
#ifndef DFS_H
#define DFS_H

int hostapd_handle_dfs(struct hostapd_iface *iface);

int hostapd_dfs_complete_cac(struct hostapd_iface *iface, int success, int freq,
                             int ht_enabled, int chan_offset, int chan_width,
                             int cf1, int cf2);

int hostapd_dfs_pre_cac_expired(struct hostapd_iface *iface, int freq,
                                int ht_enabled, int chan_offset, int chan_width,
                                int cf1, int cf2);

int hostapd_dfs_radar_detected(struct hostapd_iface *iface, int freq,
                               int ht_enabled,
                               int chan_offset, int chan_width,
                               int cf1, int cf2);

int hostapd_dfs_nop_finished(struct hostapd_iface *iface, int freq,
                             int ht_enabled,
                             int chan_offset, int chan_width, int cf1, int cf2);

int hostapd_is_dfs_required(struct hostapd_iface *iface);

int hostapd_is_dfs_chan_available(struct hostapd_iface *iface);

int hostapd_dfs_start_cac(struct hostapd_iface *iface, int freq,
                          int ht_enabled, int chan_offset, int chan_width,
                          int cf1, int cf2);

int hostapd_handle_dfs_offload(struct hostapd_iface *iface);

int hostapd_is_dfs_overlap(struct hostapd_iface *iface, enum chan_width width,
                           int center_freq);

#endif /* DFS_H */
