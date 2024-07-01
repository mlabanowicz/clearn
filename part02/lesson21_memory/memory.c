
#include <stdio.h>
#include <stdlib.h>

static int bar(int a, int b, int * c, int * i)
{
  if (0) { printf("%d %d %d %d\n", a, b, *c, *i); }

  if (*i && ((a & 2) == 0))
  {
    --(*i);
    ++(*c);
  }

  return *i;
}

static long foo(int a, int b, int * c, int * i)
{
  /* [++] == kod do naprawienia == */

  long result = 0;

  while (bar(a, b, c, i))
  {
    a += 5;
    b -= 7;

    result += *i + *c;
  }

  return result;

  /* [--] == kod do naprawienia == */
}

int main(void)
{
  int i, c = 0;

  if (scanf("%d", &i) == 1)
  {
    printf("%ld\n", foo(0, 0, &c, &i));
  }

  return EXIT_SUCCESS;
}
