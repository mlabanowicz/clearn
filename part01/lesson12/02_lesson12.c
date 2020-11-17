#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#ifdef __cplusplus
extern "C" {
#endif

int main(void) {
  char znak;
  int result=0;
  int lengthstring;
  char * tablica_on_heap = NULL;
  if (tablica_on_heap == NULL) {
    fprintf(stderr, "LOG: wskaznik ma wartosc NULL, wskazuje na nic :) !\n");
  }
  
  tablica_on_heap = (char *)malloc(123456);

  if (tablica_on_heap != NULL) {
    fprintf(stderr, "LOG: Udalo sie zarezerwowac obszar 123456 bajtow !\n");
    fprintf(stderr, "LOG: Mozemy z niego korzystac !\n");
    int scanf_result = scanf("%d %s %c",&lengthstring,tablica_on_heap, &znak );
    int dlugosc = strlen(tablica_on_heap);
    if(dlugosc != lengthstring){
      fprintf(stderr,"LOG: Podana długość jest różna od autentycznej");
      return EXIT_FAILURE;
    }
    if( scanf_result != 3){
      fprintf(stderr,"LOG: Błędne dane!");
      return EXIT_FAILURE;
    }
      while(lengthstring != 0){
        if(tablica_on_heap[lengthstring] == znak)
          result++;
          lengthstring--;
      }

    fprintf(stderr, "LOG: Zwalnianie zaaolokawengo wczesniej obszaru na HEAP'ie : %p\n", (void *)tablica_on_heap);
    free(tablica_on_heap);
    printf("%d\n", result);
  }
  return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif
