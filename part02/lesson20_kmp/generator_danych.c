
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LITERA_MIN 'A'
#define LITERA_MAX 'Z'

static int randRange(int from, int to)
{
  return from + (rand() % (to - from + 1));
}

int main(void)
{
  static char ciag  [1000000 + 1];
  static char klucz [sizeof(ciag)];

  int DLUGOSC_CIAGU;
  int DLUGOSC_KLUCZA;
  int LITERA_CNT;

  int i;

  unsigned srand_value = (unsigned)clock();

  srand(srand_value);

  DLUGOSC_CIAGU  = randRange(1, sizeof(ciag) - 1);
  DLUGOSC_KLUCZA = randRange(1, DLUGOSC_CIAGU);

  LITERA_CNT = randRange(1, LITERA_MAX - LITERA_MIN + 1);

  i = DLUGOSC_KLUCZA + 1;

  klucz[--i] = '\0';

  while (i)
  {
    int r = rand();
    r %= LITERA_CNT;
    r += LITERA_MIN;
    klucz[--i] = r;
  }

  puts(klucz);

  i = DLUGOSC_CIAGU + 1;

  ciag[--i] = '\0';

  while (i)
  {
    int r = rand();
    r %= LITERA_CNT;
    r += LITERA_MIN;
    ciag[--i] = r;
  }

  puts(ciag);

  return EXIT_SUCCESS;
}
