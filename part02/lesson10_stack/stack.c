
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C"
{
#endif

  /* struktura wykorzystujaca hierarchie stosu: */

  struct data_type_s
  {
    /* zawartosc jednego elementu, przykladowo 2 inty  */
    int x, y;

    /* wskaznik na element poprzedni */
    struct data_type_s *prev;
  };

  /* funkcja usuwa element ze stosu, zwraca nowy top (o ile sie zmienil, bo moze zwrocic stary) */
  static struct data_type_s *RemoveStackElement(struct data_type_s *top, struct data_type_s *element)
  {
    struct data_type_s *i = top;
    struct data_type_s *j = top->prev;
    if (top)
    {
      if (i == element)
      {
        top = j;
      }
      else
      {
        while (j)
        {
          if (element == j && j->prev == NULL)
          {
            i->prev = NULL;
            break;
          }
          else
          {
            if (element == j && j->prev != NULL)
            {
              i->prev = j->prev;
            }
            i = j;
            j = j->prev;
          }
        }
      }
    }

    return top;
  }

  static void dumpStack(struct data_type_s *top, int eol)
  {
    if (top)
    {
      if (top->prev)
      {
        dumpStack(top->prev, 0);

        printf("<--");
      }

      printf("{%d,%d}", top->x, top->y);
    }

    if (eol)
    {
      puts("<==top");
    }
  }

  int main(void)
  {
    struct data_type_s *top = NULL;

    struct data_type_s a;

    struct data_type_s b;

    struct data_type_s c;

    struct data_type_s d;

    a.x = 6;
    a.y = 77;

    b.x = 5;
    b.y = 917;

    c.x = 89;
    c.y = 100;

    d.x = 95;
    d.y = 13;
    /* Wyglad stosu:     */
    /*  top:NULL (pusty) */

    /* Dodanie do stosu elementu a */
    a.prev = top;
    top = &a;

    /* Wyglad stosu: */
    /* [a]           */
    /* /|\           */
    /*  +---top      */
    dumpStack(top, 1);
    /* Dodanie do stosu elementu b */
    b.prev = top;
    top = &b;

    /* Wyglad stosu:  */
    /* [a]<--[b]      */
    /*       /|\      */
    /*        +---top */

    /* Dodanie do stosu elementu c */
    dumpStack(top, 1);
    c.prev = top;
    top = &c;

    /* Wyglad stosu:        */
    /* [a]<--[b]<--[c]      */
    /*             /|\      */
    /*              +---top */
    dumpStack(top, 1);
    d.prev = top;
    top = &d;
    /* Wyglad stosu:              */
    /* [a]<--[b]<--[c]<--[d]      */
    /*                   /|\      */
    /*                    +---top */
    /* usuniecie elementu b ze stosu */
    dumpStack(top, 1);
    top = RemoveStackElement(top, &b);

    /* Wyglad stosu:        */
    /* [a]<--[c]<--[d]      */
    /*             /|\      */
    /*              +---top */
    dumpStack(top, 1);

    /* usuniecie elementu a ze stosu */
    top = RemoveStackElement(top, &a);

    /* Wyglad stosu: */
    /* [c]<--[d]           */
    /*       /|\           */
    /*        +---top      */
    dumpStack(top, 1);
    /*usuniecie elementu d ze stosu*/
    top = RemoveStackElement(top, &d);
    /*   [c]      */
    /*   /|\      */
    /*   top      */
    /* usuniecie elementu gornego ze stosu (jest to element c) */
    dumpStack(top, 1);
    top = RemoveStackElement(top, top);

    /* Wyglad stosu:     */
    /*  top:NULL (pusty) */
    dumpStack(top, 1);

    return EXIT_SUCCESS;
  }

#ifdef __cplusplus
}
#endif
