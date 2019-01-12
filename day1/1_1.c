#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("input","r");
    int x;
    int a = 0;
    while(fscanf(fp,"%d",&x) != EOF) // EOF- koniec wiersza liczenie wersow
    {
        a++;
    }
    fclose(fp);
    int tab[a];
    a=0;
    fopen("input","r");
    while(fscanf(fp,"%d",&x) != EOF)//pobieranie danych i zapis w tablicy przy pomocy fuckcji fopen
    {
        tab[a] = x;
        a++;
    }
    fclose(fp);
    int suma = 0;
    for (int i = 0; i < a; i++){
        suma+=tab[i];//suma=suma+tab[1] - sumowanie kolejnych wartosci
    }
    printf("Suma  %d\n", suma); // wypisz wynik
    return 1;
}
