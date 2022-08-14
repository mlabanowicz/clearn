#include "textdata.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#ifdef __cplusplus
extern "C"
{
#endif

textdata_line_t *TEXTDATA_LoadFile(FILE *f) {
	textdata_line_t *line = NULL;
	textdata_line_t *first_line = NULL;
	textdata_line_t *last_line = NULL;
	textdata_char_t *znak = NULL;
	textdata_char_t *last_char = NULL;
	int c = fgetc(f);
	while (1) {
		/*if dla pustego pliku */
		if (c == EOF) {
			break;
		}
		line = (textdata_line_t *) malloc(sizeof(textdata_line_t));
		if (!line) {
			fprintf(stderr, "Alloc failed!\n");
			exit(EXIT_FAILURE);
		}
		line->data = NULL;
		line->next = NULL;
/*ustawienie pierwszej lini */
		if (first_line) {
			last_line->next = line;
		} else {
			first_line = line;
		}
		while (1) {
			if (znak) {
				c = fgetc(f);
			}
			if (c == EOF) {
				break;
			}
/*tu mialem duzy problem ale znalazlem taka konfiguracje ktora dziala ale nie wiem dlaczego */
/*bez pobrania nastepnego znaku tworzy strukture dla \n */
/*a jesli dam w warunku \n to tworzy strukture dla \r, troche tego nie rozumiem */
			if (c == '\r') {
				c = fgetc(f);
				break;
			}

/*jesli linijka nie jest pusta lub jej nie ma mozna tworzyc chara */
			znak = (textdata_char_t *) malloc(sizeof(textdata_char_t));

			if (!znak) {
				fprintf(stderr, "Alloc failed!\n");
				exit(EXIT_FAILURE);
			}
			znak->c = (char) c;
			znak->next = NULL;
			if (last_char) {
				last_char->next = znak;
			} else {
				line->data = znak;
			}
			last_char = znak;
		}
		last_line = line;
		last_char = NULL;
	}
	return first_line;
}


void TEXTDATA_Free(textdata_line_t *textdata) {
	textdata_line_t *line = NULL;
	textdata_line_t *next_line = NULL;
	textdata_char_t *znak = NULL;
	textdata_char_t *last_znak = NULL;
	line = textdata;
	while (line != NULL) {
		next_line = line->next;
		znak = line->data;
		fprintf(stderr, "LOG: line@%p", (void *) line);
		while (znak != NULL) {
			last_znak = znak;
			fprintf(stderr, "-> char@%p=%2d'%c'", (void *) znak, (int) (znak->c),
							(znak->c >= ' ' && znak->c < SCHAR_MAX) ? znak->c : '.');
			znak = znak->next;
			free(last_znak);
		}
		fprintf(stderr, "\n");
		free(line);
		line = next_line;
    }
}

#ifdef __cplusplus
}
#endif
