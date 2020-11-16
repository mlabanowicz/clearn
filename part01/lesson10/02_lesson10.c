#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C"
{
#endif

  int main (void)
  {
    int i = 0;
    char wyraz[20 + 1];
    while (scanf ("%s", wyraz) == 1)
      {
	char *p = wyraz;


	while (1 == 1)
	  {
	    if (*p == '\0')
	      {
		break;
	      }
	    i++;


	    p += 1;


	  }

	while (1 == 1)
	  {

	    if (p == wyraz)
	      {
		break;
	      }

	    p -= 1;
	  }

	printf ("%d\n", i);
	i = 0;
      }


    return EXIT_SUCCESS;
  }

#ifdef __cplusplus
}
#endif
