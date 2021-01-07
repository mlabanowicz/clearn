#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#ifdef __cplusplus
extern "C" {
#endif
int main(void)
{
  /* tablica o rozmiarze 256 intow (1k), wyzerowana */
  int count [UCHAR_MAX + 1] = {0,};
  /* zmienna pomocnicza */
  int c;
  /* obliczenie wystapien wszystkich znakow z stdin */
  while ((c = getchar()) != EOF) {
    ++count[(unsigned char)c];
  }
  /* wyswietlenie wynikow */
  for (c = 'A'; c <= 'z'; ++c) {
    if (count[c]) {
      printf("%c:%d\n", c, count[c]);
    }
    if (c == 'Z') {
      c = 'a' - 1;
    }
  }
  return EXIT_SUCCESS;
}
#ifdef __cplusplus
}
#endif
