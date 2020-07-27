/**
 * Program wczytuje dane 2 osob w roznym wieku i wyswietla dane tej, ktora jest starsza.
 * Dane osob to: Imie (max 15 znakow), Rok urodzenia, Iq
 *
 * Przyklad:
 *   $ gcc 01_struct.c -o 01_struct.exe
 *   $ ./01_struct.exe < 01_struct_a.in
 *   $ ./01_struct.exe < 01_struct_b.in
 */

#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus /* Takie cos powoduje, ze program zadziala poprawnie ze wszystkimi kompilatorami C++. */
extern "C" {
#endif

/* struktowa, ktora bedzie zawierala w sobie dane osobowe */
struct dane_osobowe_s
{
  char imie [15 + 1]; /* 15 znakow na imie + 1 znak na '\0' oznaczajacy koniec lancucha */
  int  rok_urodzenia;
  int  iq;
};

int main(void)
{
  struct dane_osobowe_s osoba1; /* ta jedna zmienna zawiera w sobie 3 pola zdefiniowane wyzej */

  struct dane_osobowe_s osoba2; /* tutaj podobnie */

  struct dane_osobowe_s osoba_starsza;

  /* wczytaj dane dla osoby 1 */
  if (scanf("%s %d %d", &osoba1.imie[0], &osoba1.rok_urodzenia, &osoba1.iq) != 3)
  {
    fprintf(stderr, "Niepoprane dane wejsciowe\n");
    return EXIT_FAILURE;
  }

  /* wczytaj dane dla osoby 2 */
  if (scanf("%s %d %d", &osoba2.imie[0], &osoba2.rok_urodzenia, &osoba2.iq) != 3)
  {
    fprintf(stderr, "Niepoprane dane wejsciowe\n");
    return EXIT_FAILURE;
  }

  /* ustal, ktora osoba jest starsza */
  if (osoba1.rok_urodzenia < osoba2.rok_urodzenia)
  {
    /* wszystkie pola skopiuj ze zmiennej osoba1 do osoba_starsza */
    osoba_starsza = osoba1;
  }
  else
  {
    /* wszystkie pola skopiuj ze zmiennej osoba2 do osoba_starsza */
    osoba_starsza = osoba2;
  }

  /* wyswietl zawartosc zmiennej osoba_starsza */
  printf("[osoba starsza]\n");
  printf("imie          : %s\n", osoba_starsza.imie);
  printf("rok_urodzenia : %d\n", osoba_starsza.rok_urodzenia);
  printf("iq            : %d\n", osoba_starsza.iq);

  return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif
