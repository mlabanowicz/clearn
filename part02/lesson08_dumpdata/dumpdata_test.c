
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include <utils.h>

#ifdef __cplusplus
extern "C" {
#endif

int main(void)
{
  size_t   size = 0;
  void   * data = UTILS_LoadFile(stdin, &size);

  UTILS_DumpData(stdout, data, size);

  free(data);

  return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif
