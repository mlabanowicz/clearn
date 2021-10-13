
#include <stdlib.h> /* EXIT_SUCCESS */

#include "01_suma.h" /* suma_drukuj */

#ifdef __cplusplus
extern "C" {
#endif

int main(void)
{
  suma_drukuj(12, 78, stderr);

  return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif
