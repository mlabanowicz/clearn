#include "02_sleep.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define CLOCKS_PER_MSEC 1000
#ifdef __cplusplus
extern "C" {
#endif
  int sleeps(int s){
	  
	 clock_t  end_t;
	 end_t = clock() + s *CLOCKS_PER_SEC;
	 while(end_t != clock()){}
	 return EXIT_SUCCESS;
  }
  int sleepms(int ms){
	  
	 clock_t end_t;
	 end_t = clock() + ms *CLOCKS_PER_MSEC;
	 while(end_t != clock()){}
	 return EXIT_SUCCESS;
  }

#ifdef __cplusplus
}
#endif