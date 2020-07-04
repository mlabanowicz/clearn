#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i=0;
    while(0 == 0){
    i = getchar();
    if(i==EOF){
    break;
    }
    if ( i>=65 && i <=90){
    i += 32;
    }
        putchar(i);
    }
    return EXIT_SUCCESS;
}
