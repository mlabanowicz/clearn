#include "stdlib.h"
#include <stdio.h>
#include <limits.h>

#ifdef __cplusplus
extern "C" {
#endif

int main(void) {
    FILE *fp_in = NULL, *fp_out = NULL;
    int c, next_c = 0;
    char *filepath_in = "input.txt", *filepath_out = "output.txt";
    if ((fp_in = fopen(filepath_in, "rb")) == NULL) {
        fprintf(stderr,"Nie mogę otworzyć pliku input.txt do odczytu!\n");
        exit(EXIT_FAILURE);
    }
    if ((fp_out = fopen(filepath_out, "wb")) == NULL) {
        fprintf(stderr,"Nie mogę otworzyć pliku output.txt do odczytu!\n");
        exit(EXIT_FAILURE);
    }
    c = fgetc(fp_in);
    if(c != EOF){
        next_c = fgetc(fp_in);;
    }
    while (c != EOF) {
        if (c != 13 || next_c != 10) {
            fputc(c, fp_out);
        }
        c = next_c;
        if(c == EOF){
            break;
        }
        next_c = fgetc(fp_in);
    }
    fclose(fp_out);
    fclose(fp_in);
    return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif

