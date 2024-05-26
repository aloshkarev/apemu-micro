/*
 * WPS module tests
 */

#include "utils/includes.h"

#include "utils/common.h"
#include "utils/module_tests.h"
#include "wps_attr_parse.h"

struct wps_attr_parse_test {
    const char *data;
    int result;
    int extra;
};

static const struct wps_attr_parse_test wps_attr_parse_test_cases[] = {
        /* Empty message */
        {"", 0, 0},
        /* Truncated attribute header */
        {"10", -1, 0},
        {"1010", -1, 0},
        {"101000", -1, 0},
        /* Attribute overflow */
        {"10100001", -1, 0},
#ifdef CONFIG_WPS_STRICT
        { "10270000001057000101", -1, 0 },
        { "1027000010570001010000000000", -1, 0 },
#else /* CONFIG_WPS_STRICT */
        /* Network Key workaround */
        {"10270000001057000101", 0, 1},
        {"10230000001057000101", -1, 0},
        {"10270000101057000101", -1, 0},
        /* Mac OS X 10.6 padding workaround */
        {"1027000010570001010000000000", 0, 1},
        {"1027000010570001010000000000000001000000", -1, 0},
#endif /* CONFIG_WPS_STRICT */
        /* Version */
        {"104a000110", 0, 0},
        {"104a0000", -1, 0},
        /* Message Type */
        {"1022000101", 0, 0},
        {"10220000", -1, 0},
        /* Enrollee Nonce */
        {"101a001000112233445566778899aabbccddeeff", 0, 0},
        {"101a00111122334455667788990011223344556677", -1, 0},
        /* Registrar Nonce */
        {"1039001000112233445566778899aabbccddeeff", 0, 0},
        {"103900111122334455667788990011223344556677", -1, 0},
        /* UUID-E */
        {"1047001000112233445566778899aabbccddeeff", 0, 0},
        {"10470000", -1, 0},
        {"104700111122334455667788990011223344556677", -1, 0},
        /* UUID-R */
        {"1048001000112233445566778899aabbccddeeff", 0, 0},
        {"10480000", -1, 0},
        {"104800111122334455667788990011223344556677", -1, 0},
        /* Auth Type Flags */
        {"100400021122", 0, 0},
        {"10040001ff", -1, 0},
        /* Encr Type Flags */
        {"101000021122", 0, 0},
        {"10100001ff", -1, 0},
        /* Connection Type Flags */
        {"100d0001ff", 0, 0},
        {"100d0002ffff", -1, 0},
        /* Config Methods */
        {"10080002ffff", 0, 0},
        {"10080001ff", -1, 0},
        /* Selected Registrar Config Methods */
        {"10530002ffff", 0, 0},
        {"10530001ff", -1, 0},
        /* Primary Device Type */
        {"105400081122334455667788", 0, 0},
        {"105400111122334455667788990011223344556677", -1, 0},
        /* RF Bands */
        {"103c0001ff", 0, 0},
        {"103c0002ffff", -1, 0},
        /* Association State */
        {"10020002ffff", 0, 0},
        {"10020001ff", -1, 0},
        /* Config Error */
        {"100900020001", 0, 0},
        {"10090001ff", -1, 0},
        /* Device Password ID */
        {"101200020004", 0, 0},
        {"10120001ff", -1, 0},
        /* OOB Device Password */
        {"102c001611223344556677889900112233445566778899000007", 0, 0},
        {"102c0036112233445566778899001122334455667788990011223344556677889900112233445566778899001122334455667788990011223344",
         0, 0},
        {"102c0001ff", -1, 0},
        {"102c003711223344556677889900112233445566778899001122334455667788990011223344556677889900112233445566778899001122334455",
         -1, 0},
        {"102c002511223344556677889900112233445566778899001122334455667788990011223344556677", -1, 0},
        /* OS Version */
        {"102d000411223344", 0, 0},
        {"102d00111122334455667788990011223344556677", -1, 0},
        /* WPS State */
        {"1044000101", 0, 0},
        {"10440002ffff", -1, 0},
        /* Authenticator */
        {"100500081122334455667788", 0, 0},
        {"10050000", -1, 0},
        {"100500111122334455667788990011223344556677", -1, 0},
        /* R-Hash1 */
        {"103d00201122334455667788990011223344556677889900112233445566778899001122", 0, 0},
        {"103d0000", -1, 0},
        {"103d0021112233445566778899001122334455667788990011223344556677889900112233", -1, 0},
        /* R-Hash2 */
        {"103e00201122334455667788990011223344556677889900112233445566778899001122", 0, 0},
        {"103e0000", -1, 0},
        {"103e0021112233445566778899001122334455667788990011223344556677889900112233", -1, 0},
        /* E-Hash1 */
        {"101400201122334455667788990011223344556677889900112233445566778899001122", 0, 0},
        {"10140000", -1, 0},
        {"10140021112233445566778899001122334455667788990011223344556677889900112233", -1, 0},
        /* E-Hash2 */
        {"101500201122334455667788990011223344556677889900112233445566778899001122", 0, 0},
        {"10150000", -1, 0},
        {"10150021112233445566778899001122334455667788990011223344556677889900112233", -1, 0},
        /* R-SNonce1 */
        {"103f001011223344556677889900112233445566", 0, 0},
        {"103f0000", -1, 0},
        {"103f00111122334455667788990011223344556677", -1, 0},
        /* R-SNonce2 */
        {"1040001011223344556677889900112233445566", 0, 0},
        {"10400000", -1, 0},
        {"104000111122334455667788990011223344556677", -1, 0},
        /* E-SNonce1 */
        {"1016001011223344556677889900112233445566", 0, 0},
        {"10160000", -1, 0},
        {"101600111122334455667788990011223344556677", -1, 0},
        /* E-SNonce2 */
        {"1017001011223344556677889900112233445566", 0, 0},
        {"10170000", -1, 0},
        {"101700111122334455667788990011223344556677", -1, 0},
        /* Key Wrap Authenticator */
        {"101e00081122334455667788", 0, 0},
        {"101e0000", -1, 0},
        {"101e0009112233445566778899", -1, 0},
        /* Authentication Type */
        {"100300020001", 0, 0},
        {"10030001ff", -1, 0},
        /* Encryption Type */
        {"100f00020001", 0, 0},
        {"100f0001ff", -1, 0},
        /* Network Index */
        {"1026000101", 0, 0},
        {"10260002ffff", -1, 0},
        /* Network Key Index */
        {"1028000101", 0, 3},
        {"10280002ffff", -1, 0},
        /* MAC Address */
        {"10200006112233445566", 0, 0},
        {"10200000", -1, 0},
        {"1020000711223344556677", -1, 0},
        /* Selected Registrar */
        {"1041000101", 0, 0},
        {"10410002ffff", -1, 0},
        /* Request Type */
        {"103a000101", 0, 0},
        {"103a0002ffff", -1, 0},
        /* Response Type */
        {"103b000101", 0, 0},
        {"103b0002ffff", -1, 0},
        /* Manufacturer */
        {"10210000", 0, 0},
        /* Model Name */
        {"10230000", 0, 0},
        /* Model Number */
        {"10240000", 0, 0},
        /* Serial Number */
        {"10420000", 0, 0},
        /* Device Name */
        {"10110000", 0, 0},
        /* Public Key */
        {"10320000", 0, 0},
        /* Enc Settings */
        {"10180000", 0, 0},
        /* SSID */
        {"10450000", 0, 0},
        /* AP Setup Locked */
        {"1057000101", 0, 0},
        {"10570002ffff", -1, 0},
        /* Requested Device Type */
        {"106a00081122334455667788", 0, 0},
        {"106a0000", -1, 0},
        {"106a0009112233445566778899", -1, 0},
        /* More than maximum Requested Device Type attributes */
        {"106a00081122334455667788106a00081122334455667788106a00081122334455667788106a00081122334455667788106a00081122334455667788106a00081122334455667788106a00081122334455667788106a00081122334455667788106a00081122334455667788106a00081122334455667788106a00081122334455667788106a00081122334455667788",
         0, 4},
        /* Secondary Device Type List */
        {"105500081122334455667788", 0, 0},
        {"1055000711223344556677", -1, 0},
        {"1055008811223344556677889900112233445566778899001122334455667788990011223344556677889900112233445566778899001122334455667788990011223344556677889900112233445566778899001122334455667788990011223344556677889900112233445566778899001122334455667788990011223344556677889900112233445566",
         -1, 0},
        /* AP Channel */
        {"100100020001", 0, 0},
        {"1001000101", -1, 0},
        /* Skip invalid Vendor Extension */
        {"10490000", 0, 0},
        {"1049000100", 0, 0},
        {"104900020000", 0, 0},
        /* Too long unknown vendor extension */
        {"10490401"
         "112233445566778899001122334455667788990011223344556677889900"
         "112233445566778899001122334455667788990011223344556677889900"
         "112233445566778899001122334455667788990011223344556677889900"
         "112233445566778899001122334455667788990011223344556677889900"
         "112233445566778899001122334455667788990011223344556677889900"
         "112233445566778899001122334455667788990011223344556677889900"
         "112233445566778899001122334455667788990011223344556677889900"
         "112233445566778899001122334455667788990011223344556677889900"
         "112233445566778899001122334455667788990011223344556677889900"
         "112233445566778899001122334455667788990011223344556677889900"
         "112233445566778899001122334455667788990011223344556677889900"
         "112233445566778899001122334455667788990011223344556677889900"
         "112233445566778899001122334455667788990011223344556677889900"
         "112233445566778899001122334455667788990011223344556677889900"
         "112233445566778899001122334455667788990011223344556677889900"
         "112233445566778899001122334455667788990011223344556677889900"
         "112233445566778899001122334455667788990011223344556677889900"
         "112233445566778899001122334455667788990011223344556677889900"
         "112233445566778899001122334455667788990011223344556677889900"
         "112233445566778899001122334455667788990011223344556677889900"
         "112233445566778899001122334455667788990011223344556677889900"
         "112233445566778899001122334455667788990011223344556677889900"
         "112233445566778899001122334455667788990011223344556677889900"
         "112233445566778899001122334455667788990011223344556677889900"
         "112233445566778899001122334455667788990011223344556677889900"
         "112233445566778899001122334455667788990011223344556677889900"
         "112233445566778899001122334455667788990011223344556677889900"
         "112233445566778899001122334455667788990011223344556677889900"
         "112233445566778899001122334455667788990011223344556677889900"
         "112233445566778899001122334455667788990011223344556677889900"
         "112233445566778899001122334455667788990011223344556677889900"
         "112233445566778899001122334455667788990011223344556677889900"
         "112233445566778899001122334455667788990011223344556677889900"
         "112233445566778899001122334455667788990011223344556677889900"
         "1122334455", -1, 0},
        /* Maximum unknown vendor extensions */
        {"10490003111111104900032222221049000333333310490003444444104900035555551049000366666610490003777777104900038888881049000399999910490003AAAAAA",
         0, 5},
        /* More than maximum unknown vendor extensions */
        {"10490003111111104900032222221049000333333310490003444444104900035555551049000366666610490003777777104900038888881049000399999910490003AAAAAA10490003BBBBBB",
         -1, 0},
        /* WFA vendor extensions */
        {"1049000300372a", 0, 0},
        {"1049000400372a00", 0, 0},
        {"1049000500372a0001", 0, 0},
        {"1049001600372a0001ff0100020101030101040101ff00fe0101", 0, 6},
        /* Invalid Version2 length */
        {"1049000500372a0000", -1, 0},
        /* Invalid Network Key Shareable length */
        {"1049000500372a0200", -1, 0},
        /* Invalid Requedt To Enroll length */
        {"1049000500372a0300", -1, 0},
        /* Invalid Settings Delay Time length */
        {"1049000500372a0400", -1, 0},
        /* More than maximum Credential attributes */
        {"100e0000100e0000100e0000100e0000100e0000100e0000100e0000100e0000100e0000100e0000100e0000100e0000", 0, 2},
};


static int wps_attr_parse_tests(void) {
    struct wps_parse_attr attr;
    unsigned int i;
    int ret = 0;

    wpa_printf(MSG_INFO, "WPS attribute parsing tests");

    for (i = 0; i < ARRAY_SIZE(wps_attr_parse_test_cases); i++) {
        struct wpabuf *buf;
        size_t len;
        const struct wps_attr_parse_test *test =
                &wps_attr_parse_test_cases[i];

        len = os_strlen(test->data) / 2;
        buf = wpabuf_alloc(len);
        if (buf == NULL)
            return -1;
        if (hexstr2bin(test->data, wpabuf_put(buf, len), len) < 0) {
            wpabuf_free(buf);
            return -1;
        }
        if (wps_parse_msg(buf, &attr) != test->result) {
            wpa_printf(MSG_ERROR, "WPS attribute parsing test %u failed: %s",
                       i, test->data);
            ret = -1;
        }
        switch (test->extra) {
            case 1:
                if (!attr.network_key || !attr.ap_setup_locked)
                    ret = -1;
                break;
            case 2:
                if (attr.num_cred != MAX_CRED_COUNT)
                    ret = -1;
                break;
            case 3:
                if (!attr.network_key_idx)
                    ret = -1;
                break;
            case 4:
                if (attr.num_req_dev_type != MAX_REQ_DEV_TYPE_COUNT)
                    ret = -1;
                break;
            case 5:
                if (attr.num_vendor_ext != MAX_WPS_PARSE_VENDOR_EXT)
                    ret = -1;
                break;
            case 6:
                if (!attr.version2 ||
                    !attr.authorized_macs ||
                    !attr.network_key_shareable ||
                    !attr.request_to_enroll ||
                    !attr.settings_delay_time)
                    ret = -1;
                break;
        }
        wpabuf_free(buf);
    }

    return ret;
}


int wps_module_tests(void) {
    int ret = 0;

    wpa_printf(MSG_INFO, "WPS module tests");

    if (wps_attr_parse_tests() < 0)
        ret = -1;

    return ret;
}
