#!/bin/sh
x=$(echo -n ":${1}" | sed "s,^:,," | xxd -ps | awk '{printf("%s", $0);}')
xxd -ps | awk '{printf("%s", $0);}' | sed "s,${x},\n,g" | wc -l
