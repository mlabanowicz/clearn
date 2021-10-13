
/* zainkludowanie headera od modulu */
#include "01_suma.h"

/* Tutaj wstawiamy biblioteki, ktore sa potrzebne, aby zaimplementowac kod */
#include <string.h>

/* kompatybilnosc z C++ */
#ifdef __cplusplus
extern "C" {
#endif

/* Implementacje funkcji */

int suma(int a, int b)
{
  int result;

  result = a + b;

  return result;
}

void suma_drukuj(int a, int b, FILE * stream)
{
  int result = suma(a, b);

  fprintf(stream, "%d\n", result);
}

/* kompatybilnosc z C++ */
#ifdef __cplusplus
}
#endif
