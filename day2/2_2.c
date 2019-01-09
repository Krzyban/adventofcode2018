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

int main()
{
	int a=250;
	FILE *fp = fopen("slowa","r");
	/*char ch;
	while ((ch = fgetc(fp)) != EOF){
	  if (ch == '\n')
				a++;
	}*/   
	/*char slowo[MDN];
	while(fscanf(fp,"%s",slowo) != EOF)
	{
		a++;
	}*/
	char **A = (char**) malloc(a*sizeof(char*));//zapisuje wyrazy do tablicy
	czytajplik(A,a,fp);
	fclose(fp);
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
			printf("%s\n%s\n",A[i],A[j]);
		}
	}
	return 1;
}


