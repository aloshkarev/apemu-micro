#!/bin/sh

here="${0%/*}"  # or you can use `dirname "$0"`

LD_LIBRARY_PATH="$here"/../lib:"$LD_LIBRARY_PATH"
LD_LOADER=$here"/../lib/ld-linux.so"
export LD_LIBRARY_PATH
exec "$LD_LOADER"  --library-path ../lib "$0".bin "$@"