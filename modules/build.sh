#!/bin/bash -ex

THIS_DIR="$(cd "$(dirname "${0}")" && pwd -P)"

if [ "${#}" -eq 0 ]; then

  # Wygenerowanie wszystkich modulow
  (cd "${THIS_DIR}" && find . -mindepth 1 -maxdepth 1 -type d) \
  | sed "s,^[.]/,," \
  | while IFS='' read -r module; do
      "${0}" ${module}
    done

else

  # Wygeneorwanie konkretnego modulu

  (
  # przejscie do katalogu MODULES/<module_name>
  cd "${THIS_DIR}/${1}"

  # usuniecie poprzednioch plikow
  rm -fr *.[o] ../${1}.a

  # zaladowanie opcji wymaganych do kompilacji
  . ../opts.sh

  # kompilacja wszystkich plikow *.c do plikow obiektowych *.o
  gcc ${opts} ${opts_rel} -I.. -c *.c

  # wygenerowanie biblioteki zawierajacej wszystkie pliki *.o
  ar cr ../${1}.a *.o
  )

fi
