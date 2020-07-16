#include <stdio.h>
#include <stdlib.h>
int
main (void) 
{
int n = 0, x = 0, y = 1, z = 0,tab[100];
int scanf_result = scanf("%d", &n);
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
