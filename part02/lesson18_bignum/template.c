
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BITS (sizeof(unsigned short) * CHAR_BIT)

#define BITS_HALF (BITS / 2)

unsigned short ushort_sum(unsigned short a, unsigned short b, unsigned short *carry_ptr);

unsigned short ushort_sum(unsigned short a, unsigned short b, unsigned short *carry_ptr)
{
  unsigned short ah = a >> BITS_HALF;

  unsigned short al = a & (((unsigned short)1 << BITS_HALF) - 1);

  unsigned short bh = b >> BITS_HALF;

  unsigned short bl = b & (((unsigned short)1 << BITS_HALF) - 1);

  unsigned short low = al + bl;

  unsigned short hi = (low >> BITS_HALF) + ah + bh;

  if (carry_ptr)
  {
    *carry_ptr = hi >> BITS_HALF;
  }

  return
    ((unsigned short)(hi << BITS_HALF))
    |
    (low & (((unsigned short)1 << BITS_HALF) - 1));
}

int main(void)
{
  unsigned int ia, ib;

  while (scanf("0x%04x 0x%04x\n", &ia, &ib) == 2)
  {
    unsigned short a = (unsigned short)ia;
    unsigned short b = (unsigned short)ib;

    unsigned short carry;

    unsigned short sum = ushort_sum(a, b, &carry);

    printf("0x%04x%04x\n", (unsigned)carry, (unsigned)sum);
  }

  return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif
