
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  unsigned char c = 0x80;

  printf("0x%02x\n", (unsigned)c);

  c <<= 1;

  printf("0x%02x\n", (unsigned)c);

  return EXIT_SUCCESS;
}
