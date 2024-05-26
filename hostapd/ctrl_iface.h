/*
 * hostapd / UNIX domain socket -based control interface
 */

#ifndef CTRL_IFACE_H
#define CTRL_IFACE_H

#ifndef CONFIG_NO_CTRL_IFACE
int hostapd_ctrl_iface_init(struct hostapd_data *hapd);
void hostapd_ctrl_iface_deinit(struct hostapd_data *hapd);
int hostapd_global_ctrl_iface_init(struct hapd_interfaces *interface);
void hostapd_global_ctrl_iface_deinit(struct hapd_interfaces *interface);
#else /* CONFIG_NO_CTRL_IFACE */
static inline int hostapd_ctrl_iface_init(struct hostapd_data *hapd)
{
	return 0;
}

static inline void hostapd_ctrl_iface_deinit(struct hostapd_data *hapd)
{
}

static inline int
hostapd_global_ctrl_iface_init(struct hapd_interfaces *interface)
{
	return 0;
}

static inline void
hostapd_global_ctrl_iface_deinit(struct hapd_interfaces *interface)
{
}
#endif /* CONFIG_NO_CTRL_IFACE */

#endif /* CTRL_IFACE_H */
