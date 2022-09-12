#!/bin/bash -ex

# kompilacja
gcc -DNDEBUG -Wbad-function-cast -Wmissing-declarations -Wmissing-parameter-type -Wmissing-prototypes -Wnested-externs \
  -Wstrict-prototypes -Wdeclaration-after-statement -Wpointer-sign -ansi -pedantic \
  -Wall -Wextra -Werror -Os sortint.c -o sortint.exe

# generacja pliku testowego
int_bits=32
echo | awk '{
    srand(1);
    for(i=0; i<100000; ++i){
      printf("%d\n", int(rand()*'$(echo $(( 1 << int_bits )))') - '$(( 1 << (int_bits-1) ))');} \
    }' \
  > input.txt

# wygenerowanie poprawnego outputu
sort -n < input.txt > correct.txt

# wygenerowanie outputu programu
./sortint.exe < input.txt > output.txt

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

