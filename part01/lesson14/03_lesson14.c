#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int tab[256];
    int x = 0;
    while (x != 256) {
        printf("adres %d-go elementu %p\n", x, (void*)(&tab[x]));
        x++;
    }

    return EXIT_SUCCESS;
}