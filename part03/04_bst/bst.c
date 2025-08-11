#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COMMANDS 3
#define BUFFER 100

#ifdef __cplusplus
extern "C" {
#endif

typedef struct element_s element_t;

struct element_s
{
    element_t *left, *right, *parent;

    int value;

    int count;
};

void add(element_t **root, int number);
void del(element_t **root, int number);
/*void dump(element_t *ptr);*/
void free_tree(element_t *root);
void max(element_t *root);
void shift_nodes(element_t **root, element_t *u, element_t *v);
element_t *get_successor(element_t *x);

int main(void)
{
    const char commands[COMMANDS][BUFFER] = {{"add"}, {"del"}, {"max"}};
    char cmd[BUFFER];

    int i, index, number;

    element_t *root = NULL;

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
                add(&root, number);
                break;
            case 1:
                scanf("%d", &number);
                del(&root, number);
                break;
            case 2:
                max(root);
                break;
            default:
                fprintf(stderr, "command not found\n");
                break;
        }
    }

    free_tree(root);

    return EXIT_SUCCESS;
}

/* Adds a node to the tree */
void add(element_t **root, int number)
{
    element_t *current = *root, *parent = NULL, *new_node = NULL;

    while (current != NULL)
    {
        parent = current;
        if (number == current->value)
        {
            current->count++;
            return;
        }
        else if (number < current->value)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    new_node = malloc(sizeof(element_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "%s Error: failed to allocate memory for variable 'new_node'\n", __func__);
        free_tree(*root);
        exit(EXIT_FAILURE);
    }

    new_node->value = number;
    new_node->count = 1;
    new_node->left = new_node->right = NULL;
    new_node->parent = parent;

    if (parent == NULL)
    {
        *root = new_node;
    }
    else if (number < parent->value)
    {
        parent->left = new_node;
    }
    else
    {
        parent->right = new_node;
    }
}

/* Deletes the node with the given number */
void del(element_t **root, int number)
{
    element_t *current = *root;

    while (current != NULL && number != current->value)
    {
        if (number < current->value)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    if (current == NULL)
    {
        return;
    }

    if (current->count > 1)
    {
        current->count--;
        return;
    }

    if (current->left == NULL)
    {
        shift_nodes(root, current, current->right);
    }
    else if (current->right == NULL)
    {
        shift_nodes(root, current, current->left);
    }
    else
    {
        element_t *successor = get_successor(current);
        if (successor->parent != current)
        {
            shift_nodes(root, successor, successor->right);
            successor->right = current->right;
            successor->right->parent = successor;
        }
        shift_nodes(root, current, successor);
        successor->left = current->left;
        successor->left->parent = successor;
    }

    free(current);
}

element_t *get_successor(element_t *x)
{
    element_t *y = NULL;

    if (x->right != NULL)
    {
        x = x->right;
        while (x->left != NULL)
        {
            x = x->left;
        }
        return x;
    }

    y = x->parent;

    while (y != NULL && x == y->right)
    {
        x = y;
        y = y->parent;
    }

    return y;
}

void shift_nodes(element_t **root, element_t *u, element_t *v)
{
    if (u->parent == NULL)
    {
        *root = v;
    }
    else if (u == u->parent->left)
    {
        u->parent->left = v;
    }
    else
    {
        u->parent->right = v;
    }
    if (v != NULL)
    {
        v->parent = u->parent;
    }
}

/*
void dump(element_t *ptr)
{
    if (ptr == NULL)
    {
        return;
    }

    printf("%d - %d\n", ptr->value, ptr->count);

    dump(ptr->left);
    dump(ptr->right);
}
*/

/* Prints the max value */
void max(element_t *root)
{
    if (root == NULL)
    {
        fprintf(stderr, "Tree is empty!\n");
        return;
    }

    while (root->right != NULL)
    {
        root = root->right;
    }
    printf("%d\n", root->value);
}

/* Iterates through the tree and frees all nodes */
void free_tree(element_t *root)
{
    if (root == NULL)
    {
        return;
    }

    free_tree(root->left);
    free_tree(root->right);

    free(root);
}

#ifdef __cplusplus
}
#endif
