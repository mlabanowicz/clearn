
#include <stdio.h> /* scanf, printf */
#include <stdlib.h> /* EXIT_SUCCESS, EXIT_FAILURE */
#include <math.h> /* fabs */

int main(void)
{
  const float EPS = 0.000001; /* otoczenie epsilon */

  int i = 0;

  float x = 0.0; /* aby wynik byl dokladnijeszy x bedzie liczba zmmienna przecinkowa */

  while (i == 0) { /* petla bedzie wykonywana az x nie bedzie mial poprawnej wartosci */

    int scanf_result = scanf("%f", &x); /* wczytaj z klawiatory wartosc x */

    if (scanf_result == EOF)
    {
      fprintf(stderr, "blad - brak danych\n");
      return EXIT_FAILURE;
    }

    if (scanf_result != 1)
    {
      fprintf(stderr, "blad - podane dane nie sa liczba\n");
      continue;
    }

    x -= 1.0;

    if (fabs(x) <= EPS) { /* sprawdz czy x jest "niedozwolona wartoscia" */
      fprintf(stderr, "blad - x ma niedozwolona wartosc\n");
    }
    else { /* jezeli nie zakoncz petle */
      i = 1;
    }
  }

  printf("%f\n", 100.0 / x); /* z poprawnym x oblicz i wypisz jego funkcje */

  return EXIT_SUCCESS;
}
