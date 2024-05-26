/*
 * MD5 internal definitions
 */

#ifndef MD5_I_H
#define MD5_I_H

struct MD5Context {
    u32 buf[4];
    u32 bits[2];
    u8 in[64];
};

void MD5Init(struct MD5Context *context);

void MD5Update(struct MD5Context *context, unsigned char const *buf,
               unsigned len);

void MD5Final(unsigned char digest[16], struct MD5Context *context);

#endif /* MD5_I_H */
