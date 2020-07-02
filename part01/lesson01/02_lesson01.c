#include <stdio.h>

int main()
{
int i=0;
float x;//aby wynik byl dokladnijeszy x bedzie liczba zmmienna przecinkowa
while(i==0){//petla bedzie wykonywana az x nie bedzie mial poprawnej wartosci
    scanf("%f", &x);//wczytaj z klawiatory wartosc x
    if(x == 1){//sprawdz czy x jest "niedozwolona wartoscia"
        printf("blad\n");
    }
    else{//jezeli nie zakoncz petle
        i=1;
    }
}
printf("%f", 100/(x - 1));//z poprawnym x oblicz i wypisz jego funkcje
    return x;
}
