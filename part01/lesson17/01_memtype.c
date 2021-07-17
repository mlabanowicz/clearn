
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* 1. [Pamiec typu STACK] */
/*      - alokowana automatycznie dla zmiennych podczas wywolania funkcji */
/*      - dealokowana automatycznie podczas zakonczenia dzialania funkcji */
/*    rozmiary _NIE_ moga byc duze, jest to pamiec na zmienne funkcyjne, przewaznie rozmiar jest ograniczony. */
int mem_stack(int a);
int mem_stack(int a) {

  char str1 [32]; /* tablica 32 znakow, !!! zawartosc jest niezdefiniowana !!! */

  char str2 [32] = "cos tam"; /* tablica 32 znakow, zawartosc jest niezdefiniowana,
                                 pierwsze 7 bajtow to ten napis, reszta to same zera,
                                 inicjalizacja jest zawsze wykonywana podczas odpalania funkcji */

  char str3 [ ] = "moje dane"; /* tablica skladajaca sie z 10 bajtow (napis + '\0') */

  char str4 [9] = "moje dane"; /* tablica skladajaca sie z 9 bajtow (napis, nie ma '\0') */

  str1[0] = a;

  return str1[0] + str2[0] + str3[0] + str4[0];
}

/* 2. [Pamiec typu HEAP] */
/*      - alokowana przez programiste w dowolnym momencie */
/*      - musi byc przed zakonczeniem dzialania programu dealokowana przez programiste */
/*    rozmiary moga byc duze, limitem jest jedynie system i jego zasoby */
int mem_heap(int a);
int mem_heap(int a) {
  int result = 0;
  char * buffer = (char *)malloc(100000000 + a); /* !!! zawartosc jest niezdefiniowana !!! */
  if (buffer) {
    fprintf(stderr, "Zaalokowano %d bajtow ::: ptr = %p\n", 100000000 + a, (void *)buffer);
  } else {
    fprintf(stderr, "Failed, Nie moge zaalokowac %d bajtow !\n", 100000000 + a);
    result = -1;
  }
  free(buffer);
  return result;
}

/* 3. [Pamiec typu BSS - wyczyszczona zerami przed uruchomieniem programu */
/*    rozmiary moga byc duze, limitem jest jedynie system i jego zasoby */
/*    zmienne BSS sa widoczne przez caly czas dzialania programu. */

/*    BSS deklaracja exportowalnej tablicy: */
/*      o) widoczna w kazdej funkcji ponizej */
/*      o) dostep do tej tablicy moga miec programy skompilowane w innych plikach *.c */
int array_1 [1000000];

/*    BSS deklaracja lokalnej tablicy: */
/*      o) widocznej w kazdej funkcji ponizej */
/*      o) dostep do tej tablicy ma tylko program w obecnym pliku */
static int array_2 [1000000];

/*    BSS deklaracja lokalnej tablicy w funkcji: */
/*      o) widocznej tylko w tej jednej funkcji, w ktorej jest zdefiniowana */
int mem_bss(int a);
int mem_bss(int a) {
  static int array_3 [1000000];
  return array_3[a];
}

int main(void)
{
  mem_stack(5);

  mem_heap(6);

  printf("%d %d\n", array_1[0], array_2[0]);

  mem_bss(2);

  return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif
