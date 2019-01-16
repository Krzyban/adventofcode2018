#include <stdio.h>
#include <stdlib.h>

void czytajplik(int *tab, FILE *fp)
{
    int a = 0;
    int x;
    while(fscanf(fp,"%d",&x) != EOF)
    {
        tab[a] = x;
        a++;
    }
}

int zliczzmienne(FILE *fp)
{
    int a = 0;
    int x;
    while(fscanf(fp,"%d",&x) != EOF)
    {
        a++;
    }
    return a;
}

void suma(int *tab, int a)
{
    int suma = 0;
    for (int i = 0; i < a; i++){
        suma+=tab[i];//suma=suma+tab[1] - sumowanie kolejnych wartosci
    }
    printf("Suma  %d\n", suma); // wypisz wynik
}

int main()
{
    FILE *fp = fopen("input","r");//liczy zmienne
    int a=zliczzmienne(fp);
    fclose(fp);
    int tab[a];
    fopen("input","r");
    czytajplik(tab, fp);
    fclose(fp);
    suma(tab,a);
    return 1;
}
