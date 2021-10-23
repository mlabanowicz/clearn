<<<<<<< HEAD
#include <stdlib.h> 
#include "02_sleep.h" 
#include <time.h>
#include <stdio.h>
#define CLOCKS_PER_MSEC 1000
=======
#include <stdlib.h> /* EXIT_SUCCESS */

#include "02_sleep.h" /* suma_drukuj */
#include <time.h>
#include <stdio.h>
>>>>>>> fa989ed1e3762313c29eef47671490d5f0f0d38d
#ifdef __cplusplus
extern "C" {
#endif

int main(void)
{
<<<<<<< HEAD
	clock_t start_t;
=======
	clock_t start_t,end_t;
>>>>>>> fa989ed1e3762313c29eef47671490d5f0f0d38d
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
<<<<<<< HEAD
		fprintf(stderr,"LOG:program trwal:%.5f milisekund\n",roznica/ CLOCKS_PER_MSEC);
=======
		printf("program trwal:%.5f milisekund",roznica/ 1000);
>>>>>>> fa989ed1e3762313c29eef47671490d5f0f0d38d
	}
	else{
		start_t = clock();
		sleeps(time);
		roznica = difftime( clock(), start_t);
<<<<<<< HEAD
		fprintf(stderr,"LOG:program trwal:%.5f sekund\n",roznica/ CLOCKS_PER_SEC);
=======
		printf("program trwal:%.5f sekund",roznica/1000000);
>>>>>>> fa989ed1e3762313c29eef47671490d5f0f0d38d
	}
  return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
<<<<<<< HEAD
#endif
=======
#endif
>>>>>>> fa989ed1e3762313c29eef47671490d5f0f0d38d
