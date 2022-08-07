
#include "textdata.h"

#include <limits.h>

#ifdef __cplusplus
extern "C" {
#endif

void TEXTDATA_Dump(textdata_line_t const * first_line, FILE * f) {

  textdata_line_t const * line = first_line;

  int line_id = 0;

  while (line) {

    char const * next = " =";

    textdata_char_t const * znak = line->data;

    ++line_id;

    fprintf(f, "%02d: line@%p", line_id, (void *)line);

    while (znak) {

      fprintf(f, "%s char@%p=%2d'%c'", next, (void *)znak, (int)(znak->c),
        (znak->c >= ' ' && znak->c < SCHAR_MAX) ? znak->c : '.'
      );

      znak = znak->next;

      next = " ->";
    }

    fprintf(f, "\n");

    line = line->next;
  }
}

#ifdef __cplusplus
}
#endif
