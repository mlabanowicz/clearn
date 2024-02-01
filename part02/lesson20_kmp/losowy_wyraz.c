
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LITERA_MIN 'A'
#define LITERA_MAX 'Z'

#define DLUGOSC_WYRAZU 10

#define LITERA_CNT (LITERA_MAX - LITERA_MIN + 1)

int main(void)
{
  char wyraz [DLUGOSC_WYRAZU + 1];

  int i = sizeof(wyraz); /* wypelniac tablice bedziemy od konca */

  srand(time(NULL)); /* inicjalizujemy generator liczb losowych */

  wyraz[--i] = '\0'; /* ostatni znak ma byc koncem napisu, czyli '\0' */

  while (i)
  {
    int r = rand(); /* losujemy liczbe od 0 do RAND_MAX */

    /* r ma wartosc z przedzialu: <0, RAND_MAX> */

    /* zmniejszamy zakres losowanej wartosci do liczby liter */
    r %= LITERA_CNT;

    /* r ma wartosc z przedzialu: <0, LITERA_CNT) */

    /* podnosimy przedzial tak, aby r bylo w zakresie liter */
    r += LITERA_MIN;

    /* r ma wartosc z przedzialu: <LITERA_MIN, LITERA_MIN + LITERA_CNT) */
    /* czyli: */
    /* r ma wartosc z przedzialu: <LITERA_MIN, LITERA_MAX> */

    /* wpisujemy wylosowana litere do tablicy wyrazu */
    wyraz[--i] = r;
  }

  puts(wyraz);

  return EXIT_SUCCESS;
}
