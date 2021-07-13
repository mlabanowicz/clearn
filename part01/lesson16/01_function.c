
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Deklaracja funkcji               */
/*                                  */
/*   +--- zwracany typ              */
/*  /                               */
/* /         +-------+--- parametry */
/*          /       /               */
int add(int a, int b);

/* Definicja funkcji */
int add(int a, int b)
{
  int result = a + b; /* deklaracja zmiennej result, jest ona trzymana na stosie,
                         po wyjsciu z tej funkcji ta zmienna nie bedzie juz dostepna */

  return result; /* wynik dzialania funkcji to wartosc odczytana ze zmiennej result */
}

int main(void)
{
  /* Wywolanie funkcji z podanymi parametrami */
  int suma = add(5, 9);

  printf("%d\n", suma);

  return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif
