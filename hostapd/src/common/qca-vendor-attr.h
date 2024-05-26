/*
 * Qualcomm Atheros vendor specific attribute definitions
 */

#ifndef QCA_VENDOR_ATTR_H
#define QCA_VENDOR_ATTR_H

/*
 * This file defines some of the attributes used with Qualcomm Atheros OUI
 * 00:13:74 in a way that is not suitable for qca-vendor.h, e.g., due to
 * compiler dependencies.
 */

struct qca_avoid_freq_range {
    u32 start_freq;
    u32 end_freq;
} __attribute__ ((packed));

struct qca_avoid_freq_list {
    u32 count;
    struct qca_avoid_freq_range range[0];
} __attribute__ ((packed));

#endif /* QCA_VENDOR_ATTR_H */
