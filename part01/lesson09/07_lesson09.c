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
  int d;
  int result = 0;
  if (argc != 2) {
    fprintf(stderr, "Blad, do programu nalezy podac jeden argument !\n");
    exit(EXIT_FAILURE);
  }

  wyraz = argv[1];

  while (wyraz[dlugosc_wyrazu]) {
    fprintf(stderr, "LOG: wyraz[%d] = '%c'\n", dlugosc_wyrazu, wyraz[dlugosc_wyrazu]);

    ++dlugosc_wyrazu;
  }

  if (dlugosc_wyrazu == 0) {
    fprintf(stderr, "Blad, wyraz musi skladac sie z przynjamniej jednej litery !\n");
    exit(EXIT_FAILURE);
  }

  i = -1;
  d = dlugosc_wyrazu;
  while ((c = getchar()) != EOF) { 
    fprintf(stderr, "LOG: pobrano znak: (%d = '%c') [i=%d, dlugosc_wyrazu=%d]\n", c, isprint(c) ? c : '.', i, dlugosc_wyrazu);
    d--;
    ++i;
    if (c == wyraz[i]) {
      fprintf(stderr, "LOG: zgadza sie pobrany znak '%c' ze znakiem w wyrazie na pozycji %d\n", c, i);

      if (i == dlugosc_wyrazu) {
        break;
      }

    } else {
      if (d != dlugosc_wyrazu) {
        fprintf(stderr, "LOG: nie zgadza sie pobrany znak '%c' ze znakiem w wyrazie na pozycji %d -> resetujemy szukanie\n", c, i);
      }

      i = -1;
      d = dlugosc_wyrazu;
    }
      if(d==0){
      result++;
      fprintf(stderr, "LOG: znalezlismy slowo\n");
      i = -1;
      d = dlugosc_wyrazu;
      }
  }
  printf("%d",result);
  return EXIT_SUCCESS;
}
#ifdef __cplusplus
}
#endif
