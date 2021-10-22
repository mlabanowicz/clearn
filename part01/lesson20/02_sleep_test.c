#include <stdlib.h> /* EXIT_SUCCESS */

#include "02_sleep.h" /* suma_drukuj */
#include <time.h>
#include <stdio.h>
#ifdef __cplusplus
extern "C" {
#endif

int main(void)
{
	clock_t start_t,end_t;
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
		printf("program trwal:%.5f milisekund",roznica/ 1000);
	}
	else{
		start_t = clock();
		sleeps(time);
		roznica = difftime( clock(), start_t);
		printf("program trwal:%.5f sekund",roznica/1000000);
	}
  return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif