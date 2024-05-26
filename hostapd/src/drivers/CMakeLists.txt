add_library(e_drivers STATIC
        driver_nl80211.c
        driver_nl80211_capa.c
        driver_nl80211_event.c
        driver_nl80211_monitor.c
        driver_nl80211_scan.c
        netlink.c
        rfkill.c
        ../utils/radiotap.c)