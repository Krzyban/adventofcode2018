#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("1000.txt","r");
    int x;
    int a = 0;
    while(fscanf(fp,"%d",&x) != EOF)
    {
        a++;
    }
    fclose(fp);
    int tab[a];
    a=0;
    fopen("1000.txt","r");
    while(fscanf(fp,"%d",&x) != EOF)
    {
        tab[a] = x;
        a++;
    }
    fclose(fp);
    int suma = 0;
    for (int i = 0; i < a; i++){
        suma+=tab[i];
    }
    printf("Suma - %d\n", suma);
    return 1;
}
