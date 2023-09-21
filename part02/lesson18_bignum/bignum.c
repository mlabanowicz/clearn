#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <limits.h>

#define BITS (sizeof(unsigned short) * CHAR_BIT)
#define BITS_HALF (BITS / 2)

    unsigned short ushort_sum(unsigned short a, unsigned short b, unsigned short *carry_ptr);

    unsigned short ushort_sum(unsigned short a, unsigned short b, unsigned short *carry_ptr)
    {
        unsigned short sumh, suml;
        unsigned short bh = b >> BITS_HALF;
        unsigned short bl = b & (((unsigned short)1 << BITS_HALF) - 1);
        unsigned short ah = a >> BITS_HALF;
        unsigned short al = a & (((unsigned short)1 << BITS_HALF) - 1);
        sumh = ah + bh;
        suml = al + bl;
        if (suml > 0x00ff)
        {
            suml -= 0x0100;
            sumh += 0x0001;
        }
        if (sumh > 0x00ff)
        {
            sumh -= 0x0100;
            *carry_ptr = 0x0001;
        }
        else
        {
            *carry_ptr = 0x0000;
        }
        return (sumh << BITS_HALF) | suml;
    }

    int main(void)
    {
        unsigned int ia, ib;

        while (scanf("0x%08x 0x%08x\n", &ia, &ib) == 2)
        {
            unsigned short a = (unsigned short)ia;
            unsigned short b = (unsigned short)ib;

            unsigned short carry;

            unsigned short sum = ushort_sum(a, b, &carry);

            printf("0x%04x%04x\n", (unsigned)carry, (unsigned)sum);
        }
        return 0;
    }

#ifdef __cplusplus
}
#endif
