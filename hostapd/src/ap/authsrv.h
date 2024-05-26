/*
 * Authentication server setup
 */

#ifndef AUTHSRV_H
#define AUTHSRV_H

int authsrv_init(struct hostapd_data *hapd);

void authsrv_deinit(struct hostapd_data *hapd);

#endif /* AUTHSRV_H */
