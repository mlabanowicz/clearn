/**
 * Program wczutuje godziny, minuty i sekundy, i je wyswietla
 */

#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

int main(void) {

  int hours;
  int minutes;
  int seconds;

  if (scanf("%02d:%02d:%02d", &hours, &minutes, &seconds) != 3) {

    fprintf(stderr, "LOG: Niepoprawne dane wejsciowe");

    return EXIT_FAILURE;
  }

  printf("%02d:%02d:%02d\n", hours, minutes, seconds);

  return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif
