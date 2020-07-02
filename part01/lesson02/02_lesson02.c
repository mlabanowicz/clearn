#include <stdio.h>
#include <stdlib.h>


int
main (void)
{
  const float EPS = 0.000001;
  int i = 0, x = 0, z = 0;

  while (i == 0)
    {
      int scanf_result = scanf ("%d", &x);
      if (scanf_result == EOF)
	{
	  fprintf (stderr, "blad - brak danych\n");
	  i = 1;
	  continue;
	}


      if (x <= -101 || x >= 101)/*sprawdzenie czy x miesci sie w zakresie odpowiednich liczb*/
	{

	  fprintf (stderr, "blad - liczba(%d) jest za mala/za duza", x);
	  return EXIT_FAILURE;
	}
      if (scanf_result != 1)
	{
	  fprintf (stderr, "blad - podane dane nie sa liczba\n");
	  return EXIT_FAILURE;
	}
	
	
      if (i != 1)/*jezeli x spelnia wszystkie warunki jest on przypisywany do z a pozniej wypisuje z*/
	{
	  z = z + x;
	  printf ("%d\n", z);
	}
    }
  return EXIT_SUCCESS;
}
