
#include <utils.h>

#ifdef __cplusplus
extern "C" {
#endif

size_t UTILS_BitsCount(void const *data, size_t size)
{
  size_t counter = 0;

  unsigned char const *ptr = (unsigned char const *)data;

  size_t i;

  static unsigned char const array [] =
  {
    #include "bitscnt/tablica.txt"
  };

  for (i = 0; i < size; i++)
  {
      counter += array[*ptr++];
  }

  return counter;
}

#ifdef __cplusplus
}
#endif
