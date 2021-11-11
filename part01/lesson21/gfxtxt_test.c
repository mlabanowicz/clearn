
#include "gfxtxt.h"

#include <stdlib.h> /* EXIT_SUCCESS */

#ifdef __cplusplus
extern "C" {
#endif

int main(void)
{
  void * gfxtxt = GFXTXT_Create(40, 10);

  if (gfxtxt) {

    GFXTXT_Clear(gfxtxt, 'a');
    GFXTXT_ToFile(gfxtxt, stdout);

    printf("------\n");

    GFXTXT_Clear(gfxtxt, '@');
    GFXTXT_ToFile(gfxtxt, stdout);

    printf("------\n");

    GFXTXT_DrawRect(gfxtxt, 10, 2, 5, 4, '.');
    GFXTXT_ToFile(gfxtxt, stdout);

    GFXTXT_Destroy(gfxtxt);
  }

  return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif
