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

void sprawdz(int *tab, int a)
{
    int go=0;
    int suma[200000];// tablica na milion
    suma[0]=tab[0];//pierwszy na sztywno
    int i = 1;
    int x = 1;
    while(go==0)
    {
        suma[i]=suma[i-1]+tab[x]; //dodawanie kolejnych wartosci
        for (int j = 0; j < i; j++)
        {
            if (suma[j]==suma[i])//sprawdzanie wszystkich poprzednich wartosci - szukanie odpowiedzi
            {
                printf("Liczba - %d (pozycja - %d)\n", suma[j],i);// wypisanie rozwiazania
                go=1;
            }
        }
        i++;
        x++;
        if(x>=a)//jesli przekroczy liczbe zmiennych
            x=0;
    }
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
    sprawdz(tab, a);
}