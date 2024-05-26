/*
 * CHAP-MD5 (RFC 1994)
 */

#ifndef CHAP_H
#define CHAP_H

#define CHAP_MD5_LEN 16

int chap_md5(u8 id, const u8 *secret, size_t secret_len, const u8 *challenge,
	     size_t challenge_len, u8 *response);

#endif /* CHAP_H */
