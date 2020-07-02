#include <stdlib.h>
#include <stdio.h>

int
main (void)
{
  int x = 0, i = 1, z = 0, y = 0;
  int scanf_result = scanf ("%d", &x);
  if (scanf_result != 1)
    {
      fprintf (stderr, "blad - podane dane nie sa liczba\n");
      return EXIT_FAILURE;
    }
  if (x >= 1000 || x <= 0)
    {
      fprintf (stderr, "blad - liczba okreslajaca za duza/za mala");
      return EXIT_FAILURE;
    }
  int TAB[x];
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
      i++;
    }
  y = i;			/*przypisujemy wartosc  i->y aby moc jednoczesnie zrobic tyle samo powtorzen w petli jak w petli poprzednej i
				   zeby moc wypisywac z tablicy odpowiednia liczbe */
  i = 1;
  if (scanf ("%d", &z) != EOF)	/*sprawdzamy cz po wykonaniu petli wczytujacej liczby zostala jeszcze jakas */
    {
      fprintf (stderr, "blad-za duzo liczb");
      return EXIT_FAILURE;
    }
  while (i <= x)
    {
      printf ("%d\n", TAB[y - 1]);
      y--;
      i++;
    }
  return EXIT_SUCCESS;
}