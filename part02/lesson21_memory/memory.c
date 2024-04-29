
#include <stdio.h>
#include <stdlib.h>

static int bar(int a, int b, int c, int * i)
{
  if (*i)
  {
    --(*i);

    if (!*i)
    {
      printf("%d\n", a + b + c);
    }
  }

  return *i;
}

static void foo(int a, int b, int c, int * i)
{
  /* [++] == kod do naprawienia == */

  if (bar(a, b, c, i))
  {
    a += 5;
    b -= 7;
    c += 3;

    foo(a, b, c, i);
  }

  /* [--] == kod do naprawienia == */
}

int main(void)
{
  int i = 1000 * 1000;

  foo(0, 0, 0, &i);

  return EXIT_SUCCESS;
}
