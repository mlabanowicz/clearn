
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#ifdef __cplusplus
extern "C" {
#endif

static int bitsCnt(unsigned int v)
{
  int result = 0;

  while (v)
  {
    result += (v & 1);

    v >>= 1;
  }

  return result;
}

int main(void)
{
  unsigned int i = 0;

  while (i <= UCHAR_MAX)
  {
    printf("%c%d", i ? ',' : ' ', bitsCnt(i));

    ++i;
  }

  puts("");

  return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif
