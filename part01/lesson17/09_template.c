
#include <stdio.h>  /* size_t, fread, fwrite, fprintf */
#include <stdlib.h> /* malloc, free, exit, EXIT_SUCCESS, EXIT_FAILURE */
#include <string.h> /* memset */

#ifdef __cplusplus
extern "C" {
#endif

int main(void) {

  /* 1) Zdefiniuje tablice w pamieci BSS o rozmiarze 1MB. */
  static char tab [1000000];

  /* 2) Wczyta zawartosc ze standardowego wejscia do tej tablicy. */
  /*    Tyle danych ile sie uda wczytac, ale nie wiecej niz rozmiar tej tablicy. */
  size_t len = fread(tab, 1, sizeof(tab), stdin);

  /* 3) Zaalokouje w pamieci HEAP tablice, rozmiar ma byc dokladnie taki, */
  /*    ile danych udalo sie wczytac do tablicy BSS podczas punktu 2. */
  char * buffer = (char *)malloc(len);

  /* zmienne pomocnicze */
  char * src = tab + len; /* wskazuje na koniec wczytanych danych */
  char * dst = buffer;    /* wskazuje na poczatek bufora */
  int i = len;
  if (len && !buffer) {
    fprintf(stderr, "Failed, Nie moge zaalokowac %d bajtow !\n", i);
    exit(EXIT_FAILURE);
  }

  /* 4) Skopiuje do tablicy HEAP wszystkie te dane z tablicy BSS, ale w odwrotnej kolejnosci. */
  while (i--) {
    /* najpierw zmniejsz src o 1 i dopiero odczytaj bajt z tego adresu */
    /* zapisz ten bajto do dst i po tym zwieksz dst o 1 */
    *dst++ = *--src;
  }

  /* 5) Wypelni cala tablice BSS wartoscia '1'. */
  memset(tab, '1', sizeof(tab));

  /* 6) Wypisze na stanardowe wyjscie cala tablice HEAP. */
  fwrite(buffer, 1, len, stdout);

  /* 7) Dealokuje pamiec HEAP (zwolni pamiec) */
  free(buffer);

  /* 8) Koniec programu */
  return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif
