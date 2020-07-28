#include <stdio.h>
#include <stdlib.h>
#ifdef __cplusplus
extern "C"
{
#endif
  struct zawodnik
  {
    char imie[20 + 1];
    int czasZawodnika;
  };
  int main (void)
  {

    struct zawodnik pierwszemiejsce;
    struct zawodnik drugiemiejsce;
    struct zawodnik trzeciemiejsce;
    int x = 0, iloscOsob = 1;
    struct zawodnik tablica[100];
    while (1 == 1)
      {
	int scanf_result =
	  scanf ("%s %d", tablica[x].imie, &tablica[x].czasZawodnika);
	if (scanf_result != 2 && scanf_result != EOF)
	  {
	    fprintf (stderr, "Niepoprane dane wejsciowe\n");
	    return EXIT_FAILURE;
	  }
	if (scanf_result == EOF)
	  break;
	if (iloscOsob != 1)
	  {
	    if (tablica[x].czasZawodnika == pierwszemiejsce.czasZawodnika || tablica[x].czasZawodnika == drugiemiejsce.czasZawodnika || tablica[x].czasZawodnika == trzeciemiejsce.czasZawodnika)
	      {
		fprintf (stderr, "Czas zawodnikow nie moze byc rowny\n");
		return EXIT_FAILURE;
	      }
	    if (tablica[x].czasZawodnika < pierwszemiejsce.czasZawodnika && tablica[x].czasZawodnika < drugiemiejsce.czasZawodnika && tablica[x].czasZawodnika < trzeciemiejsce.czasZawodnika)
	      pierwszemiejsce = tablica[x];
	    if (tablica[x].czasZawodnika < drugiemiejsce.czasZawodnika && tablica[x].czasZawodnika > pierwszemiejsce.czasZawodnika && tablica[x].czasZawodnika < trzeciemiejsce.czasZawodnika)
	      drugiemiejsce = tablica[x];
	    if (tablica[x].czasZawodnika > pierwszemiejsce.czasZawodnika && tablica[x].czasZawodnika > drugiemiejsce.czasZawodnika && tablica[x].czasZawodnika < trzeciemiejsce.czasZawodnika)
	      trzeciemiejsce = tablica[x];
	  }
	else
	  {
	    trzeciemiejsce = tablica[x];
	    drugiemiejsce = tablica[x];
	    pierwszemiejsce = tablica[x];
	  }
	x++;
	iloscOsob++;
      }
    if (iloscOsob < 3)
      {
	fprintf (stderr, "Za malo osob\n");
	return EXIT_FAILURE;
      }
    printf ("1. %s\n", pierwszemiejsce.imie);
    printf ("2. %s\n", drugiemiejsce.imie);
    printf ("3. %s\n", trzeciemiejsce.imie);
  }
#ifdef __cplusplus
}
#endif
