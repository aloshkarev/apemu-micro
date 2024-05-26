# This file lists the configuration options that are used when building the
# hostapd binary. All lines starting with # are ignored. Configuration option
# lines must be commented out complete, if they are not to be included, i.e.,
# just setting VARIABLE=n is not disabling that variable.
#
# This file is included in Makefile, so variables like CFLAGS and LIBS can also
# be modified from here. In most cass, these lines should use += in order not
# to override previous values of the variables.

# Driver interface for Host AP driver
set(CONFIG_DRIVER_HOSTAP ON)

# Driver interface for wired authenticator
#set(CONFIG_DRIVER_WIRED ON)

# Driver interface for drivers using the nl80211 kernel interface
set(CONFIG_DRIVER_NL80211 ON)

# QCA vendor extensions to nl80211
#set(CONFIG_DRIVER_NL80211_QCA ON)

# driver_nl80211.c requires libnl. If you are compiling it yourself
# you may need to point hostapd to your version of libnl.
# Use libnl 3.2 libraries (if this is selected, CONFIG_LIBNL20 is ignored)
set(CONFIG_LIBNL32 ON)

# Driver interface for no driver (e.g., RADIUS server only)
#set(CONFIG_DRIVER_NONE ON)

# WPA2/IEEE 802.11i RSN pre-authentication
set(CONFIG_RSN_PREAUTH ON)

# Support Operating Channel Validation
#set(CONFIG_OCV ON)

# Integrated EAP server
set(CONFIG_EAP ON)

# EAP Re-authentication Protocol (ERP) in integrated EAP server
set(CONFIG_ERP ON)

# EAP-MD5 for the integrated EAP server
set(CONFIG_EAP_MD5 ON)

# EAP-TLS for the integrated EAP server
set(CONFIG_EAP_TLS ON)

# EAP-MSCHAPv2 for the integrated EAP server
set(CONFIG_EAP_MSCHAPV2 ON)

# EAP-PEAP for the integrated EAP server
set(CONFIG_EAP_PEAP ON)

# EAP-GTC for the integrated EAP server
set(CONFIG_EAP_GTC ON)

# EAP-TTLS for the integrated EAP server
set(CONFIG_EAP_TTLS ON)

# EAP-SIM for the integrated EAP server
#set(CONFIG_EAP_SIM ON)

# EAP-AKA for the integrated EAP server
#set(CONFIG_EAP_AKA ON)

# EAP-AKA' for the integrated EAP server
# This requires CONFIG_EAP_AKA to be enabled, too.
#set(CONFIG_EAP_AKA_PRIME ON)

# EAP-PAX for the integrated EAP server
#set(CONFIG_EAP_PAX ON)

# EAP-PSK for the integrated EAP server (this is _not_ needed for WPA-PSK)
#set(CONFIG_EAP_PSK ON)

# EAP-pwd for the integrated EAP server (secure authentication with a password)
#set(CONFIG_EAP_PWD ON)

# EAP-SAKE for the integrated EAP server
#set(CONFIG_EAP_SAKE ON)

# EAP-GPSK for the integrated EAP server
#set(CONFIG_EAP_GPSK ON)
# Include support for optional SHA256 cipher suite in EAP-GPSK
#set(CONFIG_EAP_GPSK_SHA256 ON)

# EAP-FAST for the integrated EAP server
#set(CONFIG_EAP_FAST ON)

# EAP-TEAP for the integrated EAP server
# Note: The current EAP-TEAP implementation is experimental and should not be
# enabled for production use. The IETF RFC 7170 that defines EAP-TEAP has number
# of conflicting statements and missing details and the implementation has
# vendor specific workarounds for those and as such, may not interoperate with
# any other implementation. This should not be used for anything else than
# experimentation and interoperability testing until those issues has been
# resolved.
#set(CONFIG_EAP_TEAP ON)

# Wi-Fi Protected Setup (WPS)
set(CONFIG_WPS ON)
# Enable UPnP support for external WPS Registrars
set(CONFIG_WPS_UPNP ON)
# Enable WPS support with NFC config method
set(CONFIG_WPS_NFC ON)

# EAP-IKEv2
#set(CONFIG_EAP_IKEV2 ON)

# Trusted Network Connect (EAP-TNC)
#set(CONFIG_EAP_TNC ON)

# EAP-EKE for the integrated EAP server
#set(CONFIG_EAP_EKE ON)

# PKCS#12 (PFX) support (used to read private key and certificate file from
# a file that usually has extension .p12 or .pfx)
set(CONFIG_PKCS12 ON)

# RADIUS authentication server. This provides access to the integrated EAP
# server from external hosts using RADIUS.
set(CONFIG_RADIUS_SERVER ON)

# Build IPv6 support for RADIUS operations
set(CONFIG_IPV6 ON)

# IEEE Std 802.11r-2008 (Fast BSS Transition)
set(CONFIG_IEEE80211R ON)
set(CONFIG_IEEE80211R_AR ON)

# Use the hostapd's IEEE 802.11 authentication (ACL), but without
# the IEEE 802.11 Management capability (e.g., FreeBSD/net80211)
#set(CONFIG_DRIVER_RADIUS_ACL ON)

# Wireless Network Management (IEEE Std 802.11v-2011)
# Note: This is experimental and not complete implementation.
set(CONFIG_WNM ON)

# IEEE 802.11ac (Very High Throughput) support
set(CONFIG_IEEE80211AC ON)

# IEEE 802.11ax HE support
set(CONFIG_IEEE80211AX ON)

# IEEE 802.11be EHT support
# CONFIG_IEEE80211AX is mandatory for setting CONFIG_IEEE80211BE.
# Note: This is experimental and work in progress. The definitions are still
# subject to change and this should not be expected to interoperate with the
# final IEEE 802.11be version.
set(CONFIG_IEEE80211BE ON)

# Simultaneous Authentication of Equals (SAE), WPA3-Personal
set(CONFIG_SAE ON)

# SAE Public Key, WPA3-Personal
#set(CONFIG_SAE_PK ON)

# Remove debugging code that is printing out debug messages to stdout.
# This can be used to reduce the size of the hostapd considerably if debugging
# code is not needed.
#set(CONFIG_NO_STDOUT_DEBUG ON)

# Add support for writing debug log to a file: -f /tmp/hostapd.log
# Disabled by default.
set(CONFIG_DEBUG_FILE ON)

# Send debug messages to syslog instead of stdout
#set(CONFIG_DEBUG_SYSLOG ON)

# Add support for sending all debug messages (regardless of debug verbosity)
# to the Linux kernel tracing facility. This helps debug the entire stack by
# making it easy to record everything happening from the driver up into the
# same file, e.g., using trace-cmd.
#set(CONFIG_DEBUG_LINUX_TRACING ON)

# Remove support for RADIUS accounting
#set(CONFIG_NO_ACCOUNTING ON)

# Remove support for RADIUS
#set(CONFIG_NO_RADIUS ON)

# Remove support for VLANs
#set(CONFIG_NO_VLAN ON)

# Enable support for fully dynamic VLANs. This enables hostapd to
# automatically create bridge and VLAN interfaces if necessary.
#set(CONFIG_FULL_DYNAMIC_VLAN ON)

# Use netlink-based kernel API for VLAN operations instead of ioctl()
# Note: This requires libnl 3.1 or newer.
#set(CONFIG_VLAN_NETLINK ON)

# Remove support for dumping internal state through control interface commands
# This can be used to reduce binary size at the cost of disabling a debugging
# option.
#set(CONFIG_NO_DUMP_STATE ON)

# Enable tracing code for developer debugging
# This tracks use of memory allocations and other registrations and reports
# incorrect use with a backtrace of call (or allocation) location.
#set(CONFIG_WPA_TRACE ON)

# Use libbfd to get more details for developer debugging
# This enables use of libbfd to get more detailed symbols for the backtraces
# generated by CONFIG_WPA_TRACE=y.
#set(CONFIG_WPA_TRACE_BFD ON)

# hostapd depends on strong random number generation being available from the
# operating system. os_get_random() function is used to fetch random data when
# needed, e.g., for key generation. On Linux and BSD systems, this works by
# reading /dev/urandom. It should be noted that the OS entropy pool needs to be
# properly initialized before hostapd is started. This is important especially
# on embedded devices that do not have a hardware random number generator and
# may by default start up with minimal entropy available for random number
# generation.
#
# As a safety net, hostapd is by default trying to internally collect
# additional entropy for generating random data to mix in with the data
# fetched from the OS. This by itself is not considered to be very strong, but
# it may help in cases where the system pool is not initialized properly.
# However, it is very strongly recommended that the system pool is initialized
# with enough entropy either by using hardware assisted random number
# generator or by storing state over device reboots.
#
# hostapd can be configured to maintain its own entropy store over restarts to
# enhance random number generation. This is not perfect, but it is much more
# secure than using the same sequence of random numbers after every reboot.
# This can be enabled with -e<entropy file> command line option. The specified
# file needs to be readable and writable by hostapd.
#
# If the os_get_random() is known to provide strong random data (e.g., on
# Linux/BSD, the board in question is known to have reliable source of random
# data from /dev/urandom), the internal hostapd random pool can be disabled.
# This will save some in binary size and CPU use. However, this should only be
# considered for builds that are known to be used on devices that meet the
# requirements described above.
#set(CONFIG_NO_RANDOM_POOL ON)

# Should we attempt to use the getrandom(2) call that provides more reliable
# yet secure randomness source than /dev/random on Linux 3.17 and newer.
# Requires glibc 2.25 to build, falls back to /dev/random if unavailable.
#set(CONFIG_GETRANDOM ON)

# Should we use poll instead of select? Select is used by default.
#set(CONFIG_ELOOP_POLL ON)

# Should we use epoll instead of select? Select is used by default.
#set(CONFIG_ELOOP_EPOLL ON)

# Should we use kqueue instead of select? Select is used by default.
#set(CONFIG_ELOOP_KQUEUE ON)

# TLS-based EAP methods require at least TLS v1.0. Newer version of TLS (v1.1)
# can be enabled to get a stronger construction of messages when block ciphers
# are used.
#set(CONFIG_TLSV11 ON)

# TLS-based EAP methods require at least TLS v1.0. Newer version of TLS (v1.2)
# can be enabled to enable use of stronger crypto algorithms.
#set(CONFIG_TLSV12 ON)

# At the cost of about 4 kB of additional binary size, the internal LibTomMath
# can be configured to include faster routines for exptmod, sqr, and div to
# speed up DH and RSA calculation considerably
#set(CONFIG_INTERNAL_LIBTOMMATH_FAST ON)

# Interworking (IEEE 802.11u)
# This can be used to enable functionality to improve interworking with
# external networks.
#set(CONFIG_INTERWORKING ON)

# Hotspot 2.0
set(CONFIG_HS20 ON)

# Enable SQLite database support in hlr_auc_gw, EAP-SIM DB, and eap_user_file
#set(CONFIG_SQLITE ON)

# Enable Fast Session Transfer (FST)
set(CONFIG_FST ON)

# Enable CLI commands for FST testing
set(CONFIG_FST_TEST ON)

# Testing options
# This can be used to enable some testing options (see also the example
# configuration file) that are really useful only for testing clients that
# connect to this hostapd. These options allow, for example, to drop a
# certain percentage of probe requests or auth/(re)assoc frames.
#
#set(CONFIG_TESTING_OPTIONS ON)

# Automatic Channel Selection
# This will allow hostapd to pick the channel automatically when channel is set
# to "acs_survey" or "0". Eventually, other ACS algorithms can be added in
# similar way.
#
# Automatic selection is currently only done through initialization, later on
# we hope to do background checks to keep us moving to more ideal channels as
# time goes by. ACS is currently only supported through the nl80211 driver and
# your driver must have survey dump capability that is filled by the driver
# during scanning.
#
# You can customize the ACS survey algorithm with the hostapd.conf variable
# acs_num_scans.
#
# Supported ACS drivers:
# * ath9k
# * ath5k
# * ath10k
#
# For more details refer to:
# https://wireless.wiki.kernel.org/en/users/documentation/acs
#
set(CONFIG_ACS ON)

# Multiband Operation support
# These extensions facilitate efficient use of multiple frequency bands
# available to the AP and the devices that may associate with it.
#set(CONFIG_MBO ON)

# Client Taxonomy
# Has the AP retain the Probe Request and (Re)Association Request frames from
# a client, from which a signature can be produced which can identify the model
# of client device like "Nexus 6P" or "iPhone 5s".
set(CONFIG_TAXONOMY ON)

# Fast Initial Link Setup (FILS) (IEEE 802.11ai)
#set(CONFIG_FILS ON)
# FILS shared key authentication with PFS
#set(CONFIG_FILS_SK_PFS ON)

# Include internal line edit mode in hostapd_cli. This can be used to provide
# limited command line editing and history support.
set(CONFIG_WPA_CLI_EDIT ON)

# Opportunistic Wireless Encryption (OWE)
# Experimental implementation of draft-harkins-owe-07.txt
#set(CONFIG_OWE ON)

# Airtime policy support
#set(CONFIG_AIRTIME_POLICY ON)

# Wired equivalent privacy (WEP)
# WEP is an obsolete cryptographic data confidentiality algorithm that is not
# considered secure. It should not be used for anything anymore. The
# functionality needed to use WEP is available in the current hostapd
# release under this optional build parameter. This functionality is subject to
# be completely removed in a future release.
set(CONFIG_WEP ON)

# Remove all TKIP functionality
# TKIP is an old cryptographic data confidentiality algorithm that is not
# considered secure. It should not be used anymore. For now, the default hostapd
# build includes this to allow mixed mode WPA+WPA2 networks to be enabled, but
# that functionality is subject to be removed in the future.
#set(CONFIG_NO_TKIP ON)

# Pre-Association Security Negotiation (PASN)
# Experimental implementation based on IEEE P802.11z/D2.6 and the protocol
# design is still subject to change. As such, this should not yet be enabled in
# production use.
# This requires CONFIG_IEEE80211W=y to be enabled, too.
set(CONFIG_PASN ON)

# Device Provisioning Protocol (DPP) (also known as Wi-Fi Easy Connect)
set(CONFIG_DPP ON)
# DPP version 2 support
set(CONFIG_DPP2 ON)
# DPP version 3 support (experimental and still changing; do not enable for
# production use)
#set(CONFIG_DPP3 ON)
