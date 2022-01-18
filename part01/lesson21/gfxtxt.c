
#include "gfxtxt.h"

#include <stdlib.h> /* malloc, free */
#include <string.h> /* memset */

#ifdef __cplusplus
extern "C" {
#endif

/* Struktura uzywana w tej implementacji      */
/* -------------------------------------      */
/* Zauwaz, ze ona nie jest potrzebna          */
/* w pliku h, czyli uzytkownik tego           */
/* modulu nie musi wiedziec, jak ona wyglada, */
/* wogole go to nie interesuje                */
typedef struct {
  int width;
  int height;
} gfxtxt_t;

void * GFXTXT_Create(int width, int height)
{
  gfxtxt_t * h = NULL;

  if (width > 0 && height > 0) {

    /* tylko wartosci dodatnie sa akceptowalne */

    h = (gfxtxt_t *)malloc(sizeof(*h) + width * height);
  }

  /**
   * Utworzony w pamieci obszar wyglada nastepujaco:
   *
   *  +-- h             +-- h + 1
   *  |                 |
   * \|/               \|/
   *  +-----------------+--------...--+--------...--+ ... +-------------...+
   *  | width  | height | line0       | line1       | ... | line(height-1) |
   *  +.................+--------...--+--------...--+ ... +-------------...+
   *  :    gfxtxt_t     : width bytes : width bytes :     :  width bytes   :
   *
   */

  /* !!! Adres struktury gfxtxt_t to h */

  /* !!! Adres line0 to kolejny bajt za h, czyli (h + 1) */
  /* {h jest typu (gfxtxt_t *), czyli adres sie przesunie o 1 * sizeof(gfxtxt_t)} */

  if (h) {

    h->width  = width;
    h->height = height;
  }

  return (void *)h;
}

int GFXTXT_Clear(void * handle, int byte)
{
  int result = -1;

  if (handle) {

    gfxtxt_t * h = (gfxtxt_t *)handle;

    memset(h + 1, byte, h->width * h->height);

    result = 0; /* success */
  }

  return result;
}

int GFXTXT_DrawRect(void * handle, int x, int y, int width, int height, int byte)
{
  int result = -1;

  if (handle && x >= 0 && y >= 0 && width > 0 && height > 0) {

    gfxtxt_t * h = (gfxtxt_t *)handle;

    if (x + width <= h->width && y + height <= h->height) {

      char * line = (char *)((void *)(h + 1));

      line += x + y * h->width;

      fprintf(stderr, "!!! GFXTXT_DrawRect !!! : Not completed\n");

      /* Ten kod robi dokladnie co FillRect, a nie powinien.        */
      /* Nalezy go zmodyfikowac tak, aby rysowal tylko obramowanie. */
      while (height--) {

        memset(line, byte, width);

        line += h->width;
      }

    }

  }

  return result;
}

int GFXTXT_FillRect(void * handle, int x, int y, int width, int height, int byte)
{
  int result = -1;

  if (handle && x >= 0 && y >= 0 && width > 0 && height > 0) {

    gfxtxt_t * h = (gfxtxt_t *)handle;

    if (x + width <= h->width && y + height <= h->height) {

      char * line = (char *)((void *)(h + 1));

      line += x + y * h->width;

      while (height--) {

        memset(line, byte, width);

        line += h->width;
      }

    }

  }

  return result;
}

int GFXTXT_ToFile(void * handle, FILE * file)
{
  int result = -1;

  if (handle && file) {

    gfxtxt_t * h = (gfxtxt_t *)handle;

    int i = h->height;

    /* ustal adres lini poczatkowej */
    char const * line = (char const *)((void const *)(h + 1));

    result = 0;

    while (!result && i--) {

               /* display line */                                           /* display end of line */
      result = (fwrite(line, 1, h->width, file) != ((size_t)(h->width))) || (putc('\n', file) == EOF);

      /* blad jest wtedy, gdy:
       *   a) nie udalo sie wyswietlic lini
       * lub:
       *   b) byl problem z wyswietleniem znaku konca lini
       */

      /* przesun pointer do nastepnej lini */
      line += h->width;
      /* {line jest typu (char const *), czyli adres sie przesunie o h->width * sizeof(char const)} */
    }
  }

  return result;
}

void GFXTXT_Destroy (void * handle)
{
  /* do free mozna podac NULL, tak wiec nie trzeba sprawdzac wskaznika */
  free(handle);
}

#ifdef __cplusplus
}
#endif
