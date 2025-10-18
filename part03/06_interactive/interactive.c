#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

char query(int value);

int main(void)
{
    int min = INT_MIN;
    int max = INT_MAX;
    int i = 0;
    char answer;

    while (min <= max)
    {
        answer = query(i);
        if (answer == '>')
        {
            if (min == INT_MAX)
            {
                fprintf(stderr, "OVERFLOW!\n");
                return EXIT_FAILURE;
            }
            min = i + 1;
        }
        else if(answer == '<')
        {
            if (max == INT_MIN)
            {
                fprintf(stderr, "OVERFLOW!\n");
                return EXIT_FAILURE;
            }
            max = i - 1;
        }
        else if(answer == '=')
        {
            printf("Your number is %d!\n",i);
            return EXIT_SUCCESS;
        }
     
        i = min + (max - min) / 2;
    }
    printf("You are lying!\n");
    return EXIT_SUCCESS;
}

char query(int value)
{
  char answer [8];
  printf("%d\n", value); /* wysylamy zapytanie do uzytkownika */
  fflush(stdout);
  scanf("%7s", answer); /* odczytujemy cala linie jaka odpowiedz */
  return *answer;
}

#ifdef __cplusplus
}
#endif
