add_library(e_crypto STATIC
        aes-cbc.c
        aes-ccm.c
        aes-ctr.c
        aes-eax.c
        aes-encblock.c
        aes-gcm.c
        aes-internal.c
        aes-internal-dec.c
        aes-internal-enc.c
#        aes-omac1.c
        aes-siv.c
        aes-unwrap.c
        des-internal.c
        dh_group5.c
        dh_groups.c
        md4-internal.c
#        md5.c
        md5-internal.c
        milenage.c
        ms_funcs.c
#        rc4.c
#        sha1.c
        sha1-internal.c
#        sha1-pbkdf2.c
        sha1-prf.c
        sha1-tlsprf.c
        sha1-tprf.c
        sha256.c
        sha256-prf.c
        sha256-tlsprf.c
#        sha256-internal.c
        sha384.c
        sha384-prf.c
#        sha384-internal.c
        sha512.c
        sha512-prf.c
#        sha512-internal.c
#        crypto_internal.c
        crypto_internal-cipher.c
#        crypto_internal-modexp.c
        crypto_internal-rsa.c
        tls_internal.c
        fips_prf_internal.c
        random.c
        crypto_openssl.c
        )