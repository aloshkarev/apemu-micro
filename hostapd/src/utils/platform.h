/*
 * Platform definitions for Radiotap parser
 */

#ifndef PLATFORM_H
#define PLATFORM_H

#include "includes.h"
#include "common.h"

#define get_unaligned_le16(p)    WPA_GET_LE16((void *) (p))
#define get_unaligned_le32(p)    WPA_GET_LE32((void *) (p))

#endif /* PLATFORM_H */
