/*
 * 32-bit CRC for FCS calculation
 */

#ifndef CRC32_H
#define CRC32_H

u32 ieee80211_crc32(const u8 *frame, size_t frame_len);

#endif /* CRC32_H */
