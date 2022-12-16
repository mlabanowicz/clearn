
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Element struktury BST : */

struct data_type_s
{
  /* zawartosc jednego elementu, przykladowo 1 int  */
  int value;

  /* wskaznik na rodzica (root bedzie mial tutaj wartosc NULL) */
  struct data_type_s *parent;

  /* wskaznik na dziecko z lewej strony, to oznacza, ze lewe dziecko musi byc <= od obecnego */
  /* jezlei nie ma lewego dziecka, to musi tu byc NULL */
  struct data_type_s *left;

  /* wskaznik na dziecko z prawej strony, to oznacza, ze prawe dziecko musi byc >= od obecnego */
  /* jezlei nie ma prawego dziecka, to musi tu byc NULL */
  struct data_type_s *right;
};

/* zwarca true, jezeli a < b */
static int isLess(struct data_type_s const * a, struct data_type_s const * b)
{
  return a->value < b->value;
}

/* Dodaje nowy element do struktury BST */
/* Zwraca nowy root (o ile sie zmienil) */
static struct data_type_s * addElementToBst(struct data_type_s * root, struct data_type_s * element)
{
  /* do zaimplementowania */

  /* W strukturze wskazywanej przez element ta funkcja powinna poustawiac */
  /* pola parent, left i right na odpowiednie wartosci. */

  /* Do porownywnaian, ktory elemnt jest wiekszy/mmniejszy funkcja ma uzywac tylko funkcji isLess */
}

int main(void)
{
  struct data_type_s * root = NULL;

  struct data_type_s a, b, c, d;

  a.value = 3;
  b.value = 5;
  c.value = 1;
  d.value = 4;

  /* Na samym poczatku root jest NULL, drzewo ma 0 elementow */

  root = addElementToBst(root, &a);

  /* Po dodaniu pierwszego elementu, root powinien wskazywac na element a, cale drzewo ma 1 element: */
  /*                                                 */
  /*  root --> &a                                    */
  /*                                                 */
  /*  a    === (3,parent=NULL,left=NULL,right=NULL)  */
  /*                                                 */
  /*                  [a:3]                          */
  /*                                                 */

  root = addElementToBst(root, &b);

  /* Po dodaniu drugiego elemntu, root sie juz nie zmienia, zaczyna on wskazywac na dziecko b: */
  /* dziecko b pojawia sie z prawej strony a, poniewaz a < b */
  /*                                                 */
  /*  root --> &a                                    */
  /*                                                 */
  /*  a    === (3,parent=NULL,left=NULL,right=&b)    */
  /*                                                 */
  /*  b    === (5,parent=&a,left=NULL,right=NULL)    */
  /*                                                 */
  /*                  [a:3]                          */
  /*                       \                         */
  /*                        \                        */
  /*                        [b:5]                    */
  /*                                                 */

  root = addElementToBst(root, &c);

  /* Po dodaniu trzeciego elemntu:                   */
  /*                                                 */
  /*  root --> &a                                    */
  /*                                                 */
  /*  a    === (3,parent=NULL,left=&c,right=&b)      */
  /*                                                 */
  /*  b    === (5,parent=&a,left=NULL,right=NULL)    */
  /*                                                 */
  /*  c    === (1,parent=&a,left=NULL,right=NULL)    */
  /*                                                 */
  /*                  [a:3]                          */
  /*                 /     \                         */
  /*                /       \                        */
  /*            [c:1]       [b:5]                    */
  /*                                                 */

  root = addElementToBst(root, &d);

  /* Po dodaniu czwartego elemntu:                   */
  /*                                                 */
  /*  root --> &a                                    */
  /*                                                 */
  /*  a    === (3,parent=NULL,left=&c,right=&b)      */
  /*                                                 */
  /*  b    === (5,parent=&a,left=&d,right=NULL)      */
  /*                                                 */
  /*  c    === (1,parent=&a,left=NULL,right=NULL)    */
  /*                                                 */
  /*  d    === (4,parent=&b,left=NULL,right=NULL)    */
  /*                                                 */
  /*                  [a:3]                          */
  /*                 /     \                         */
  /*                /       \                        */
  /*            [c:1]       [b:5]                    */
  /*                         /                       */
  /*                        /                        */
  /*                     [d:4]                       */
  /*                                                 */

  return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif
