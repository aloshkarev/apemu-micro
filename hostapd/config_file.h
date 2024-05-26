/*
 * hostapd / Configuration file parser
 */

#ifndef CONFIG_FILE_H
#define CONFIG_FILE_H

struct hostapd_config * hostapd_config_read(const char *fname);
int hostapd_set_iface(struct hostapd_config *conf,
		      struct hostapd_bss_config *bss, const char *field,
		      char *value);

#endif /* CONFIG_FILE_H */
