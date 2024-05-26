add_library(e_eap_server STATIC
        eap_server.c
        eap_server_identity.c
        eap_server_methods.c
        eap_server_md5.c
        eap_server_mschapv2.c
        eap_server_peap.c
        eap_server_gtc.c
        eap_server_tls.c
        eap_server_ttls.c)