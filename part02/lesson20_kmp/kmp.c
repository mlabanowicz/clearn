#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inputString(FILE *fp);
int countOccurrences(const char *slowaA, const char *slowoB);

char *inputString(FILE *fp)
{
    char *str = NULL;
    int ch;
    size_t len = 0;

    while (EOF != (ch = fgetc(fp)) && ch != '\n')
    {
        str = realloc(str, sizeof(*str) * (len + 2)); /* new character + \0 */
        if (str == NULL)
        {
            return str;
        }
        str[len++] = ch;
    }
    str[len] = '\0';

    return str;
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