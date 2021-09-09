#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#ifdef __cplusplus
extern "C" {
#endif

int jednosci(int length, char num1, char num2);

int dziesiatek(char num1,char num2);

int setek(char num);

int jednosci(int length, char num1, char num2)
{
	switch(num1)
	{
		case '1':
			switch(num2){
				case '0':
					printf("dzie");
					break;
				case '1':
					printf("jede");
					break;
				default:
					printf("jeden" );
					break;
			}
			break;
		case '2' :
			printf("dwa");
			break;
		case '3' :
			printf("trzy");
			break;
		case '4' :
			switch(length){
				case 2:
					printf("czter");
					break;
				default:
					printf("cztery" );
					break;
			}
			break;
		case '5' :
			switch(num2){
				case '1':
					printf("piet");
					break;
				default:
					printf("piec" );
					break;
			}
			break;
		case '6' :
			switch(num2){
				case '1':
					printf("szes");
					break;
				default:
					printf("szesc" );
					break;
			}
			break;
		case '7' :
			printf("siedem");
			break;
		case '8' :
			printf("osiem");
			break;
		case '9' :
			switch(num2){
				case '1':
					printf("dziewiet");
					break;
				default:
					printf("dziewiec" );
					break;
			}
			break;
		case '0' :
			if(num2== 'c'){
				printf("zero");
			}
			break;
	}
	return EXIT_SUCCESS;
}
int dziesiatek(char num1,char num2)
{
	switch(num1)
	{
		case '1':
			switch(num2){
				case '0':
					printf("dziesiec ");
					break;
				default:
					printf("nascie " );
					break;
			}
			break;
		case '2' :
			printf("dziescia ");
			break;
		case '3' :
			printf("dziesci ");
			break;
		case '4' :
			printf("dziesci ");
			break;
		case '0' :
			break;
		default:
			printf("dziesiat " );
			break;
	
	}
	return EXIT_SUCCESS;
}

int setek(char num)
{
	switch(num)
	{
		case '0':
			break;
		case '1':
			printf("sto ");
			break;
		case '2' :
			printf("scie ");
			break;
		case '3' :
			printf("sta ");
			break;
		case '4' :
			printf("sta ");
			break;
		default:
			printf("set " );
			break;
	
	}
	return EXIT_SUCCESS;
}





int main(void) {
	int length;
	char num[5]="xxxx";
	char *ptr = &num[0];
	while(scanf("%s",ptr)!= EOF){
		length = strlen(ptr);
		fprintf(stderr,"\nLOG:\ndlugosc liczby:%d\nliczba:%s\nptr[0]=%c\nptr[1]=%c\nptr[2]=%c\nptr[3]=%c\n\n", length, ptr,ptr[0],ptr[1],ptr[2],ptr[3]);
		if(length == 1){
			jednosci(length,ptr[0],'c');
		}
		if(length == 2){
			if(ptr[0] == '1'){
				jednosci(length,ptr[1],ptr[0]);
				dziesiatek(ptr[0],ptr[1]);
			}
			else{
				jednosci(length,ptr[0],'b');
				dziesiatek(ptr[0],ptr[1]);
				jednosci(length-1,ptr[1],'b');
			}
		}
		if(length == 3){
			if(ptr[0] == '1'){
				setek(ptr[0]);
			}
			else{
				jednosci(length,ptr[0],'b');
				setek(ptr[0]);
			}
			if(ptr[1]=='1'){
				jednosci(length-1,ptr[2],ptr[1]);
				dziesiatek(ptr[1],ptr[2]);		
			}
			else{
				jednosci(length-1,ptr[1],'b');
				dziesiatek(ptr[1],ptr[2]);
				jednosci(length-2,ptr[2],'b');				
			}
		}
		if(length == 4){
			printf("tysiac");
		}
	}
  return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif
