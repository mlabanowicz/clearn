#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

int main(void) {

  int hours;
  int minutes;
  int seconds;
  
  int hourssum = 0;
  int minutessum = 0;
  int secsum = 0;
  
  while(1==1){
  int scanf_result = scanf("%02d:%02d:%02d", &hours, &minutes, &seconds);
  if (scanf_result == EOF) {

    fprintf(stderr, "LOG: Koniec danych");

    break;
  }
  if (scanf_result != 3) {

    fprintf(stderr, "LOG: Niepoprawne dane wejsciowe");

    return EXIT_FAILURE;
  }
    secsum += seconds;
    if(secsum >= 60){
      minutessum++;
      secsum -= 60;
      fprintf(stderr, "LOG: sekundy przekroczyly 60\n");
    }
    minutessum += minutes;
    if(minutessum >= 60){
      hourssum++;
      minutessum -= 60;
      fprintf(stderr, "LOG: minuty przekroczyly 60\n");
    }
    hourssum += hours;
    if(hourssum > 99){
        fprintf(stderr, "LOG: przokroczono maksymalną ilość godzin");
        return EXIT_FAILURE;
    }
  }

  printf("%02d:%02d:%02d\n", hourssum, minutessum, secsum);

  return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif
