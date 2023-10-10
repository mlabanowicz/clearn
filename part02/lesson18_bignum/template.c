
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned short bignum_type_t;

#define BIGNUM_HEX_DIGITS_COUNT_STR "4" /* assuming bignum_type_t is 16 bits long */

#define BITS (sizeof(bignum_type_t) * CHAR_BIT)

#define BITS_HALF (BITS / 2)

static bignum_type_t LOW(bignum_type_t v)
{
  return v & (((bignum_type_t)1 << BITS_HALF) - 1);
}

static bignum_type_t HI(bignum_type_t v)
{
  return v >> BITS_HALF;
}

static bignum_type_t JOIN(bignum_type_t hi, bignum_type_t low)
{
  return (hi << BITS_HALF) | low;
}

static bignum_type_t bignum_type_sum(bignum_type_t a, bignum_type_t b,
  bignum_type_t *carry_ptr)
{
  bignum_type_t low = LOW(a) + LOW(b);

  bignum_type_t hi = HI(low) + HI(a) + HI(b);

  if (carry_ptr)
  {
    *carry_ptr = HI(hi);
  }

  return JOIN(LOW(hi), LOW(low));
}

static bignum_type_t bignum_type_mul(bignum_type_t a, bignum_type_t b,
  bignum_type_t *hi_ptr)
{
  bignum_type_t r0 = LOW(a) * LOW(b);

  bignum_type_t ab = LOW(a) * HI(b);

  bignum_type_t ba = HI(a) * LOW(b);

  bignum_type_t r1 = HI(r0) + LOW(ab) + LOW(ba);

  if (hi_ptr)
  {
    *hi_ptr = HI(a) * HI(b) + HI(r1) + HI(ab) + HI(ba);
  }

  return JOIN(LOW(r1), LOW(r0));
}

int main(void)
{
  unsigned long la, lb;

  while (scanf("0x%lx 0x%lx\n", &la, &lb) == 2)
  {
    bignum_type_t a = (bignum_type_t)la;

    bignum_type_t b = (bignum_type_t)lb;

    bignum_type_t carry;

    bignum_type_t sum = bignum_type_sum(a, b, &carry);

    bignum_type_t mul_hi;

    bignum_type_t mul_low = bignum_type_mul(a, b, &mul_hi);

    printf("0x%0" BIGNUM_HEX_DIGITS_COUNT_STR
           "lx%0" BIGNUM_HEX_DIGITS_COUNT_STR "lx ",
           (unsigned long)carry, (unsigned long)sum);

    printf("0x%0" BIGNUM_HEX_DIGITS_COUNT_STR
           "lx%0" BIGNUM_HEX_DIGITS_COUNT_STR "lx\n",
           (unsigned long)mul_hi, (unsigned long)mul_low);
  }

  return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif
