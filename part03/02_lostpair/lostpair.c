/* wersja w c z liniowym wyszukwianiem w prostej strukturze, nazwy zmiennych/komentarzy/funkcji polsko-angielskie :p */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

struct list
{
    struct list *next;
    char *word;
    unsigned short ctr;
};

struct list *znajdz_slowo(struct list *head, const char *word);
void dodaj_slowo(struct list **head, const char *word);
void wypisz_bez_pary(struct list *head);
void zwolnij_liste(struct list **head);

int main(void)
{

    struct list *head = NULL;
    char *text = malloc(sizeof(char) * 100 + 1);

    if (!text)
    {
        fprintf(stderr, "LOG: Nie udalo sie zarezerwowac obszaru!\n");
        return EXIT_FAILURE;
    }

    while ((scanf("%100s", text)) != EOF)
    {
        dodaj_slowo(&head, text);
    }

    free(text);

    wypisz_bez_pary(head);
    zwolnij_liste(&head);

    return EXIT_SUCCESS;
}

struct list *znajdz_slowo(struct list *head, const char *word)
{

    while (head != NULL)
    {
        if (strcmp(head->word, word) == 0)
        {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

void dodaj_slowo(struct list **head, const char *word)
{
    struct list *znalezione_slowo = znajdz_slowo(*head, word);

    /* if there's no match in list, add to the list */
    if (znalezione_slowo == NULL)
    {
        struct list *nowy = malloc(sizeof(struct list));

        if (!nowy)
        {
            fprintf(stderr, "LOG: Nie udalo sie zarezerwowac obszaru!\n");
            /* chyba taki exit w funkcji wewnetrznej jest sredni, bo program nie uwolni calej
             * pamieci */
            exit(EXIT_FAILURE);
        }

        nowy->word = malloc(sizeof(char) * (strlen(word) + 1));

        if (!nowy->word)
        {
            fprintf(stderr, "LOG: Nie udalo sie zarezerwowac obszaru!\n");
            exit(EXIT_FAILURE);
        }

        strcpy(nowy->word, word);

        nowy->ctr = 1;
        nowy->next = *head;
        *head = nowy;
    }
    /* If it is, add 1 to the counter */
    else
    {
        znalezione_slowo->ctr++;
    }
}

void wypisz_bez_pary(struct list *head)
{

    while (head != NULL)
    {
        if (head->ctr == 1)
        {
            printf("%s\n", head->word);
            /* zalozenie z zadania ze jest tylko jedne slowo bez pary, mozna przestac iterowac */
            break;
        }
        head = head->next;
    }
}

void zwolnij_liste(struct list **head)
{
    struct list *pomocnicza;
    
    while (*head != NULL)
    {
        pomocnicza = *head;
        *head = pomocnicza->next;
        free(pomocnicza->word);
        free(pomocnicza);
    }
}

#ifdef __cplusplus
}
#endif
