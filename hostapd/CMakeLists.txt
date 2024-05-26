cmake_minimum_required(VERSION 3.10)

project(eltex-hostapd VERSION 0.01 LANGUAGES C)
message(STATUS "")
message(STATUS "${PROJECT_NAME} section")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(AP_DIR "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
find_package(AP CONFIG)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/SetAPConfigOptions.cmake)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(/usr/include/libnl3)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

add_subdirectory(src/ap)
add_subdirectory(src/crypto)
add_subdirectory(src/common)
add_subdirectory(src/drivers)
add_subdirectory(src/eap_common)
add_subdirectory(src/eap_peer)
add_subdirectory(src/eap_server)
add_subdirectory(src/eapol_auth)
add_subdirectory(src/eapol_supp)
add_subdirectory(src/fst)
add_subdirectory(src/l2_packet)
add_subdirectory(src/p2p)
add_subdirectory(src/pae)
add_subdirectory(src/pasn)
add_subdirectory(src/radius)
add_subdirectory(src/rsn_supp)
add_subdirectory(src/tls)
add_subdirectory(src/utils)
add_subdirectory(src/wps)
add_subdirectory(src/wpa_supplicant)

message(STATUS "CMAKE_C_FLAGS for hostapd is ${CMAKE_C_FLAGS}")

add_executable(eltex_hostapd
        main.c
        config_file.c)

target_link_libraries(eltex_hostapd
        e_ap
        e_common
        e_crypto
        e_drivers
        e_eap_common
        e_eap_peer
        e_eap_server
        e_eapol_auth
        e_eapol_supp
        e_fst
        e_l2_packet
        e_p2p
        e_pae
        e_pasn
        e_radius
        e_rsn_supp
        e_tls
        e_utils
        e_wps
        )

target_link_libraries(eltex_hostapd dl rt nl-3 nl-genl-3 crypto tommath)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DCONFIG_CTRL_IFACE -DCONFIG_CTRL_IFACE_UNIX")
add_executable(eltex_hostapd_cli
        hostapd_cli.c
        src/common/cli.c
        src/common/wpa_ctrl.c
        src/utils/wpa_debug.c
        src/utils/common.c
        src/utils/eloop.c
        src/utils/edit.c
        src/utils/os_unix.c
        )

target_link_libraries(eltex_hostapd_cli dl z rt nl-3 nl-genl-3)

#add_executable(wpa_supplicant
#        )
#
#add_executable(wpa_cli
#        )