#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef __cplusplus
extern "C"
{
#endif
  int main (void)
  {
    char *alfabet = NULL;
    int *wynik = NULL;
    int x = 65;
    char znak;
      alfabet = (char *) malloc (81);
      wynik = (int *) malloc (81);
    if (alfabet != NULL && wynik != NULL)
      {
	while (x != 123)
	  {
	    if (x < 91 || x > 96)
	      {
		alfabet[x] = x;
		fprintf (stderr, "LOG:Przypisalismy do tablica[%d] znak rowny %c\n", x, alfabet[x]);
	      }
	    ++x;
	  }
	x = 65;
	while (x != 123)
	  {
	    wynik[x] = 0;
	    x++;
	  }
	while ((scanf ("%c", &znak)) != EOF)
	  {
	    x = 65;
	    while (x != 123)
	      {
		if (znak == alfabet[x])
		  {
		    wynik[x]++;
		    break;
		  }
		x++;
		if(x == 122){
		  fprintf(stderr,"znak \"%c\" nie jest zamieszczony w naszej tablicy\n",znak);
		}
	      }

	    fprintf (stderr,"LOG: Wczytalismy znak o wartosci %c , znak ten powtorzyl sie %d razy\n",znak, wynik[x]);
	  }
	x = 65;
	while (x != 123)
	  {
	    if (wynik[x] != 0)
	      {
		printf ("%c:%d \n", alfabet[x], wynik[x]);
	      }
	    x++;
	  }
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
