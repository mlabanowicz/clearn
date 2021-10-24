
#ifndef GFXTXT_H__
#define GFXTXT_H__

#include <stdio.h> /* FILE */

#ifdef __cplusplus
extern "C" {
#endif

/* Utworz plan graficzny do rysowania, ktory ma podane wymiary, */
/* czyli ma 'height' lini, kazda o szerokosci 'width' znakow. */
void * GFXTXT_Create  (int width, int height);

/* Wyczysc plan graficzny podanym bajtem. */
int    GFXTXT_Clear   (void * handle, int byte);

/* Narysuj prostokat na planie graficznym o podanych wymiarach i podanym bajcie. */
int    GFXTXT_DrawRect(void * handle, int x, int y, int width, int height, int byte);

/* Wypelnij prostokat na planie graficznym o podanych wymiarach i podanym bajcie. */
int    GFXTXT_FillRect(void * handle, int x, int y, int width, int height, int byte);

/* Wyswietl plan graficzny do podanego pliku. */
/* Moze to byc przykladowo 'stdout', wtedy to caly 'obraz' zostanie wyswietlony na konsoli. */
int    GFXTXT_ToFile  (void * handle, FILE * file);

/* Zwolnij uzyte zasoby. */
void   GFXTXT_Destroy (void * handle);

#ifdef __cplusplus
}
#endif

#endif /* GFXTXT_H__ */
