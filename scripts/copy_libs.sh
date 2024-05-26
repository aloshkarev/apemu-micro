#!/bin/sh
FILE=$1
DESTDIR=$2
if [ -z $FILE -o -z $DESTDIR ]; then
	echo "Usage: copy_libs.sh <bin> <destdir>"
	exit 1
fi
if [ ! -e "$FILE" ]; then
	echo "$FILE not found!\n"
	exit 1;
fi
if [ ! -e "$DESTDIR" ]; then
	echo "$DESTDIR not exists!\n"
	exit 1;
fi
ldd "$FILE" | grep "=> /" | awk '{print $3}' | xargs -I '{}' cp -p -u '{}' "$DESTDIR"
cp -p -u /lib64/ld-linux-x86-64.so.2 "$DESTDIR/ld-linux-x86-64.so.2"