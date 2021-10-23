#include "02_sleep.h" 
#include <stdlib.h> 
#include <time.h>
#include <stdio.h>
#define CLOCKS_PER_MSEC 1000
#ifdef __cplusplus
extern "C" {
#endif

int main(void)
{
	clock_t start_t;
	double roznica;
	int i;
	int time;
	printf("milisekundy-1 sekundy-2\n");
	scanf("%d",&i);
	printf("czas trwania:\n");
	scanf("%d",&time);
	if(i==1){
		start_t = clock();
		sleepms(time);
		roznica = difftime( clock(), start_t);
		fprintf(stderr,"LOG:program trwal:%.5f milisekund\n",roznica/ CLOCKS_PER_MSEC);
	}
	else{
		start_t = clock();
		sleeps(time);
		roznica = difftime( clock(), start_t);
		fprintf(stderr,"LOG:program trwal:%.5f sekund\n",roznica/ CLOCKS_PER_SEC);
	}
  return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif
