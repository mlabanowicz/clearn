#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include <utils.h>

#ifdef __cplusplus
extern "C"
{
#endif
    void *UTILS_LoadFile(FILE *stream, size_t *size_ptr)
    {
        char   * buffer = NULL; /* Bufor wynikowy                  */
        size_t   length = 0;    /* Liczba bajtow uzytych w buforze */

        /* Odczytywanie danych ze strumienia, o ktorym nic nie wiemy,
         * mozna zrealizowac za pomoca fgetc */
        int c;

        while ((c = fgetc(stream)) != EOF) {

          /* OK, w strumieniu jest dodatkowy bajt, dodajmy go do wyjsciowego bufora: */

          void * ptr = realloc(buffer, length + 1);

          if (!ptr) {
            fprintf(stderr, "LOG:blad realokacji HEAP\n");
            free(buffer);
            exit(EXIT_FAILURE);
          }

          buffer = (char *)ptr; /* buffer ma teraz nowy adres, i jest wiekszy o 1 bajt */

          /* wrzucmy ten bajt na koniec tego bufora i pozniej
           * zwiekszmy zmienna 'length' przechowujaca jego rozmiar */
          buffer[length++] = (unsigned char)c;

        }

        /* *size_ptr jest to parametr, ktory powinien byc wypelniony przez ta funkcje */
        *size_ptr = length;

        return buffer;
    }

#ifdef __cplusplus
}
#endif
