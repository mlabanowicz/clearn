
#include <stdio.h>  /* stdout       */
#include <stdlib.h> /* EXIT_SUCCESS */

/* podanie kompilatorowi -I<katalog_MODULES> powoduje, ze tutaj mozemy uzyc nawiasow ostrych */
#include <utils.h>

#ifdef __cplusplus
extern "C" {
#endif

int main(void) {

  /* wykorzystanie funkcji z naszej wlasnej biblioteki utils */
  UTILS_BuildInfo(stdout);

  return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif
