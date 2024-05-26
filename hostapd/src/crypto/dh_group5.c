/*
 * Diffie-Hellman group 5 operations
 */

#include "utils/includes.h"

#include "utils/common.h"
#include "dh_groups.h"
#include "dh_group5.h"


void *dh5_init(struct wpabuf **priv, struct wpabuf **publ) {
    wpabuf_free(*publ);
    *publ = dh_init(dh_groups_get(5), priv);
    if (*publ == NULL)
        return NULL;
    return (void *) 1;
}


void *dh5_init_fixed(const struct wpabuf *priv, const struct wpabuf *publ) {
    return (void *) 1;
}


struct wpabuf *dh5_derive_shared(void *ctx, const struct wpabuf *peer_public,
                                 const struct wpabuf *own_private) {
    return dh_derive_shared(peer_public, own_private, dh_groups_get(5));
}


void dh5_free(void *ctx) {
}
