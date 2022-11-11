#include <utils.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#ifdef __cplusplus
extern "C"
{
#endif

    size_t UTILS_BitsCountByArray(void const *data, size_t size)
    {
        size_t counter = 0;
        unsigned char *ptr = (unsigned char *)data;
        size_t i;
        unsigned char j;
        unsigned char * ptr2 = malloc(CHAR_BIT * 256),* array = ptr2;
        for(i=0;i < 256;i++){
            *ptr2 = 0;
            for (j = 0; j < CHAR_BIT; j++)
            {
                  *ptr2 += (i >> j) & 1;
            }
            ptr2++;
        }
        for (i = 0; i < size; i++)
        {
            counter += array[(short)*ptr];
            ptr++;
        }
        free(array);
        return counter;
    }

#ifdef __cplusplus
}
#endif
