#include <stdio.h>
#include <stdlib.h>
#ifdef __cplusplus
extern "C"
{
#endif
    static int multiply(int a, int b)
    {
        return a * b;
    }
    static int divide(int a, int b)
    {
        if (b == 0)
        {
            fprintf(stderr, "LOG: pamietaj cholero nie dziel przez zero!\n");
        }
        return b ? a / b : 0;
    }
    static int add(int a, int b)
    {
        return a + b;
    }
    static int subtract(int a, int b)
    {
        return a - b;
    }

    int main(void)
    {
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
        while ((scanf("%d %d", &a, &b)) == 2)
        {
            printf("%d\n", funcptr(a, b));
        }
        return EXIT_SUCCESS;
    }

#ifdef __cplusplus
}
#endif