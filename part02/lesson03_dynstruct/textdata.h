
#ifndef TEXTDATA_H__
#define TEXTDATA_H__

#include <stdio.h> /* FILE */

#ifdef __cplusplus
extern"C" {
#endif

typedef struct textdata_char_s textdata_char_t;

struct textdata_char_s {
  char              c;
  textdata_char_t * next;
};

typedef struct textdata_line_s textdata_line_t;

struct textdata_line_s {
  textdata_char_t * data;
  textdata_line_t * next;
};

/* creates text data structure in HEAP */
textdata_line_t * TEXTDATA_LoadFile(FILE * f);

/* Dump structure to file */
void TEXTDATA_Dump(textdata_line_t const * first_line, FILE * f);

/* destroy text data structure from HEAP */
void TEXTDATA_Free(textdata_line_t * textdata);

#ifdef __cplusplus
}
#endif

#endif /* TEXTDATA_H__ */

