/*
 * PKCS #8 (Private-key information syntax)
 */

#ifndef PKCS8_H
#define PKCS8_H

struct crypto_private_key *pkcs8_key_import(const u8 *buf, size_t len);

struct crypto_private_key *
pkcs8_enc_key_import(const u8 *buf, size_t len, const char *passwd);

#endif /* PKCS8_H */
