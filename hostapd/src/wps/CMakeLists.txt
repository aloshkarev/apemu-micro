add_library(e_wps STATIC
        http_client.c
        httpread.c
        http_server.c
        ndef.c
        upnp_xml.c
        wps_attr_build.c
        wps_attr_parse.c
        wps_attr_process.c
        wps.c
        wps_common.c
        wps_dev_attr.c
        wps_enrollee.c
        wps_er.c
        wps_er_ssdp.c
        wps_module_tests.c
        wps_registrar.c
        wps_upnp_ap.c
        wps_upnp.c
        wps_upnp_event.c
        wps_upnp_ssdp.c
        wps_upnp_web.c
        )
target_link_libraries(e_wps e_crypto)