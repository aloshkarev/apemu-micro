#!/bin/bash

# Generate a wpa_supplicant.conf from the template.
# $1: the template file name
if [ -n "$WIFI_DRIVER_SOCKET_IFACE" ]
then
  sed -e 's/#.*$//' -e 's/[ \t]*$//' -e '/^$/d' < $1 | sed -e "s/wlan0/$WIFI_DRIVER_SOCKET_IFACE/"
else
  sed -e 's/#.*$//' -e 's/[ \t]*$//' -e '/^$/d' < $1
fi
