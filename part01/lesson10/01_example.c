/**
 * Program, ktory wypisuje podane wyrazy od konca.
 * Implementacja wraz z opisem oparta na wskaznikach.
 */

#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

int main(void) {

  /* Zarezerwowanie w pamieci tablicy              */
  /* o rozmiarze 21 bajtow.                        */
  /* Przyklad jak to moze wygladac w pamieci:      */
  /*  0                  10                    20  */
  /* +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ */
  /* |.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.| */
  /* +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ */
  /*   \                                           */
  /*   &wyraz = 0x12345678 (przykladowy adres)     */
  /*    (wskazuje na zerowy element w tablicy)     */

  char wyraz [20 + 1];

  /* Wypisanie na console adresu tablicy wyraz */
  fprintf(stderr, "LOG: adres wyraz = %p\n", (void *)(wyraz));
  /* w przykladzie powinein wypisac: 0x12345678 */

  /* Wypisanie na console adresu zerowego elementu tablicy wyraz */
  fprintf(stderr, "LOG: adres wyraz[0] = %p\n", (void *)(&wyraz[0]));
  /* w przykladzie powinein wypisac: 0x12345678 */

  /* Wypisanie na console adresu drugiego elementu tablicy wyraz */
  fprintf(stderr, "LOG: adres wyraz[2] = %p\n", (void *)(&wyraz[2]));
  /* w przykladzie powinien wypisac: 0x1234567A */

  while (scanf("%s", wyraz) == 1) {

    /* Gdy udalo sie wczytac wyraz z stdin,           */
    /* przyklad: "lokomotywa"                         */

    /*  0                   10                    20  */
    /* +-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+ */
    /* |l|o|k|o|m|o|t|y|w|a|\0|.|.|.|.|.|.|.|.|.|.|.| */
    /* +-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+ */
    /*   \                                            */
    /*   &wyraz = 0x12345678                          */

    /* Zadeklaruj wskaznik w pamieci i wpisz do niego */
    /* adres zerowego elementu tablicy.               */
    /* Przyklad, jak to moze wygladac w pamieci:      */

    /* +--+--+--+--+                                  */
    /* |12|34|56|78|                                  */
    /* +--+--+--+--+                                  */
    /*   \                                            */
    /*   &p = 0x98765432 (adres zmiennej p)           */

    char * p = wyraz;

    /* Wypisanie na console adresu zmiennej p */
    fprintf(stderr, "LOG: adres zmiennej p = %p\n", (void *)(&p));
    /* w przykladzie powinien wypisac: 0x98765432 */

    /* Wypisanie na console wartosci zmiennej p */
    fprintf(stderr, "LOG: wartosc zmiennej p = %p\n", (void *)(p));
    /* w przykladzie powinien wypisac: 0x12345678 */

    /* Wypisanie na console znaku, znajdujacego */
    /* sie pod adresem, ktory jest w zmiennej p (0x12345678) */
    fprintf(stderr, "LOG: *p = '%c'\n", *p);
    /* powinien wypisac: 'l' */

    /* Mozna sobie wyobrazic, ze p wskazuje na zerowy */
    /* element w tablicy.                             */
    /*  0                   10                    20  */
    /* +-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+ */
    /* |l|o|k|o|m|o|t|y|w|a|\0|.|.|.|.|.|.|.|.|.|.|.| */
    /* +-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+ */
    /*   \                                            */
    /*    p = 0x12345678                              */

    /* Wartosc zmiennej p mozna modyfikowac           */
    /* zwyklymi operacjami arytmetycznymi.            */
    /* Przesuwamy sie do konca napisu                 */
    /* (czyli do znalezienia znaku '\0')              */

    while (1 == 1) { /* petla nieskonczona, jedyna
                        mozliowsc wyjscia to 'break' */

      /* Jezeli wskaznik wskazuje na znak, ktory zawiera '\0' to wyjdz z petli */
      if (*p == '\0') {
        break;
      }

      /* Jezeli nie, to zwieksz wskaznik o 1     */
      /* (przesun sie w tablicy o jeden element) */

      p += 1;

      /* W przykladzie, po pierwszej iteracji tej petli */
      /* p bedzie wskazywac na kolejny el. w tablicy    */
      /*  0                   10                    20  */
      /* +-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+ */
      /* |l|o|k|o|m|o|t|y|w|a|\0|.|.|.|.|.|.|.|.|.|.|.| */
      /* +-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+ */
      /*     \                                          */
      /*      p = 0x12345679                            */
    }

    /* Po wyjsciu z tablicy p bedzie wskazywac na znak '\0' */
    /*  0                   10                    20  */
    /* +-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+ */
    /* |l|o|k|o|m|o|t|y|w|a|\0|.|.|.|.|.|.|.|.|.|.|.| */
    /* +-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+ */
    /*                       \                        */
    /*                        p = 0x12345681          */

    /* Wypisywanie znakow od ostatniego elementu: */
    while (1 == 1) { /* petla nieskonczona, jedyna
                        mozliowsc wyjscia to 'break' */

      /* Jezeli wskaznik wskazuje na poczatek tablicy wyraz, */
      /* to zakoncz petle */
      if (p == wyraz) {
        break;
      }

      /* Jezeli nie, to: */
      /* cofnij wskaznik o jeden element */

      p -= 1;

      /* W przykladzie, po pierwszej iteracji tej petli:*/
      /*  0                   10                    20  */
      /* +-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+ */
      /* |l|o|k|o|m|o|t|y|w|a|\0|.|.|.|.|.|.|.|.|.|.|.| */
      /* +-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+ */
      /*                     \                          */
      /*                      p = 0x12345680            */

      /* wypisz znak wskazywany przez p na stdout */
      putchar(*p);

      /* kontynuuj petle */
    }

    /* Wyswietl jeszcze znak nowej lini */
    puts("");
  }

  /* Prosze zuwazyc, ze w programie rzeczywista      */
  /* wartosc adresow, ktora jest zalezna od systemu, */
  /* nie jest wogole istotna, ona moze sluzyc dla    */
  /* programisty w celu zorientowania sie, jakie sa  */
  /* wartosci wskaznikow, ale do dzialania programu  */
  /* nie ma znaczenia.                               */

  return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif
