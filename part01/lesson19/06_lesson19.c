/*troche inaczej bardzie z schematem 04_hint.txt */
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif
    int main(void) {       
        int is2bytes = 0;
        unsigned char secletter = 0x00;
        unsigned char letter;
        int i=0;
        unsigned char * ptr = &letter;
        unsigned char * secptr = &secletter;
        unsigned char male[2][9] = {
            {0xc4,0xc4,0xc4,0xc5,0xc5,0xc3,0xc5,0xc5,0xc5},
           
            {0x85,0x87,0x99,0x82,0x84,0xb3,0x9b,0xbc,0xba}
           
        };
        unsigned char duze[2][9] = {
            {0xc4,0xc4,0xc4,0xc5,0xc5,0xc3,0xc5,0xc5,0xc5},
           
            {0x84,0x86,0x98,0x81,0x83,0x93,0x9a,0xbb,0xb9}
           
        };
        while(scanf("%c",ptr) != EOF){
            if(*ptr <= 0x7f){
                fprintf(stderr,"znak ma 1 bajt\n");
                    if(*ptr >= 65 && *ptr <= 90){
                        *ptr = *ptr + 32;
                    }
                    else{
                        if(*ptr>=97 && *ptr <= 122){
                        *ptr = *ptr-32;
                        }
                    }
            }
            if(*ptr >= 0xC0 && *ptr <=0xDF){
                is2bytes = 1;
                fprintf(stderr,"znak ma 2 bajty\n");
            }
            if(is2bytes == 1 && *ptr >= 0x80 && *ptr <= 0xBF){
                is2bytes = 0;
                for(i =0;i<=8;i++){
                        if(*secptr == male[0][i] && *ptr == male[1][i]){
                            *ptr = duze[1][i];
                    }
                    else{
                        if(*secptr == duze[0][i] && *ptr == duze[1][i]){
                            *ptr = male[1][i];
                        }                   
                    }
                }
            }
        printf("%c",*ptr);
        *secptr = *ptr;
        }
       
        return EXIT_SUCCESS;
      }
#ifdef __cplusplus
}
#endif
