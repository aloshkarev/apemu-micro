/*
 * WPA Supplicant / Empty template functions for crypto wrapper
 */

#include "utils/includes.h"

#include "utils/common.h"
#include "crypto.h"


int md4_vector(size_t num_elem, const u8 *addr[], const size_t *len, u8 *mac) {
    return 0;
}


int des_encrypt(const u8 *clear, const u8 *key, u8 *cypher) {
    return 0;
}


void crypto_unload(void) {
}
