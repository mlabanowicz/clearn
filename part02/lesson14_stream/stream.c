#include <stdio.h>
#include <stdlib.h>
#ifdef __cplusplus
extern "C"
{
#endif
    int main(void)
    {
        char c='\0', last_c='\0';
        unsigned short jest_komentarz = 0, jest_string = 0;
        if ((last_c = getchar())== EOF)
        {
            exit(EXIT_SUCCESS);
        }
        if(last_c == '\"')  jest_string =1;
        if(last_c == '\'')  jest_string =2;
        while ((c = getchar()) != EOF)
        {
        if(c == '\"' && last_c != '\\'){
            if(jest_string == 0)    jest_string = 2;
            if(jest_string == 1)    jest_string = 0;
        }
        if(c == '\'' && last_c != '\\'){
            if(jest_string == 0)    jest_string = 4;
            if(jest_string == 3)    jest_string = 0;
        }
        if(jest_string == 0){
        if (last_c == '/' && c == '/')
                jest_komentarz = 4;
        if (last_c == '/' && c == '*')
                jest_komentarz = 3;
        if(jest_komentarz != 0){
            if(jest_komentarz == 4 && c =='\n' && last_c != '\\'){
                jest_komentarz = 1;
            }
            if(jest_komentarz == 3 && c == '/' && last_c == '*'){
                jest_komentarz = 2;
            }
        }
        }
        if(!jest_komentarz){
            putchar(last_c);
        }
        if(jest_komentarz<3 && jest_komentarz !=0){
            jest_komentarz--;
        }
        if(jest_string == 4 || jest_string == 2){
            jest_string--;
        }
        last_c = c;
        }
        if(!jest_komentarz){
            putchar(last_c);            
        }
        return EXIT_SUCCESS;
    }

#ifdef __cplusplus
}
#endif