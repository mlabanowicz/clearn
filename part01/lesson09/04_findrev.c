/*

Program, ktory sprawdza, czy w strumieniu wejsciowym przynajmniej
raz wystepuje podana fraza (ktora sklada sie z roznych liter), ale pisana od konca.

Przyklad:
Wywolanie:
  ./04_findrev.exe am

Wejscie:
  Ala musi kupic masc.
Wyjscie:
  Tak

Wejscie:
  Ala lubi kredki.
Wyjscie:
  Nie

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#ifdef __cplusplus
extern "C" {
#endif

int main(int argc, char * argv []) {

  char * wyraz;

  int dlugosc_wyrazu = 0;

  int c;
  int i;

  if (argc != 2) {
    fprintf(stderr, "Blad, do programu nalezy podac jeden argument !\n");
    exit(EXIT_FAILURE);
  }

  wyraz = argv[1];

  /* Obliczanie dlugosci wyrazu (mozna uzyc strlen), */
  /* to jest do zobrazowania jak wyznaczyc dlugosc napisu */
  while (wyraz[dlugosc_wyrazu]) {

    /* Wyswietl LOG przydatny do diagnostyki: */
    fprintf(stderr, "LOG: wyraz[%d] = '%c'\n", dlugosc_wyrazu, wyraz[dlugosc_wyrazu]);

    ++dlugosc_wyrazu;
  }

  if (dlugosc_wyrazu == 0) {
    fprintf(stderr, "Blad, wyraz musi skladac sie z przynjamniej jednej litery !\n");
  }

  i = dlugosc_wyrazu;

  while ((c = getchar()) != EOF) { /* pobierz znak, jezeli EOF to zakoncz petle. */

    /* Wyswietl LOG przydatny do diagnostyki: */
    fprintf(stderr, "LOG: pobrano znak: (%d = '%c') [i=%d, dlugosc_wyrazu=%d]\n", c, isprint(c) ? c : '.', i, dlugosc_wyrazu);

    /* bedziemy sprawdzac kolejny znak liczac od konca */
    --i;

    if (c == wyraz[i]) {

      /* Ok, znak sie zgadza */

      /* Wyswietl LOG przydatny do diagnostyki: */
      fprintf(stderr, "LOG: zgadza sie pobrany znak '%c' ze znakiem w wyrazie na pozycji %d\n", c, i);

      if (i == 0) {
        /* Koniec -> wyraz zostal znaleziony, wiemy, ze 'i' jest 0 */
        /* Nie potrzebujemy pobierac wiecej danych, wynik jest juz znany. */
        /* Wylazimy z petli. */
        break;
      }

    } else {

      /* nie pasuje, szukamy od nowa: */

      /* Wyswietl LOG przydatny do diagnostyki: */
      if (i + 1 != dlugosc_wyrazu) {
        fprintf(stderr, "LOG: nie zgadza sie pobrany znak '%c' ze znakiem w wyrazie na pozycji %d -> resetujemy szukanie\n", c, i);
      }

      i = dlugosc_wyrazu;

    }
  }

  puts(i ? "Nie" : "Tak");

  return EXIT_SUCCESS;
}
#ifdef __cplusplus
}
#endif
