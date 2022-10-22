#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include <utils.h>

#ifdef __cplusplus
extern "C"
{
#endif

    void UTILS_DumpData(FILE *output, void const *data, size_t size)
    {
        size_t i;
        int j = 0;
        /*char const * column = "| ";*/
        char *ptr = (char *)data;
        for (i = 0; i < (size / 16) + 1 && i * 16 <= size; i++)
        {
            fprintf(output, " | ");
            for (j = 0; j < 16; j++)
            {
                if (j == 0)
                    fprintf(output, "%08lX | ", (unsigned long)(i * 16) + j);
                if ((i * 16) + j >= size)
                {
                    fprintf(output, "   ");
                }
                else
                {
                    fprintf(output, "%02X ", ptr[(i * 16) + j]);
                    
                }
                if (j == 7){
                        fprintf(output, " ");
                    }
            }
            fprintf(output, "| ");
            for (j = 0; j < 16; j++)
            {
                if ((i * 16) + j >= size)
                {
                    fprintf(output, " ");
                }
                else
                {
                    fprintf(output, "%c", (ptr[(i * 16) + j] >= ' ' && ptr[(i * 16) + j] < SCHAR_MAX) ? ptr[(i * 16) + j] : '.');
                }
            }
            fprintf(output, " |\n");
        }
    }

#ifdef __cplusplus
}
#endif
