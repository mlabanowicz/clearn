#!/bin/bash -ex

# sciezka do katalogu modules
MODULES=../../modules

# zbudowanie biblioteki utils.a
${MODULES}/build.sh utils

# zaladowanie opcji kompilacji
. ${MODULES}/opts.sh

# kompilacja programu z wykorzystaniem biblioteki
gcc ${opts} ${opts_rel} dumpdata_test.c -I${MODULES} ${MODULES}/utils.a -o dumpdata_test.exe

# uruchomienie/test programu (jako wejscie stdin podano ten skrypt)
./dumpdata_test.exe < "${0}"
