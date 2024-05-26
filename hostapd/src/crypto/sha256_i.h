/*
 * SHA-256 internal definitions
 */

#ifndef SHA256_I_H
#define SHA256_I_H

#define SHA256_BLOCK_SIZE 64

struct sha256_state {
    u64 length;
    u32 state[8], curlen;
    u8 buf[SHA256_BLOCK_SIZE];
};

void sha256_init(struct sha256_state *md);

int sha256_process(struct sha256_state *md, const unsigned char *in,
                   unsigned long inlen);

int sha256_done(struct sha256_state *md, unsigned char *out);

#endif /* SHA256_I_H */
