/**
 * Program wczutuje napis, jego dlugosc nie moze przekroczyc 123456788 znakow
 * i wypisuje jego dlugosc na standardowe wyjscie.
 */

#include <stdio.h>  /* scanf, printf, stderr */
#include <stdlib.h> /* EXIT_SUCCESS, EXIT_FAILURE, malloc, free */
#include <string.h> /* strlen */

#ifdef __cplusplus
extern "C" {
#endif

int main(void) {

  /* Deklaracja tablicy 21 bajtow w pamieci typu STACK       */
  /* Problem tej tablicy, jest taki,                         */
  /* ze podczas pisania programu MUSIMY ustalic jej rozmiar. */
  /* Czyli do tej tablicy juz nie wpiszemy napisow           */
  /* dlozszych niz 20 znakow.                                */
  /* Nalezy pamietac, ze pamiec typu STACK jest              */
  /* dosyc mocno ograniczona, nie mozna w tej pamieci        */
  /* tworzyc pamieciozernych danych.                         */

  char tablica_on_stack [20 + 1];


  /* Deklarackja wskaznika                   */
  /* inizjalizacja wskazuje na wartosc NULL, */
  /* czyli wskazuje na nic.                  */
  char * tablica_on_heap = NULL;


  /* zawsze mozna sprawdzic, czy wskaznik jest NULL'em     */
  /* jest to przydatne do sprawdzenia, czy na cos wskazuje */
  if (tablica_on_heap == NULL) {
    fprintf(stderr, "LOG: wskaznik ma wartosc NULL, wskazuje na nic :) !\n");
  }


  printf("adres             tablica_on_stack.: %p\n", (void *)tablica_on_stack);
  /* powinien wypisac jakas wartosc adresu z obszaru STACK */


  printf("wartosc wskaznika tablica_on_heap..: %p\n", (void *)tablica_on_heap);
  /* powinien wypisac NULL/0/(nil) albo jakas wartosc           */
  /* jednoznacznie mowiaca, ze to jest NULL                     */
  /* Wartosc NULL jest zalezna od systemu, nie zawsze jest to 0 */
  /* Przyklad wypisania NULLa dla roznych systemow:             */
  /*   DOS16BIT.....: 0000:0000                                 */
  /*   GCC-LINUX....: (nil)                                     */
  /*   GCC-WINDOWS..: 00000000                                  */


  /* Zarezerwowanie obszaru pamieci typu HEAP                                 */
  /* i wpisanie adresu tego obszaru do wskaznika:                             */
  /* Zarezerowwany obszar to 123456789 bajtow. (~117MB)                       */
  /* ::::                                                                     */
  /* Prosze dla testow sprobowac zarezerwowac taki rozmiar w tablicy_on_stack */
  /* Program, jezeli sie skompiluje, to prawdopodbnie sie nie uruchomi.       */
  /* ::::                                                                     */
  tablica_on_heap = (char *)malloc(123456789);


  /* wyswietlenie adresu zarezerwowanego obszaru */
  printf("wartosc wskaznika tablica_on_heap..: %p\n", (void *)tablica_on_heap);


  /* !!! W tym momencie, jeszcze nie wiemy, czy obszar zostal zarezerowany  */
  /* !!! Musimy sprawdzic wartosc wskaznika, jezeli bedzie NULL, to znaczy, */
  /* !!! ze operacja zarezerwowania pamieci sie nie powiodla.               */
  if (tablica_on_heap != NULL) {
    /* Obszar gotowy do uzycia, jego zawartosc (bajtow w tym obszarze) jest nieznana. */

    fprintf(stderr, "LOG: Udalo sie zarezerwowac obszar 123456789 bajtow !\n");
    fprintf(stderr, "LOG: Mozemy z niego korzystac !\n");

    tablica_on_heap[0] = 'a'; /* wpisz 'a' do pierwszego elementu w tablicy */
    tablica_on_heap[1] = 'b';
    tablica_on_heap[2] = 'c';

    tablica_on_heap[123456786] = 'x';
    tablica_on_heap[123456787] = 'y';
    tablica_on_heap[123456788] = 'z'; /* wpisz 'z' do ostatniego elementu w tablicy */

    /* Teraz mozemy wczytac napis, co to moze byc dlugi na 123456789 - 1 = 123456788 znakow + '\0' */
    if (scanf("%s", tablica_on_heap) == 1) {
      printf("Dlugosc napisu: %lu\n", (unsigned long)strlen(tablica_on_heap));
    }

    /* !!! Jezeli udalo sie zarezerwowac (zaalokowac) obszar na HEAPie                */
    /* !!! to gdy juz go nie potrzebujemy to __MUSIMY__ zwolnic ten obszar dla        */
    /* !!! systemu aby inne programy mogly z niego korzystac.                         */
    /* !!! Nalezy pamietac, aby do free zostala przekazana dokladnie ta sama wartosc, */
    /* !!! jaka zostala zwrocona przez malloc                                         */

    fprintf(stderr, "LOG: Zwalnianie zaaolokawengo wczesniej obszaru na HEAP'ie : %p\n", (void *)tablica_on_heap);

    free(tablica_on_heap);
    
    /* !!! W tym miejscu już NIE MOZEMY korzystac z tego obszaru, nie jest on juz dostepny !!! */
  }
  else {
    fprintf(stderr, "LOG: Nie udalo sie zarezerwowac obszaru !\n");
    fprintf(stderr, "LOG: Dokup RAMu albo zwieksz obszar SWAP :)\n");

    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif
