#/bin/sh
sort -g -k 2 | head -n3 | awk '{printf("%d. %s\n", NR, $1);}'
