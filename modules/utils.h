
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

#ifdef __cplusplus
}
#endif

#endif /* UTILS_H__ */
