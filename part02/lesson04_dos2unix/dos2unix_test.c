#include "stdlib.h"
#include <stdio.h>
#include <limits.h>

#ifdef __cplusplus
extern "C" {
#endif

int main(void) {
    FILE *fp_in = NULL, *fp_out = NULL;
    int c, last_c = 0;
    char *filepath_in = "input.txt", *filepath_out = "output.txt";
    if ((fp_in = fopen(filepath_in, "rb")) == NULL) {
        printf("Nie mogę otworzyć pliku input.txt do odczytu!\n");
        exit(EXIT_FAILURE);
    }
    if ((fp_out = fopen(filepath_out, "rb")) == NULL) {
        printf("Nie mogę otworzyć pliku output.txt do odczytu!\n");
        exit(EXIT_FAILURE);
    }
    c = fgetc(fp_in);
    printf("~~~~~~~~INPUT FILE~~~~~~~~\n\n%d = %c\n", c, (c >= ' ' && c < SCHAR_MAX) ? c : '.');
    while (c != EOF) {
        c = fgetc(fp_in);
        printf("%d = %c\n", c, (c >= ' ' && c < SCHAR_MAX) ? c : '.');
    }
    c = fgetc(fp_out);
    printf("~~~~~~~~OUTPUT FILE~~~~~~~~\n\n%d = %c\n", c, (c >= ' ' && c < SCHAR_MAX) ? c : '.');
    while (c != EOF) {
        c = fgetc(fp_out);
        printf("%d = %c", c, (c >= ' ' && c < SCHAR_MAX) ? c : '.');
        if (last_c == 13 && c == 10) {
            printf(" <-------- LINIA W TRYBIE DOS");
        }
        printf("\n");
        last_c = c;
    }
    fclose(fp_in);
    fclose(fp_out);
    return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif
