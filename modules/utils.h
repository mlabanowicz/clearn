
#ifndef UTILS_H__
#define UTILS_H__

#include <stddef.h> /* size_t */
#include <stdio.h>  /* FILE   */

#ifdef __cplusplus
extern "C" {
#endif

/* Print some information about build date/time to specified FILE stream */
void UTILS_BuildInfo(FILE * stream);

/* Funkcja zaladuje wszystkie dane ze strumienia do bufora zaalokowanego w pamieci HEAP
 * Uzytkownik na koncu uzywania bufora powinien zwolnic ten bufor za pomoca free
 * Przyklad uzycia:
 * {
 *   void * buffer = NULL;
 *   size_t length = 0;
 *
 *   buffer = UTILS_LoadFile(stdin, &length);
 *
 *   if (buffer) {
 *
 *     printf("OK, zaladowano dane ze strumienia\n");
 *
 *     printf("Adres z danymi: %p\n", buffer);
 *     printf("Rozmiar danych: %lu bajtow\n", (unsigned long)length);
 *
 *     free(buffer);
 *
 *   } else {
 *
 *     fprintf(stderr, "Jakis blad, nie zaladowano danych !\n");
 *
 *   }
 * }
 */
void * UTILS_LoadFile(FILE * stream, size_t * size_ptr);

/* Funkcja wyswietli zawartosc danych o adresie data i rozmiarze size
 * w postacji zrzutu pamieci z linia o 16 bajtach.
 *
 * 1 kolumna: offset o rozmiarze 8 znakow,
 *            liczony od poczatku podanego adresu danych
 * 2 kolumna: 16 bajtow w systemie szesnastkowym
 * 3 kolumna: 16 bajtow w systemie znakowym, jezeli jakis znak
 *            znaki spoza zakresu 32..126 wyswietlane w postaci kropki.
 *
 * Gdy ostatnia linia nie jest pelna (size nie jest wyalognowany do 16),
 * wtedy w miejsca tych bajtow nalezy wpisac spacje.
 *
 * | <offset> | aa aa aa aa aa aa aa aa  bb bb bb bb bb bb bb bb | cccccccccccccccc |
 */
void UTILS_DumpData(FILE * output, void const * data, size_t size);

/* Funckja zwroci liczbe bitow ustawionych
 * na podanym obszarze pamieci
 *
 * Przykladowo, gdy pamiec wyglada tak (hex):
 * data = 00 01 02 03, size = 4 (bajty)
 * zwroci: 0 + 1 + 1 + 2 = 4 - bo tyle bitow jest ustawionych
 */
size_t UTILS_BitsCount(void const * data, size_t size);

#ifdef __cplusplus
}
#endif

#endif /* UTILS_H__ */
