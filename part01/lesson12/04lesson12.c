#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#ifdef __cplusplus
extern "C" {
#endif

int main(void) {
  char znak;
  int result=0;
  int dlugoscnapisu;
  char * tablica_on_heap = NULL;
  if (tablica_on_heap == NULL) {
    fprintf(stderr, "LOG: wskaznik ma wartosc NULL, wskazuje na nic :) !\n");
  }
  if (scanf("%d", &dlugoscnapisu) != 1){
    fprintf(stderr,"LOG: Błędne dane!");
    return EXIT_FAILURE;
  }
  tablica_on_heap = (char *)malloc(dlugoscnapisu+1);

  if (tablica_on_heap != NULL) {
    fprintf(stderr, "LOG: Udalo sie zarezerwowac obszar %d bajtow !\n", dlugoscnapisu+1);
    fprintf(stderr, "LOG: Mozemy z niego korzystac !\n");
    int scanf_result = scanf("%s %c",tablica_on_heap, &znak );
    int dlugosc = strlen(tablica_on_heap);
    if(dlugosc != dlugoscnapisu){
      fprintf(stderr,"LOG: Podana długość jest różna od autentycznej\nAutentyczna=%d\nPodana=%d",dlugosc, dlugoscnapisu);
      return EXIT_FAILURE;
    }
    if( scanf_result != 2){
      fprintf(stderr,"LOG: Błędne dane!");
      return EXIT_FAILURE;
    }
      while(dlugoscnapisu != 0){
        if(tablica_on_heap[dlugoscnapisu] == znak){
          result++;
        }
        dlugoscnapisu--;
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
