#include "data_type.h"
#include <limits.h>
#include <stdio.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

/* static powodouje, ze tablica data_type nie bedzie dostepna z innych bibliotek */
/* (gdybysmy chcieli, aby tablica byla dostepna, musiala by byc jej dekladaracja w pliku .h) */
static const char *data_type[7] = {"char", "short", "int", "long", "string", "float", "double"};


void datatype_info_char(char const *cptr) {
    fprintf(stdout, "(%s) %ld:%ld@%p = %c\n", data_type[0], (long)sizeof(*cptr), (long)(sizeof(*cptr) * CHAR_BIT), (void *) cptr, *cptr);
}

void datatype_info_short(short const *hptr) {
    fprintf(stdout, "(%s) %ld:%ld@%p = %hd\n", data_type[1], (long)sizeof(*hptr), (long)(sizeof(*hptr) * CHAR_BIT), (void *) hptr, *hptr);
}

void datatype_info_int(int const *iptr) {
    fprintf(stdout, "(%s) %ld:%ld@%p = %d\n", data_type[2], (long)sizeof(*iptr), (long)(sizeof(*iptr) * CHAR_BIT), (void *) iptr, *iptr);
}

void datatype_info_long(long const *lptr) {
    fprintf(stdout, "(%s) %ld:%ld@%p = %ld\n", data_type[3], (long)sizeof(*lptr), (long)(sizeof(*lptr) * CHAR_BIT), (void *) lptr, *lptr);
}

void datatype_info_str(char const *str) {
    fprintf(stdout, "(%s) %ld:%ld@%p = %s\n", data_type[4], (long)strlen(str), (long)(sizeof(str) * CHAR_BIT), (void *) str, str);
}

void datatype_info_float(float const *fptr) {
    fprintf(stdout, "(%s) %ld:%ld@%p = %f\n", data_type[5], (long)sizeof(*fptr), (long)(sizeof(*fptr) * CHAR_BIT), (void *) fptr, (double)(*fptr));
}

void datatype_info_double(double const *dptr) {
    fprintf(stdout, "(%s) %ld:%ld@%p = %f\n", data_type[6], (long)sizeof(*dptr), (long)(sizeof(*dptr) * CHAR_BIT), (void *) dptr, *dptr);
}

#ifdef __cplusplus
}
#endif
