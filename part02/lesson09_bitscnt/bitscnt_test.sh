#!/bin/bash -ex

MODULES=../../modules

${MODULES}/build.sh utils

. ${MODULES}/opts.sh

gcc ${opts} ${opts_rel} bitscnt_test.c -I${MODULES} ${MODULES}/utils.a -o bitscnt_test.exe

./bitscnt_test.exe < "${0}"