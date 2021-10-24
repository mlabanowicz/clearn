#include "02_sleep.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define CLOCKS_PER_MSEC CLOCKS_PER_SEC/1000
#ifdef __cplusplus
extern "C" {
#endif
  int sleeps(int s){
	  
	 clock_t  endtime;
	 endtime = clock() + s *CLOCKS_PER_SEC;
	 while(endtime != clock()){}
	 return EXIT_SUCCESS;
  }
  int sleepms(int ms){
	  
	 clock_t endtime;
	 endtime = clock() + ms *CLOCKS_PER_MSEC;
	 while(endtime != clock()){}
	 return EXIT_SUCCESS;
  }

#ifdef __cplusplus
}
#endif