#!/bin/bash -ex

# kompilacja
gcc -DNDEBUG -Wbad-function-cast -Wmissing-declarations -Wmissing-parameter-type -Wmissing-prototypes -Wnested-externs \
  -Wstrict-prototypes -Wdeclaration-after-statement -Wpointer-sign -ansi -pedantic \
  -Wall -Wextra -Werror -Os dos2unix.c -o dos2unix.exe

# generacja pliku testowego
echo | awk '{srand(1);for(i=0; i<10; ++i){r=int(rand() * 3); printf("%02x", r==0?0xd:r==1?0xa:0x41);}}' | xxd -ps -r > input.txt

# wygenerowanie poprawnego outputu
dos2unix -f < input.txt > correct.txt

# wygenerowanie outputu programu
./dos2unix.exe

# porownanie wynikow
if cmp correct.txt output.txt; then
  echo "OK"
else
  echo "Failed!"
  cat input.txt
  xxd < input.txt
  cat correct.txt
  cat output.txt
  diff <(xxd < correct.txt) <(xxd < output.txt)
  false # (zwraca do systemu EXIT_FAILURE)
fi

