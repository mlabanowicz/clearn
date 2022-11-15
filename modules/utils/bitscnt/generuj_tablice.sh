#!/bin/bash -ex

. ../../opts.sh

gcc ${opts} ${opts_rel} generuj_tablice.c -o generuj_tablice.exe

./generuj_tablice.exe > tablica.txt

