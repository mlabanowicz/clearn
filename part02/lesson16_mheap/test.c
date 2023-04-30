
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  int items;

  srand((int)clock());

  if (scanf("%d", &items) == 1)
  {
    int count = 0;

    while (items > 0)
    {
      int r = rand() % 100;

      if (r < 50) /* 50% for cmd add */
      {
        printf("add %d\n", rand() % 100);
        ++count;
        --items;
      }
      else if ((r -= 50) < 20) /* 20% for cmd del */
      {
        if (count)
        {
          printf("del %d\n", (rand() % count) + 1);
          --count;
          --items;
        }
      }
      else if ((r -= 20) < 20) /* 20% for cmd get */
      {
        if (count)
        {
          printf("get\n");
          --items;
        }
      }
      else /* 10% for cmd dump*/
      {
        printf("dump\n");
      }
    }
  }

  return EXIT_SUCCESS;
}
