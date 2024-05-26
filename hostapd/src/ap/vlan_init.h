/*
 * hostapd / VLAN initialization
 */

#ifndef VLAN_INIT_H
#define VLAN_INIT_H

#ifndef CONFIG_NO_VLAN

int vlan_init(struct hostapd_data *hapd);

void vlan_deinit(struct hostapd_data *hapd);

struct hostapd_vlan *vlan_add_dynamic(struct hostapd_data *hapd,
                                      struct hostapd_vlan *vlan,
                                      int vlan_id,
                                      struct vlan_description *vlan_desc);

int vlan_remove_dynamic(struct hostapd_data *hapd, int vlan_id);

#else /* CONFIG_NO_VLAN */
static inline int vlan_init(struct hostapd_data *hapd)
{
    return 0;
}

static inline void vlan_deinit(struct hostapd_data *hapd)
{
}

static inline struct hostapd_vlan *
vlan_add_dynamic(struct hostapd_data *hapd, struct hostapd_vlan *vlan,
         int vlan_id, struct vlan_description *vlan_desc)
{
    return NULL;
}

static inline int vlan_remove_dynamic(struct hostapd_data *hapd, int vlan_id)
{
    return -1;
}
#endif /* CONFIG_NO_VLAN */

#endif /* VLAN_INIT_H */
