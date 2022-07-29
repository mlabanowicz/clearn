#include "data_type.h"
#include <stdlib.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

int main(void) {
    char a = 'a';
    char *aptr = &a;
    short b = 2;
    short *bptr = &b;
    int c = 3;
    int *cptr = &c;
    long d = 4;
    long *dptr = &d;
    char e[] = "test";
    char *eptr = &e[0];
    float f = 21.37;
    float *fptr = &f;
    double g = 100;
    double *gptr = &g;

    datatype_info_char(aptr);
    datatype_info_short(bptr);
    datatype_info_int(cptr);
    datatype_info_long(dptr);
    datatype_info_str(eptr);
    datatype_info_float(fptr);
    datatype_info_double(gptr);

    return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif
