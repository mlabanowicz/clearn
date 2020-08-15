#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (int argc, char *argv[])
{
  int result = 0;
  char word[50];
  while (1 == 1)
    {
      int scanf_result = scanf ("%s", word);
      if (scanf_result != 1 && scanf_result != EOF)
	{
	  fprintf (stderr, "Niepoprane dane wejsciowe\n");
	  return EXIT_FAILURE;
	}
      if (scanf_result == EOF)
	break;
	      char * ptr = strstr(word,argv[2]);
    while(str != NULL){
    result++;
    str = strstr(str+1, argv[argc-1]);
    }
    }
  printf("%d", result);
  return EXIT_SUCCESS;
}
