#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include <utils.h>

#ifdef __cplusplus
extern "C"
{
#endif
    void *UTILS_LoadFile(FILE *stream, size_t *size_ptr)
    {
        char *buffer = NULL;
        size_t result = 0,length=0;
        buffer = (char *)malloc(*(int *)size_ptr * CHAR_BIT);
        result = fread(buffer, CHAR_BIT, *size_ptr, stream);
        fseek(stream,0,SEEK_END);
        length = ftell(stream);
        if (result != length && !feof(stream))
        {
            fprintf(stderr, "LOG:blad wczytywania ze strumienia stdin do pamieci HEAP %d\n", *buffer);
            free(buffer);
            exit(EXIT_FAILURE);
        }
        return buffer;
    }

#ifdef __cplusplus
}
#endif