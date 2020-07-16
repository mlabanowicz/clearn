#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INT_BIT (CHAR_BIT * sizeof(int))
int
main (void) 
{
int n = 0, x = 0, y = 1, z = 0,o=0,tab[INT_BIT];
int scanf_result = scanf("%d", &n);
if (scanf_result == EOF){
fprintf(stderr, "blad- brak danych");
return EXIT_FAILURE;
}
while (1 == 1)
{
if (scanf_result != 1)
{
fprintf (stderr, "blad - podane dane nie sa liczba\n");
return EXIT_FAILURE;
}
if (y == 1)
{
x = n % 2;
if(x <=-1){
x = x * -1;
o = 1;
}
n = n / 2;
tab[z] = x;
if (n == 0)
y = 2;
z++;
if (z == 100)
{
fprintf (stderr, "blad - za duza liczba");
return EXIT_FAILURE;
}
}
if (y == 2)
{
if(o == 1){
printf("-");
o=0;
}
printf ("%d", tab[z - 1]);
z--;
if (z == 0)
{
y = 1;
printf ("\n");
if (scanf("%d", &n) == EOF){
break;
}
}
}
}
return EXIT_SUCCESS;
}
