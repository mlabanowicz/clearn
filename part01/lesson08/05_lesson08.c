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
    int iloscOsob = 1;
    struct zawodnik osoba;
    pierwszemiejsce.czasZawodnika = drugiemiejsce.czasZawodnika = trzeciemiejsce.czasZawodnika = osoba.czasZawodnika = 0;
    while (1 == 1)
      {
	int scanf_result = scanf ("%s %d", osoba.imie, &osoba.czasZawodnika);
	if (scanf_result != 2 && scanf_result != EOF)
	  {
	    fprintf (stderr, "Niepoprane dane wejsciowe\n");
	    return EXIT_FAILURE;
	  }
	if (scanf_result == EOF)
	  break;
	if (osoba.czasZawodnika <= 0)
	  {
	    fprintf (stderr, "Czas nie moze byc ujemny\n");
	    return EXIT_FAILURE;
	  }
	if (iloscOsob > 3)
	  {
	    if (osoba.czasZawodnika == pierwszemiejsce.czasZawodnika || osoba.czasZawodnika == drugiemiejsce.czasZawodnika || osoba.czasZawodnika == trzeciemiejsce.czasZawodnika)
	      {
		fprintf (stderr, "Czas zawodnikow nie moze byc rowny\n");
		return EXIT_FAILURE;
	      }
        if(osoba.czasZawodnika < pierwszemiejsce.czasZawodnika){
        trzeciemiejsce = drugiemiejsce;
        drugiemiejsce = pierwszemiejsce;
        pierwszemiejsce = osoba;
        }
        if (osoba.czasZawodnika < drugiemiejsce.czasZawodnika && osoba.czasZawodnika > pierwszemiejsce.czasZawodnika){
        trzeciemiejsce = drugiemiejsce;
        drugiemiejsce = osoba;
        }
        if (osoba.czasZawodnika > drugiemiejsce.czasZawodnika && osoba.czasZawodnika > pierwszemiejsce.czasZawodnika && osoba.czasZawodnika < trzeciemiejsce.czasZawodnika){
        trzeciemiejsce = osoba;
        }
	iloscOsob++;
	  }
	if(iloscOsob == 3){
	    if(osoba.czasZawodnika < pierwszemiejsce.czasZawodnika){
	    trzeciemiejsce = drugiemiejsce;
        drugiemiejsce = pierwszemiejsce;
        pierwszemiejsce = osoba;
        }
        if(osoba.czasZawodnika > pierwszemiejsce.czasZawodnika && osoba.czasZawodnika < drugiemiejsce.czasZawodnika){
        trzeciemiejsce = drugiemiejsce;
        drugiemiejsce = osoba;
        }
        else{
        trzeciemiejsce = osoba;
        }
        iloscOsob++;
	}
    if (iloscOsob == 2){
        if(osoba.czasZawodnika < pierwszemiejsce.czasZawodnika){
        drugiemiejsce = pierwszemiejsce;
        pierwszemiejsce = osoba;
        }
        else
        drugiemiejsce = osoba;
        iloscOsob++;
    }
if (iloscOsob == 1){
pierwszemiejsce = osoba;
iloscOsob++;
	}
      }
    if (iloscOsob < 3)
      {
	fprintf (stderr, "Za malo osob\n");
	return EXIT_FAILURE;
      }
    printf ("1. %s\n", pierwszemiejsce.imie);
    printf ("2. %s\n", drugiemiejsce.imie);
    printf ("3. %s\n", trzeciemiejsce.imie);
    return EXIT_SUCCESS;
  }
#ifdef __cplusplus
}
#endif
