#include <stdio.h>
#include <limits.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define BITS (sizeof(unsigned short) * CHAR_BIT)
#define BITS_HALF (BITS / 2)

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

        return ((unsigned short)(hi << BITS_HALF)) |
               (low & (((unsigned short)1 << BITS_HALF) - 1));
    }

    unsigned short ushort_mul(unsigned short a_, unsigned short b_, unsigned short *hi_ptr)
    {
        unsigned short a = a_ >> BITS_HALF;
        unsigned short b = a_ & (((unsigned short)1 << BITS_HALF) - 1);
        unsigned short c = b_ >> BITS_HALF;
        unsigned short d = b_ & (((unsigned short)1 << BITS_HALF) - 1);

        unsigned short hi;
        unsigned short pp = b * d;
        unsigned short qq = b * c;
        unsigned short ss = a * d;
        unsigned short tt = a * c;

        unsigned short carry1, carry2, carry3;

        unsigned short low = pp;
        low = ushort_sum(low, (qq << BITS_HALF), &carry1);
        low = ushort_sum(low, (ss << BITS_HALF), &carry2);
        low = ushort_sum(low, (tt << (2 * BITS_HALF)), &carry3);

        hi = tt + (qq >> BITS_HALF) + (ss >> BITS_HALF) + carry1 + carry2 + carry3;

        if (hi_ptr)
        {
            *hi_ptr = hi;
        }

        return low;
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
