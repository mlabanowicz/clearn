#include <stdio.h>
#include <stdlib.h>

#ifdef cplusplus
extern "C"
{
#endif

    int main(void){
        int i=0;
        int q = 0;
        static char tab[10];
        char * buffer;
        char* p= &tab[0];

        for(i = 0; i <= (int)sizeof(tab) - 2;i++){
            if(scanf("%c", &tab[i]) == EOF){
                break;
            }
            else{
            fprintf(stderr,"LOG: Wczytujemy znak %c do tablicy tab, i = %d\n",*p,i);
            p++;
            }
        }


        buffer = (char *)malloc(i+1); 


        if (buffer) {
            fprintf(stderr, "Zaalokowano %d bajtow ::: ptr = %p\n", i+1, (void *)buffer);
        }
        else 
        {
            fprintf(stderr, "Failed, Nie moge zaalokowac %d bajtow !\n", i);
            exit(EXIT_FAILURE);
        }
        p = &tab[i-1];
        for(;i-1>=0;i--){
            buffer[q] = *p;
            q++;
            p--;
        }

        p =  &tab[0];

       for(i=0;i != (int)sizeof(tab);i++) {
            *p='1';
            p++;
        }

        printf("%s\n", buffer);


        free(buffer);
        return EXIT_SUCCESS;
    }

#ifdef cplusplus2 
}
#endif
