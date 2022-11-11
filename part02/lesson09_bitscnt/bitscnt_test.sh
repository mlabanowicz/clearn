#!/bin/bash -ex

MODULES=../../modules

${MODULES}/build.sh utils

. ${MODULES}/opts.sh

gcc ${opts} ${opts_rel} bitscnt_test_shift.c -I${MODULES} ${MODULES}/utils.a -o bitscnt_test_shift.exe
gcc ${opts} ${opts_rel} bitscnt_test_array.c -I${MODULES} ${MODULES}/utils.a -o bitscnt_test_array.exe


openssl rand $(( 512*1024*1024 )) > input.data


time ./bitscnt_test_shift.exe < input.data

time ./bitscnt_test_array.exe < input.data


echo SUCCESS