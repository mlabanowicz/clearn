#include <stdio.h>
#include <stdlib.h>
#ifdef __cplusplus
extern "C" {
    #endif
    int main(void)
    {
        int tablica [256];
        int * p = &tablica[0];
        int i=-1;
        while(scanf("%d", p) == 1 && i != 255){
            i++;
            fprintf(stderr, "LOG:Wczytujemy znak %d do komórki o adresie %p i = %d!\n", tablica[i] , p, i);
            p++;
        }
        for(;i != 0;i--){
            printf("%d\n",tablica[i]);
        }
        return EXIT_SUCCESS;
    }
    #ifdef __cplusplus
}
#endif
