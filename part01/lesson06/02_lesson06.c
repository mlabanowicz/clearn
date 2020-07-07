#include <stdlib.h>
#include <stdio.h>

int
main (void)
{
  int i = 0, x = 0;
  while (1 == 1)
    {
      i += 1;
      int x = getchar ();
      if (x == EOF)
	{
	  break;
	}
      printf ("%.2x", x);
      if (i == 30)
	{
	  printf ("\n");
	  i = 0;
	}
    }
  return EXIT_SUCCESS;
}
