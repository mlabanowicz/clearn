#!/bin/bash -ex

gcc generator_danych.c -o ./generator_danych.exe
gcc slow.c -o ./slow.exe
gcc kmp.c -o ./kmp.exe

while true; do
  ./generator_danych.exe > data.in
  ./slow.exe < data.in > data.slow.out
  ./kmp.exe  < data.in > data.kmp.out
  diff data.slow.out data.kmp.out
done
