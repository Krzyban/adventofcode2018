#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MDN 254
#define MN 10

void czytajplik(char **A, int ilosc, FILE *fp)
{
	char slowo[MDN];
	int i=0;
	for (i=0;i<ilosc; i++)
	{
		fscanf(fp,"%s",slowo);
		A[i] = (char*) malloc(sizeof(char)*MDN);
		strcpy(A[i],slowo);
	}
}

void porownaj(char **A, int a)
{
	for(int i=1; i<a; i++)
	{
		for(int j=0; j<i; j++)//zeby nie porownywalo bez sensu dodatkowo 0z1 i 1 z 0
		{
			int l=0;//zlicza ilosc prawidlowych literek ma byc 25
			int c=0;//znacznik pozycji w wyrazie 0-25
			int x=0;//licznik bledow max 1
			while(x<2 && c<26)//c skacze po wyrazie x sprawdza ilosc bledow
			{
				if(*(A[i]+c) == *(A[j]+c))//j jest do porownywania
				{
					c++;
					l++;
				}
				else
				{
					x++;
					c++;				
				}
			}
			if(l==25)
			printf("%s\n%s\n",A[i],A[j]); //wypisz wynik z 2 tablic dla pewnosci
		}
	}
}

int main()
{
	int a=250;
	FILE *fp = fopen("slowa","r");
	char **A = (char**) malloc(a*sizeof(char*));//zapisuje wyrazy do tablicy
	czytajplik(A,a,fp);
	fclose(fp);
	porownaj(A,a);
	return 1;
}


