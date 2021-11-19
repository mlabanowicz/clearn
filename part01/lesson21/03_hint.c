
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

#define WIDTH  10
#define HEIGHT  5

int main(void)
{
  char plan_graficzny [WIDTH * HEIGHT];

  /* Wypelnienie planu graficznego znakami '-' */
  memset(plan_graficzny, '-', sizeof(plan_graficzny));

  /* nasz plan graficzny sklada sie z 5 lini po 10 znakow */
  /*
   * { '-','-','-','-','-','-','-','-','-','-',
   *   '-','-','-','-','-','-','-','-','-','-',
   *   '-','-','-','-','-','-','-','-','-','-',
   *   '-','-','-','-','-','-','-','-','-','-',
   *   '-','-','-','-','-','-','-','-','-','-'  }
   */

  fprintf(stderr, "linia 0 -> adres = %p\n", (void *)(plan_graficzny + (0 * WIDTH)));
  fprintf(stderr, "linia 1 -> adres = %p\n", (void *)(plan_graficzny + (1 * WIDTH)));
  fprintf(stderr, "linia 2 -> adres = %p\n", (void *)(plan_graficzny + (2 * WIDTH)));
  fprintf(stderr, "linia 3 -> adres = %p\n", (void *)(plan_graficzny + (3 * WIDTH)));
  fprintf(stderr, "linia 4 -> adres = %p\n", (void *)(plan_graficzny + (4 * WIDTH)));

  /* wyswietlenie zawartosci planu graficznego na konsole,
   * czyli wyswietlenie kazdej lini plus znak nowej lini */
  fwrite(plan_graficzny + (0 * WIDTH), 1, WIDTH, stdout);puts("");
  fwrite(plan_graficzny + (1 * WIDTH), 1, WIDTH, stdout);puts("");
  fwrite(plan_graficzny + (2 * WIDTH), 1, WIDTH, stdout);puts("");
  fwrite(plan_graficzny + (3 * WIDTH), 1, WIDTH, stdout);puts("");
  fwrite(plan_graficzny + (4 * WIDTH), 1, WIDTH, stdout);puts("");
  /* Na ekranie pojawi sie:
----------
----------
----------
----------
----------
*/

  printf("Rysowanie prostokata\n");
  {
    /* !!TODO!! */
    /* Narysuj prostokat w tablicy 'plan_graficzny' za pomoca znaku '@',
     * czyli wypelnij komorki odpowiednich bajtow w tej tablicy,
     * aby jej zawartosc wygladala tak jak ponizej.
     * !!! Prosze tylko odpowiednio wypelnic elementy tablicy,
     * !!! wyswietlenie tej tablicy jest juz zrobione jako
     * !!! kolejny krok tego programu.
----------
-@@@@@@@--
-@-----@--
-@-----@--
-@@@@@@@--
*/
  }

  /* wyswietlenie zawartosci planu graficznego na konsole */
  fwrite(plan_graficzny + (0 * WIDTH), 1, WIDTH, stdout);puts("");
  fwrite(plan_graficzny + (1 * WIDTH), 1, WIDTH, stdout);puts("");
  fwrite(plan_graficzny + (2 * WIDTH), 1, WIDTH, stdout);puts("");
  fwrite(plan_graficzny + (3 * WIDTH), 1, WIDTH, stdout);puts("");
  fwrite(plan_graficzny + (4 * WIDTH), 1, WIDTH, stdout);puts("");

  return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif
