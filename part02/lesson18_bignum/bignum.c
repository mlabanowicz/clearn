#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <limits.h>

#define BITS (sizeof(unsigned short) * CHAR_BIT)
#define BITS_HALF (BITS / 2)
#define BITS_QTR (BITS / 4)
    unsigned short ushort_sum(unsigned short a, unsigned short b, unsigned short *carry_ptr);

    unsigned short ushort_mul(unsigned short a, unsigned short b, unsigned short *hi_ptr);

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

        return (hi << BITS_HALF) |
               (low & (((unsigned short)1 << BITS_HALF) - 1));
    }

    unsigned short ushort_mul(unsigned short a, unsigned short b, unsigned short *hi_ptr)
    {
        unsigned short i = 0;
        unsigned short sum = 0;
        unsigned short rest = 0;
        *hi_ptr = 0;
        for (i = 0; i < 16; i++)
        {
            sum = ushort_sum(sum, (((a >> (i)) & 1) * b) << i, &rest);
            *hi_ptr += rest;
            *hi_ptr += (((a >> (15 - i)) & 1) * b) >> (i + 1);
        }

        return sum;
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

            unsigned short mul_hi;

            unsigned short mul_low = ushort_mul(a, b, &mul_hi);

            printf("0x%04x%04x ", (unsigned)carry, (unsigned)sum);

            printf("0x%04x%04x\n", (unsigned)mul_hi, (unsigned)mul_low);
        }
        return 0;
    }

#ifdef __cplusplus
}
#endif
