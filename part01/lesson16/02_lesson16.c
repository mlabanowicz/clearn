#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C"
{
#endif

  int potegowanie (int x, int n);

  int potegowanie (int x, int n)
  {
    int result = 1;
    for (; n != 0; n--)
      {
	result = result * x;
      }
    return result;
  }

  int main (void)
  {
    int x = 0;
    int n = 0;
    while (scanf ("%d %d", &x, &n) == 2 && x >= 0 && n >= 0)
      {
	int potega = potegowanie (x, n);

	printf ("%d\n", potega);
      }
    if (x <= -1 || n <= -1 || scanf ("%d %d", &x, &n) != EOF)
      {
	fprintf (stderr, "blad, niepoprawne dane!\n");
	exit (EXIT_FAILURE);
      }
    return EXIT_SUCCESS;
  }

#ifdef __cplusplus
}
#endif
