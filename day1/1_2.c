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
    int suma[1000000];
    suma[0]=tab[0];
    int i = 1;
    x = 1;
    while(1)
    {
        suma[i]=suma[i-1]+tab[x];
        for (int j = 0; j < i; j++)
        {
            if (suma[j]==suma[i])
            {
                printf("Liczba - %d (pozycja - %d)\n", suma[j],i);
                return 1;

            }
        }
        i++;
        x++;
        if(x>=a)
            x=0;
    }
}
