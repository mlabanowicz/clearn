#include <stdio.h>
#include <stdlib.h>
#ifdef __cplusplus
extern "C"
{
#endif
    int multiply(int a, int b)
    {
        return a * b;
    }
    int divide(int a, int b)
    {
        if (b == 0)
        {
            fprintf(stderr, "LOG: pamietaj cholero nie dziel przez zero!\n");
        }
        return b ? a / b : 0;
    }
    int add(int a, int b)
    {
        return a + b;
    }
    int subtract(int a, int b)
    {
        return a - b;
    }

    int main(void)
    {
        int *tablica = NULL;
        int tablica_rozmiar = 0;
        int tablica_w_uzyciu = 0;
        int (*funcptr)(int, int) = NULL, a = 0, b = 0;
        char symbol;
        if (!(scanf("%c", &symbol)))
        {
            fprintf(stderr, "LOG: false symbol");
            exit(EXIT_FAILURE);
        }
        switch (symbol)
        {
        case '+':
            funcptr = &add;
            break;
        case '-':
            funcptr = &subtract;
            break;
        case '*':
            funcptr = &multiply;
            break;
        case '/':
            funcptr = &divide;
            break;
        default:
            fprintf(stderr, "LOG: false symbol");
            exit(EXIT_FAILURE);
            break;
        }
        while ((scanf("%d %d", &a, &b)) != EOF)
        {
            if (tablica_w_uzyciu == tablica_rozmiar)
            {
                int nowy_rozmiar = tablica_rozmiar ? tablica_rozmiar + 1 : 1;
                void *nowy_adres = realloc(tablica, sizeof(int) * nowy_rozmiar);
                if (NULL == nowy_adres)
                {
                    fprintf(stderr, "!! Failed to realloc !!\n");
                    exit(EXIT_FAILURE);
                }
                tablica_rozmiar = nowy_rozmiar;
                tablica = (int *)nowy_adres;
            }
            tablica[tablica_w_uzyciu++] = funcptr(a, b);
        }

        for (a = 0; a < tablica_rozmiar; a++)
        {
            printf("%d\n", tablica[a]);
        }
        free(tablica);
        return EXIT_SUCCESS;
    }

#ifdef __cplusplus
}
#endif