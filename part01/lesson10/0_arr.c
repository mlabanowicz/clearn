
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

static void zwyklaTablica(void)
{
  /* deklaracja tablicy, co to ma 5 elementow typu char */
  /* Elementy w takiej tablicy mozna zmieniac/modyfikowac. */
  char arr [5];

  /* arr to jest adres tej tablicy w RAM */
  /* mozemy wyswietlic ten adres wykorzystujac: */
  /*   printf "%p" (void *) */
  printf("zwyklaTablica:  arr     = %p\n", (void *)(arr));

  /* Dla tak zadeklarowanej tablicy &arr jest takze tym samym adresem: */
  /* [__INNY_TYP__] : typ jest wtedy taki dziwny: (char (*)[5]) -> lepiej tego nie uzywac */
  printf("zwyklaTablica: &arr     = %p\n", (void *)(&arr));

  /* Adresy poszczegolnych komorek w tablicy: */
  printf("zwyklaTablica:  arr[0]  = %p\n", (void *)(&arr[0]));
  printf("zwyklaTablica:  arr[1]  = %p\n", (void *)(&arr[1]));
  printf("zwyklaTablica:  arr[2]  = %p\n", (void *)(&arr[2]));
  printf("zwyklaTablica:  arr[3]  = %p\n", (void *)(&arr[3]));
  printf("zwyklaTablica:  arr[4]  = %p\n", (void *)(&arr[4]));

  /* Adresy poszczegolnych komorek w tablicy wykorzystujac operator dodawania: */
  printf("zwyklaTablica:  arr + 0 = %p\n", (void *)(arr + 0));
  printf("zwyklaTablica:  arr + 1 = %p\n", (void *)(arr + 1));
  printf("zwyklaTablica:  arr + 2 = %p\n", (void *)(arr + 2));
  printf("zwyklaTablica:  arr + 3 = %p\n", (void *)(arr + 3));
  printf("zwyklaTablica:  arr + 4 = %p\n", (void *)(arr + 4));

  /* Zawartosc tej tablicy jest nieustalona, ustalenie zawartosci: */
  arr[0] = 'a';
  arr[1] = 'b';
  arr[2] = 'c';
  arr[3] = 'd';
  arr[4] = '\0';

  /* Nalezy pamietac, ze "%s" wymaga adresu na znak, czyli typu (char *) */

  printf("zwyklaTablica:  arr     = \"%s\"\n", arr);

  /* [__INNY_TYP__] : to rzutowanie jest tutaj wymagane ze wzgledu na inny typ */
  printf("zwyklaTablica: &arr     = \"%s\"\n", (char *)(&arr));

  printf("zwyklaTablica: &arr[0]  = \"%s\"\n", &arr[0]);
  printf("zwyklaTablica: &arr[2]  = \"%s\"\n", &arr[2]);
  printf("zwyklaTablica:  arr + 3 = \"%s\"\n", arr + 3);
}

static void inicjalizacjaTablicy(void)
{
  {
    /* inicjalizacja wszystkich 20 elementow tablicy: */
    /* pierwsze 3 elementy to 'd' 'o' 'g' */
    /* pozostale 17 elementow to '\0' */
    char arr_a [20] = "dog";

    /* sizeof zwrca typ (size_t), printf "%d" spodziewa sie (int), dlatego trzbea to rzutowac: */
    printf("inicjalizacjaTablicy: sizeof(arr_a) = %d\n", (int)sizeof(arr_a));
    printf("inicjalizacjaTablicy: arr_a = \"%s\"\n", arr_a);
  }

  {
    /* inicjalizacja wszystkich 3 elementow tablicy: */
    /* elementy to 'd' 'o' 'g' */
    /* !!!! Pamietac trzeba, ze ta tablica nie ma '\0' */
    /* Tak wiec nie mozemy traktowac tej tablicy jako string'a */
    char arr_b [3] = "cat";

    printf("inicjalizacjaTablicy: sizeof(arr_b) = %d\n", (int)sizeof(arr_b));
    printf("inicjalizacjaTablicy: arr_b = '%c' '%c' '%c'\n", arr_b[0], arr_b[1], arr_b[2]);
  }

  {
    /* inicjalizacja tablicy bez podawania wprost rozmiaru: */
    /* Taka inicjalizacja oznacza, ze wszystkie elementy tablicy */
    /* sa ustalone, ta tablica sklada sie z 13 znakow (12 znakow napis + '\0') */
    char arr_c [] = "Ala ma kota.";

    printf("inicjalizacjaTablicy: sizeof(arr_c) = %d\n", (int)sizeof(arr_c));
    printf("inicjalizacjaTablicy:        arr_c  = \"%s\"\n", arr_c);
  }

  {
    /* Tablica zainicjalizowana za pomoca poszczegolnych elementow: */
    char arr_d [] = {'q', 'w', 'e', 'r', 't', '\0', 'x', 'y', 'z', '\0'};

    printf("inicjalizacjaTablicy: sizeof(arr_d)     = %d\n", (int)sizeof(arr_d));
    printf("inicjalizacjaTablicy:        arr_d      = \"%s\"\n", arr_d);
    printf("inicjalizacjaTablicy:        arr_d + 6  = \"%s\"\n", arr_d + 6);
  }
}

static void wskazniki(void)
{
  /* Tablica 5 elementowa zawierajaca znaki 't' 'e' 's' 't' '\0' */
  char arr [5] = "test";

  /* wskaznik, czyli zmienna zawierajaca adres */
  /* ponisza deklaracja powoduje, ze ta zmienna ptr ma wartosc nieustalona: */
  char * ptr;

  /* ustalneie wartosci -> musi wskazywac na jakis adres w pamieci: */
  ptr = &arr[0]; /* adres zerowego elementu w tablicy arr */

  printf("wskazniki: arr = %p = \"%s\"\n", (void *)(arr), arr);
  printf("wskazniki: ptr = %p = \"%s\"\n", (void *)(ptr), ptr);

  /* ptr, jako zmienna, mozna modyfikowac */
  /* Czyli, jezeli chcemy przeskoczyc o 3 elementy: */
  ptr += 2;
  /* Teraz ptr wskazuje na 2 element w tablicy arr */
  printf("wskazniki: (+=2) ptr = %p = \"%s\"\n", (void *)(ptr), ptr);

  ++ptr;
  /* Teraz ptr wskazuje na 3 element w tablicy arr */
  printf("wskazniki: (++ ) ptr = %p = \"%s\"\n", (void *)(ptr), ptr);

  /* arr nie mozna modyfikowac, poniewaz arr nie jest zmienna */
  /* arr nalezy traktowac jako doslowny adres w pamieci */
}

int main(void)
{
  zwyklaTablica();
  puts("");
  inicjalizacjaTablicy();
  puts("");
  wskazniki();

  return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif
