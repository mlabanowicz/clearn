#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif
	int main(void) {		
		unsigned char letter;
		unsigned char secletter;
		unsigned char * ptr = &letter;
		unsigned char * secptr = &secletter;
		while(scanf("%c",ptr) != EOF){
			switch(*ptr){
				case 0x85 :
					*ptr = *ptr -1;
					break;
				case 0x84 :
					if(*secptr == 0xc4){
						*ptr = *ptr +1;
					}
					else{
						*ptr = *ptr -1;
					}
					break;
				case 0x87 :
					*ptr = *ptr -1;
					break;
				case 0x99 :
					*ptr = *ptr -1;
					break;
				case 0x82 :
					*ptr = *ptr -1;
					break;
				case 0xb3 :
					*ptr = 0x93;
					break;
				case 0x9b :
					*ptr = *ptr-1;
					break;
				case 0xbc :
					*ptr = *ptr-1;
					break;
				case 0x86 :
					*ptr = *ptr+1;
					break;
				case 0x98 :
					*ptr = *ptr+1;
					break;
				case 0x81 :
					*ptr = *ptr+1;
					break;
				case 0x93 :
					*ptr = 0xb3;
					break;
				case 0x9a :
					*ptr = *ptr+1;
					break;
				case 0xbb :
					*ptr = *ptr+1;
					break;
				case 0xb9 :
					*ptr = *ptr+1;
					break;	
				default :
					if(*ptr >= 65 && *ptr <= 90){
						*ptr = *ptr + 32;
					}
					else{
						if(*ptr>=97 && *ptr <= 122){
						*ptr = *ptr-32;
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
