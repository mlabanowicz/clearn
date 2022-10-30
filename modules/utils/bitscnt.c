#include <utils.h>

#include <limits.h>
#include <stdio.h>
#ifdef __cplusplus
extern "C"
{
#endif

    size_t UTILS_BitsCount(void const *data, size_t size)
    {
        size_t count = 0;
        char *ptr = (char *)data;
        size_t i;
        unsigned char j;
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < CHAR_BIT; j++)
            {
                /*if(*ptr>>j) % 2 == 1){
                  count++; 1 sposob z modulo
                }*/
                /*if((unsigned char)(*ptr<<j) % 128 != (unsigned char)(*ptr<<j)){
                    count++; 2 sposob z modul
                }*/
                count += (*ptr >> j) & 1;
            }
            ptr++;
        }
        return count;
    }

#ifdef __cplusplus
}
#endif
