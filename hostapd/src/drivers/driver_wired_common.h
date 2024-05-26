/*
 * Common definitions for Wired Ethernet driver interfaces
 */

#ifndef DRIVER_WIRED_COMMON_H
#define DRIVER_WIRED_COMMON_H

struct driver_wired_common_data {
	char ifname[IFNAMSIZ + 1];
	void *ctx;

	int sock; /* raw packet socket for driver access */
	int pf_sock;
	int membership, multi, iff_allmulti, iff_up;
};

static const u8 pae_group_addr[ETH_ALEN] =
{ 0x01, 0x80, 0xc2, 0x00, 0x00, 0x03 };

int wired_multicast_membership(int sock, int ifindex, const u8 *addr, int add);
int driver_wired_get_ssid(void *priv, u8 *ssid);
int driver_wired_get_bssid(void *priv, u8 *bssid);
int driver_wired_get_capa(void *priv, struct wpa_driver_capa *capa);

int driver_wired_init_common(struct driver_wired_common_data *common,
			     const char *ifname, void *ctx);
void driver_wired_deinit_common(struct driver_wired_common_data *common);

#endif /* DRIVER_WIRED_COMMON_H */
