#include "data_type.h"
#include <limits.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif
const char *data_type[7] = {"char", "short", "int", "long", "string", "float", "double"};


void datatype_info_char(char const *cptr) {
    fprintf(stdout, "(%s) %ld:%ld@%p = %c\n", data_type[0], sizeof(*cptr), sizeof(*cptr) * 8, (void *) cptr, *cptr);
}

void datatype_info_short(short const *hptr) {
    fprintf(stdout, "(%s) %ld:%ld@%p = %d\n", data_type[1], sizeof(*hptr), sizeof(*hptr) * 8, (void *) hptr, *hptr);
}

void datatype_info_int(int const *iptr) {
    fprintf(stdout, "(%s) %ld:%ld@%p = %d\n", data_type[2], sizeof(*iptr), sizeof(*iptr) * 8, (void *) iptr, *iptr);
}

void datatype_info_long(long const *lptr) {
    fprintf(stdout, "(%s) %ld:%ld@%p = %ld\n", data_type[3], sizeof(*lptr), sizeof(*lptr) * 8, (void *) lptr, *lptr);
}

void datatype_info_str(char const *str) {
    fprintf(stdout, "(%s) %ld:%ld@%p = %s\n", data_type[4], sizeof(str), sizeof(str) * CHAR_BIT, (void *) str, str);
}

void datatype_info_float(float const *fptr) {
    fprintf(stdout, "(%s) %ld:%ld@%p = %f\n", data_type[5], sizeof(*fptr), sizeof(*fptr) * 8, (void *) fptr, *fptr);
}

void datatype_info_double(double const *dptr) {
    fprintf(stdout, "(%s) %ld:%ld@%p = %f\n", data_type[6], sizeof(*dptr), sizeof(*dptr) * 8, (void *) dptr, *dptr);
}

#ifdef __cplusplus
}
#endif
