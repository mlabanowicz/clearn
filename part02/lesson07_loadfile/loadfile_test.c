#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include <utils.h>

#ifdef __cplusplus
extern "C"
{
#endif
  int main(void)
  {
    char *buffer = NULL;
    size_t length = 10;
    size_t i;
    buffer = UTILS_LoadFile(stdin, &length);

    if (buffer)
    {

      printf("OK, zaladowano dane ze strumienia\n");

      printf("Adres z danymi: %p\n", buffer);
      printf("Rozmiar danych: %lu bajtow\n", (unsigned long)length);

      for (i = 0; i < length && buffer[i] != 0; i++)
      {
        fprintf(stderr, "%p=%d'%c', i = %ld\n", &buffer[i], buffer[i], (buffer[i] >= ' ' && buffer[i] < SCHAR_MAX) ? buffer[i] : '.', (unsigned long)i);
      }
      free(buffer);
    }
    else
    {

      fprintf(stderr, "Jakis blad, nie zaladowano danych !\n");
    }
    return EXIT_SUCCESS;
  }

#ifdef __cplusplus
}
#endif