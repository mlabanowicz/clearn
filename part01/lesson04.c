#include <stdlib.h>
#include <stdio.h>

int
main (void)
{
  int x = 0, i = 1, z = 0, y = 0, w = 0;
  int TAB[1000 + 1];
  int scanf_result = scanf ("%d", &x);
  if (scanf_result != 1)
    {
      fprintf (stderr, "blad - podane dane nie sa liczba\n");
      return EXIT_FAILURE;
    }
  if (x > 1000 || x < 0)
    {
      fprintf (stderr, "blad - liczba okreslajaca za duza/za mala");
      return EXIT_FAILURE;
    }
  while (i <= x)		/* w tej petli program wczytuje dane liczby do tablicy */
    {
      int scanf_result = scanf ("%d", &z);
      if (scanf_result == EOF)
	{
	  fprintf (stderr, "blad - za malo liczb\n");
	  return EXIT_FAILURE;
	}
      if (scanf_result != 1)
	{
	  fprintf (stderr, "blad - podane dane nie sa liczba\n");
	  return EXIT_FAILURE;
	}
      TAB[i] = z;
      w += z;
      i++;
    }
  w = w / x;
  i = 1;
  if (scanf ("%d", &z) != EOF)	/*sprawdzamy cz po wykonaniu petli wczytujacej liczby zostala jeszcze jakas */
    {
      fprintf (stderr, "blad-za duzo liczb");
      return EXIT_FAILURE;
    }
  while (i <= x)
    {
      if (TAB[i] <= w)
	{
	  printf ("%d\n", TAB[i]);
	}
      i++;
    }
  return EXIT_SUCCESS;
}

