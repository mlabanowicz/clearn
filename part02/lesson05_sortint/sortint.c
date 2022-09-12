#include <stdlib.h>
#include <stdio.h>
#ifdef __cplusplus
extern "C"
{
#endif

  int main(void)
  {
    int *tablica = NULL;
    int tablica_rozmiar = 0;
    int tablica_w_uzyciu = 0;
    int i = 0, j, temp, liczba;
    while ((scanf("%d", &liczba)) != EOF)
    {
      if (tablica_w_uzyciu == tablica_rozmiar)
      {
        int nowy_rozmiar = tablica_rozmiar ? tablica_rozmiar + 1 : 1;
        void *nowy_adres = realloc(tablica, sizeof(int) * nowy_rozmiar);
        if (NULL == nowy_adres)
        {
          fprintf(stderr, "!! Failed to realloc !!\n");
          exit(EXIT_FAILURE);
        }
        tablica_rozmiar = nowy_rozmiar;
        tablica = (int *)nowy_adres;
      }

      tablica[tablica_w_uzyciu++] = liczba;
    }
    while (i != tablica_w_uzyciu - 1)
    {
      i = 0;
      for (j = 0; j < tablica_w_uzyciu - 1; j++)
      {
        if (tablica[j] > tablica[j + 1])
        {
          temp = tablica[j];
          tablica[j] = tablica[j + 1];
          tablica[j + 1] = temp;
        }
        else
        {
          i++;
        }
      }
    }
    for (i = 0; i < tablica_w_uzyciu; ++i) {
      printf("%d\n", tablica[i]);
    }
    free(tablica);
    return EXIT_SUCCESS;
  }

#ifdef __cplusplus
}
#endif