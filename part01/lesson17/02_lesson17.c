#include <stdio.h>
#include <stdlib.h>

#ifdef cplusplus
extern "C"
{
#endif

    int main(void){
        int i=0;
        int q = 0;
        static char tab[1000000];
        char * buffer;


        for(i = 0; i <= 999999;i++){
            if(scanf("%c", &tab[i]) == EOF){
                break;
            }
            if(tab[i] == '\n' || tab[i] == ' '){
                tab[i] = '@';
                i--;
            }
            else{
            fprintf(stderr,"LOG: Wczytujemy znak %c do tablicy tab, i = %d\n",tab[i],i);
            }
        }


        buffer = (char *)malloc(i); 


        if (buffer) {
            fprintf(stderr, "Zaalokowano %d bajtow ::: ptr = %p\n", i, (void *)buffer);
        }
        else 
        {
            fprintf(stderr, "Failed, Nie moge zaalokowac %d bajtow !\n", i);
            exit(EXIT_FAILURE);
        }

        for(;i-1>=0;i--){
            buffer[q] = tab[i-1];
            fprintf(stderr,"LOG: Wczytujemy znak %c do tablicy buffer z tablicy tab. i = %d q = %d \n",tab[i-1],i-1,q);
            q++;
        }

        for(i=0;i != 1000000;i++){
            tab[i]='1';
            fprintf(stderr,"LOG: tab[%d] = %c\n",i,tab[i]);
        }

        printf("%s\n", buffer);




        free(buffer);
        return EXIT_SUCCESS;
    }

#ifdef cplusplus2 
}
#endif
