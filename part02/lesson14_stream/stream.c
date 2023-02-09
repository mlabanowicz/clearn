#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C"
{
#endif
    /*
    i = 1 zeby nie wypisywal '/' w *
    i = 2 dla 2 x /
    i = 3 dla *
    */
    int main(void)
    {
        char c='\0', last_c='\0';
        short status = 0, x = 0;
        if ((last_c = getchar())== EOF)
        {
            exit(EXIT_SUCCESS);
        }
        while ((c = getchar()) != EOF)
        {
            if (last_c == '/' && c == '/')
                status = 2;
            if (last_c == '/' && c == '*')
                status = 3;
            if (!status)
            {
                putchar(last_c);
            }
            if (status == 1)
            {
                status--;
            }
            if (status == 2 && c == 92)
            {
                x = 1;
            }
            if (status == 2 && c == '\n')
            {
                if (x)
                {
                    x = 0;
                }
                else
                {
                    status = 0;
                }
            }
            if (status == 3 && last_c == '*' && c == '/')
            {
                status = 1;
            }
            last_c = c;
        }
        if (!status)
        {
            putchar(last_c);
        }
        return EXIT_SUCCESS;
    }

#ifdef __cplusplus
}
#endif