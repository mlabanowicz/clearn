#include <stdio.h>
#include <stdlib.h>
#ifdef __cplusplus
extern "C" {
    #endif
    int main(void)
    {
        int tablica [256];
        int * p = &tablica[0];
        int i=0;
        while(i != 255 && scanf("%d", p) == 1){
            fprintf(stderr, "LOG:Wczytujemy znak %d do komorki o adresie %p i = %d!\n", tablica[i] ,(void *)p, i);
            p++;
            i++;
        }
        for(;i != 0;i--){
            printf("%d\n",tablica[i-1]);
        }
        return EXIT_SUCCESS;
    }
    #ifdef __cplusplus
}
#endif
