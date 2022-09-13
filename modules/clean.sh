#!/bin/bash -ex

THIS_DIR="$(cd "$(dirname "${0}")" && pwd -P)"

(
  # przejscie do katalogu MODULES
  cd "${THIS_DIR}"

  # usun wszystkie pliki *.a i *.o
  find -name "*.[ao]" | xargs rm -fr
)
