#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif
    int main(void) {       
        int is2bytes = 0;
        unsigned char secletter = 0x00;
        unsigned char letter;
        unsigned char  i;        
        unsigned char * ptr = &letter;
        unsigned char * secptr = &secletter;
        while(scanf("%c",ptr) != EOF){
            i = *ptr;
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
                fprintf(stderr,"zmieniamy 2 bajt \n");
                is2bytes = 0;
                switch(*secptr){
                    case 0xc3:
                        switch(i){
                            case 0xb3:
                            *ptr = 0x93;
                            break;                    
                            case 0x93:
                            *ptr = 0xb3;
                            break;
                        }
                    break;
               
                    case 0xc4:
                        switch(i){
                            case 0x85:
                            *ptr = *ptr -1;
                            break;
                            case 0x84:
                            *ptr = *ptr +1;
                            break;
                            case 0x87:
                            *ptr = *ptr -1;
                            break;
                            case 0x99:
                            *ptr = *ptr -1;
                            break;
                            case 0x86:
                            *ptr = *ptr +1;
                            break;
                            case 0x98:
                            *ptr = *ptr +1;
                            break;
                        }
                    break;
               
                    case 0xc5:
                        switch(i){
                            case 0x82:
                            *ptr = *ptr -1;
                            break;
                            case 0x84:
                            *ptr = *ptr -1;
                            break;
                            case 0x9b:
                            *ptr = *ptr -1;
                            break;
                            case 0xbc:
                            *ptr = *ptr -1;
                            break;
                            case 0xba:
                            *ptr = *ptr -1;
                            break;
                            case 0x81:
                            *ptr = *ptr +1;
                            break;
                            case 0x83:
                            *ptr = *ptr +1;
                            break;
                            case 0x9a:
                            *ptr = *ptr +1;
                            break;
                            case 0xbb:
                            *ptr = *ptr +1;
                            break;
                            case 0xb9:
                            *ptr = *ptr +1;
                            break;
                      }
                   break;
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
