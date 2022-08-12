#include "textdata.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

int main(void) {
    FILE *fp;
    textdata_line_t *line = NULL;
    textdata_line_t *first_line = NULL;
    textdata_char_t *znak = NULL;
    textdata_char_t *last_znak = NULL;
    if ((fp = fopen("data.txt", "r")) == NULL) {
        printf("Nie mogę otworzyć pliku test.txt do odczytu!\n");
        exit(1);
    }
    while (1) {
        if (first_line) { line = line->next; }
        else{
            line = TEXTDATA_LoadFile(fp);
            TEXTDATA_Dump(line, stderr);
            first_line = line;
			if(line == NULL){
				fprintf(stderr, "LOG: plik pusty!");
				break;
			}
        }
        znak = line->data;
        while (znak != NULL) {
            last_znak = znak;
            znak = znak->next;
			printf("%c", last_znak->c);
        }
		printf("\n");
        if(line->next == NULL)  break;
    }

    TEXTDATA_Free(first_line);
    fclose(fp);
    return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif
