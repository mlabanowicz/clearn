#!/bin/bash -ex

# sciezka do katalogu modules
MODULES=../../modules

# zbudowanie biblioteki utils.a
${MODULES}/build.sh utils

# zaladowanie opcji kompilacji
. ${MODULES}/opts.sh

# kompilacja programu z wykorzystaniem biblioteki
gcc ${ops} ${opts_rel} buildinfo_test.c -I${MODULES} ${MODULES}/utils.a -o buildinfo_test.exe

# uruchomienie/test programu
./buildinfo_test.exe
