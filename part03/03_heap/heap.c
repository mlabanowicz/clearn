#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COMMANDS 3
#define BUFFER 100

#ifdef __cplusplus
extern "C" {
#endif

struct list
{
    int number;
    struct list *next;
};

void add(struct list **head, int number);
void del(struct list **head, int number);
/* void dump(struct list *ptr); */
void free_list(struct list *head);
void max(struct list *head);

int main(void)
{
    const char commands[COMMANDS][BUFFER] = {{"add"}, {"del"}, {"max"}};
    char cmd[BUFFER];

    int i, index, number;

    struct list *head = NULL;

    while (scanf("%99s", cmd) != EOF)
    {
        /* Set index to -1 to indicate command not found */
        index = -1;

        for (i = 0; i < COMMANDS; i++)
        {
            if (strcmp(cmd, commands[i]) == 0)
            {
                index = i;
                break;
            }
        }

        switch (index)
        {
            case 0:
                scanf("%d", &number);
                add(&head, number);
                break;
            case 1:
                scanf("%d", &number);
                del(&head, number);
                break;
            case 2:
                max(head);
                break;
            default:
                fprintf(stderr, "command not found\n");
                break;
        }
    }

    free_list(head);

    return EXIT_SUCCESS;
}

/* Adds a node to the end of the list */
void add(struct list **head, int number)
{
    struct list *n = malloc(sizeof(struct list)), *ptr = *head;

    if (n == NULL)
    {
        fprintf(stderr, "%s Error: failed to allocate memory for variable 'n'\n", __func__);
        free_list(ptr);
        exit(EXIT_FAILURE);
    }

    n->number = number;
    n->next = NULL;

    if (*head == NULL)
    {
        *head = n;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = n;
    }
}

/* Deletes the first found node with the given number */
void del(struct list **head, int number)
{
    struct list *ptr = *head, *next = NULL;

    if (*head == NULL)
    {
        return;
    }

    next = ptr->next;

    if (ptr->number == number)
    {
        free(ptr);
        *head = next;
        return;
    }

    while (next != NULL)
    {
        if (next->number == number)
        {
            ptr->next = next->next;
            free(next);
            return;
        }
        ptr = next;
        next = ptr->next;
    }
    fprintf(stderr, "Number not found!\n");
    return;
}

/* Prints all numbers from the list
void dump(struct list *ptr)
{
 

    for (; ptr != NULL; ptr = ptr->next)
    {
        printf("%d\n", ptr->number);
    }
}
*/

/* Iterates through the whole list and prints the max value */
void max(struct list *head)
{
    int max = INT_MIN;

    if (head == NULL)
    {
        fprintf(stderr, "List is empty!\n");
        return;
    }

    for (; head != NULL; head = head->next)
    {
        if (head->number > max)
        {
            max = head->number;
        }
    }
    printf("%d\n", max);
}

/* Iterates through the list and frees all nodes */
void free_list(struct list *head)
{
    struct list *next;
    while (head != NULL)
    {
        next = head->next;
        free(head);
        head = next;
    }
}

#ifdef __cplusplus
}
#endif
