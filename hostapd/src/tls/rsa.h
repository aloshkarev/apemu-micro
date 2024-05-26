/*
 * RSA
 */

#ifndef RSA_H
#define RSA_H

struct crypto_rsa_key;

struct crypto_rsa_key *
crypto_rsa_import_public_key(const u8 *buf, size_t len);

struct crypto_rsa_key *
crypto_rsa_import_public_key_parts(const u8 *n, size_t n_len,
                                   const u8 *e, size_t e_len);

struct crypto_rsa_key *
crypto_rsa_import_private_key(const u8 *buf, size_t len);

size_t crypto_rsa_get_modulus_len(struct crypto_rsa_key *key);

int crypto_rsa_exptmod(const u8 *in, size_t inlen, u8 *out, size_t *outlen,
                       struct crypto_rsa_key *key, int use_private);

void crypto_rsa_free(struct crypto_rsa_key *key);

#endif /* RSA_H */