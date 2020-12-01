#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef __cplusplus
extern "C"
{
#endif
  int main (void)
  {
    int *wynik = NULL;
    int x = 65;
    char znak;
    wynik = (int *) malloc(123 * sizeof(int));
    if (wynik != NULL)
      {
	while (x != 123)
	  {
	    wynik[x] = 0;
	    x++;
	  }
	while ((scanf ("%c", &znak)) != EOF)
	  {
	    wynik[znak]++;
	    fprintf (stderr,"LOG: Wczytalismy znak o wartosci %c , znak ten powtorzyl sie %d razy\n",znak, wynik[x]);
	  }
	x = 65;
	while (x != 123)
	  {
	    if (wynik[x] != 0)
	      {
		printf ("%c:%d \n", x, wynik[x]);
	      }
	    x++;
	  }
	  free(wynik);
      }
    else
      {
	fprintf (stderr, "LOG: Nie udalo sie zarezerwowac obszaru !\n");
	fprintf (stderr, "LOG: Dokup RAMu albo zwieksz obszar SWAP :)\n");

	return EXIT_FAILURE;
      }
    return EXIT_SUCCESS;
  }

#ifdef __cplusplus
}
#endif
