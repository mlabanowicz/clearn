#!/bin/bash -ex

# sciezka do katalogu modules
MODULES=../../modules

# zbudowanie biblioteki utils.a
${MODULES}/build.sh utils

# zaladowanie opcji kompilacji
. ${MODULES}/opts.sh

# kompilacja programu z wykorzystaniem biblioteki
gcc ${opts} ${opts_rel} loadfile_test.c -I${MODULES} ${MODULES}/utils.a -o loadfile_test.exe

# uruchomienie/test programu
./loadfile_test.exe