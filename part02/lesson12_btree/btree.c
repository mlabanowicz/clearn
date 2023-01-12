
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

static int walk(int const * array, int height, int leaf)
{
  /* to be implemneted */
}

int main(void)
{
  int btree [] = {0/*unused*/, 6, 2, 4, 2, 0, 1, 3 };

  int r;

  r = walk(btree, 2, 1);

  printf("%d\n", r);

  return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif
