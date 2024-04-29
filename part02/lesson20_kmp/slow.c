#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inputString(FILE *fp);
int countOccurrences(const char *slowaA, const char *slowoB);

char *inputString(FILE *fp) {
#if 1
    char *str = malloc(1000000 + 1);
    if (fscanf(fp, "%s", str)) { }
    return str;
#else
    int ch;
    size_t len = 0;
    const size_t chunk = 16;

    while (EOF != (ch = fgetc(fp)) && ch != '\n') {
        if (len % chunk == 0) {
            char *temp = realloc(str, (len + chunk + 1) * sizeof(char));
            if (temp == NULL) {
                free(str);
                return NULL;
            }
            str = temp;
        }
        str[len++] = ch;
    }
    str[len] = '\0';

    return str;
#endif
}

int countOccurrences(const char *slowaA, const char *slowoB)
{
    int count = 0;
    char *ptr = strstr(slowoB, slowaA);
    while (ptr != NULL)
    {
        count++;
        ptr = strstr(ptr + 1, slowaA);
    }
    return count;
}

int main(void)
{
    char *slowoA, *slowoB;
    int occurrences;

    slowoA = inputString(stdin);
    slowoB = inputString(stdin);

    if(slowoA == NULL || slowoB == NULL){
        fprintf(stderr, "Memory allocation failed.\n");
        return EXIT_FAILURE;
    }
    occurrences = countOccurrences(slowoA, slowoB);
    printf("%d\n", occurrences);

    free(slowoA);
    free(slowoB);
    return EXIT_SUCCESS;
}
