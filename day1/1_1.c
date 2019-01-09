#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("input","r");
    int x;
    int a = 0;
    while(fscanf(fp,"%d",&x) != EOF)
    {
        a++;
    }
    fclose(fp);
    int tab[a];
    a=0;
    fopen("input","r");
    while(fscanf(fp,"%d",&x) != EOF)
    {
        tab[a] = x;
        a++;
    }
    fclose(fp);
    int suma = 0;
    for (int i = 0; i < a; i++){
        suma+=tab[i];//suma=suma+tab[1]
    }
    printf("Suma - %d\n", suma);
    return 1;
}
