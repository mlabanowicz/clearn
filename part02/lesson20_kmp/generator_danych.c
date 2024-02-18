
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LITERA_MIN 'A'
#define LITERA_MAX 'Z'

#define DLUGOSC_KLUCZA 16
#define DLUGOSC_CIAGU 256

#define LITERA_CNT (LITERA_MAX - LITERA_MIN + 1)

int main(void)
{
  char klucz [DLUGOSC_KLUCZA + 1];
  char ciag [DLUGOSC_CIAGU + 1];
  int i = sizeof(klucz);
  int j;
  int ilosc_powtorzen =0;
  srand(time(NULL));

  klucz[--i] = '\0';

  while (i)
  {
    int r = rand();
    r %= LITERA_CNT;
    r += LITERA_MIN;
    klucz[--i] = r;
  }

  puts(klucz);


  i = sizeof(ciag);

  ciag[--i] = '\0';

  while (i)
  {
    int r;
    do{
    r = rand();
    r %= LITERA_CNT;
    r += LITERA_MIN;
    }while(r == klucz[0]); /*zabezpieczenie zeby klucz przypadkiem sie nie wygenerowal w ciagu*/
    ciag[--i] = r;
  }

  for(i =0;i<(int)sizeof(ciag)-(int)sizeof(klucz)+1;i++){
    int r = rand();
    if(r % 19 == 0){
      ilosc_powtorzen++;
      for(j=0;j<(int)sizeof(klucz)-1;j++){
        ciag[i] = klucz[j];
        i++;
      }
    }
  }

  puts(ciag);
  printf("%d\n",ilosc_powtorzen);

  return EXIT_SUCCESS;
}
