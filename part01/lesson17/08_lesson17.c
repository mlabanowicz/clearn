#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C"
{
#endif

    int main(void){
        int i=0;
        int q = 0;
        static char tab[1000000];
        char * buffer;
        char* p= &tab[0];

        for(i = 0; i <= (int)sizeof(tab) -1 ;i++){
            if(scanf("%c", p) == EOF){
                break;
            }
            else{
            fprintf(stderr,"LOG: Wczytujemy znak %c do tablicy tab, i = %d\n",*p,i);
            p++;
            }
        }
		

        buffer = (char *)malloc(i); 

		if(i == 0){
			fprintf(stderr,"LOG:brak danych!\n");
	        free(buffer);
			exit(EXIT_SUCCESS);
		}
        if (buffer) {
            fprintf(stderr, "Zaalokowano %d bajtow ::: ptr = %p\ni = %d  \n", i, (void *)buffer, i);
        }
        else 
        {
            fprintf(stderr, "Failed, Nie moge zaalokowac %d bajtow !\n", i);
            exit(EXIT_FAILURE);
        }

        i--;
        p = &tab[i];
        for(;i>=0;i--){
            buffer[q] = *p;
            q++;
            p--;
        }
        q--;
        p =  &tab[0];
       for(i=0;i != (int)sizeof(tab);i++) {
            *p='1';
            p++;
        }
        for(i=0;i <= q; i++){
        printf("%c", buffer[i]);
        }
		printf("\n");
        free(buffer);
        return EXIT_SUCCESS;
    }

#ifdef __cplusplus
}
#endif
