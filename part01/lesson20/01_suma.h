
/* Straznik, ktory zapewnia, ze dane beda zaladowane tylko 1 raz,
   nawet, gdy *include* bedzie wielokrotne.

   Nazwa SUMA_H__ wzieta po prostu na podstawie nazyw pliku,
   chodzi o to, aby byla w jakis sposob czytelna i unikalna
*/
#ifndef SUMA_H__
#define SUMA_H__

/* Tutaj wstawiamy biblioteki, ktore sa potrzebne, aby zdefiniowac API */
/* przykladowo, typ FILE jest zdefiniowany w stdio.h: */
#include <stdio.h>

/* kompatybilnosc z C++ (dzieki temu taka bliblioteka moze byc uzyta w C++ bez zadnych przeszkod) */
#ifdef __cplusplus
extern "C" {
#endif

/* Deklaracje funkcji */
int suma(int a, int b);
void suma_drukuj(int a, int b, FILE * stream);

/* kompatybilnosc z C++ */
#ifdef __cplusplus
}
#endif

#endif /* SUMA_H__ */ /* koniec straznika */
