#include "textdata.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

textdata_line_t *TEXTDATA_LoadFile(FILE *f) {
    textdata_line_t *line = NULL;
    textdata_line_t *first_line = NULL;
    textdata_line_t *last_line = NULL;
    textdata_char_t *znak = NULL;
    textdata_char_t *last_char = NULL;

    while(1) {

        line = (textdata_line_t *) malloc(sizeof(textdata_line_t));
        if (!line) {
            fprintf(stderr, "Alloc failed!\n");
            exit(EXIT_FAILURE);
        }

        line->data = NULL;
        line->next = NULL;
        if(first_line){
            last_line->next = line;
            last_char = NULL;
        }
        else{
            first_line = line;
        }
        last_line = line;
        while (1) {
            znak = (textdata_char_t *) malloc(sizeof(textdata_char_t));

            if (!znak) {
                fprintf(stderr, "Alloc failed!\n");
                exit(EXIT_FAILURE);
            }

            if (last_char) {
                last_char->next = znak;
            } else {
                line->data = znak;
            }
            last_char = znak;
            znak->next = NULL;
            if ((znak->c = fgetc(f)) == '\n') break;
            if(znak->c == EOF)  break;
        }
        if(znak->c == EOF)  break;
    }
    return first_line;
}


void TEXTDATA_Free(textdata_line_t *textdata) {
    textdata_line_t *line = NULL;
    textdata_line_t *next_line = NULL;
    textdata_char_t *znak = NULL;
    textdata_char_t *last_znak = NULL;
    while (1 == 1) {
        if(next_line){
            line = next_line;
        }
        else{
            line = textdata;
        }
        line->next = next_line;
        znak = line->data;
        while (1 == 1) {
            last_znak = znak;
            znak = znak->next;
            if (last_znak->next == NULL) break;
            free(last_znak);
        }
        free(last_znak);
        free(line);
        if(next_line == NULL)   break;
    }
}

#ifdef __cplusplus
}
#endif