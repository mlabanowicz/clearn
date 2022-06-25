#!/bin/bash -ex

#
# NOTE:
#   a) potrzebny jest program openssl, przewaznie ten pakiet jest juz zainstalowany
#   b) jezeli chcemy wykonac operacje arytmetyczna w bashu,
#      mozna wykorzystac funkje $(( <operacja arytmetyczna> ))
#      #> echo "5*78" = $(( 5 * 78 ))
#   c) plik '/dev/null' w linuxie jest takim urzadzeniem wyjsciowym, do ktorego
#      mozna przekierowac wyjscie programu, dane tam nie sa nigdzie zapisywane,
#      to taki 'smietnik', do ktorego mozna wszystko wrzucic, te dane gina bezpowrotnie.
#

echo "kompilacja"
gcc cat.c -o cat.exe
gcc cat_buffered.c -o cat_buffered.exe

echo "kompilacja z roznymi rozmiarami bufora:"
for buffer_size in 1 8 16 32 128 512; do
  gcc -DBUFFER_SIZE=${buffer_size} cat_buffered.c -o cat_buffered_${buffer_size}.exe
done

echo "wygenerowanie testowego pliku o rozmiarze 512MB:"
openssl rand $(( 512*1024*1024 )) > input.data

# dla kazdego pliku o podanym wzorcu:
for f in $(ls -1 cat*.exe); do

  echo "[$f] sprawdzenie poprawnosci dzialania programu:"

  # skasowanie pliku wyjsciowego
  rm -fr output.data

  # uruchomienie programu
  ./${f} < input.data > output.data

  # sprawdzenie wyniku - jezeli pliki beda rozne,
  # wtedy program cmp zwroci blad (return EXIT_FAILURE) - i skrypt zakonczy
  # dzialanie z bledem (takze zwroci EXIT_FAILURE)
  cmp input.data output.data

  echo "[$f] test z pomiarem czasu (czas dzialania programu jest w linijce user):"
  time ./${f} < input.data > /dev/null

done

echo SUCCESS

