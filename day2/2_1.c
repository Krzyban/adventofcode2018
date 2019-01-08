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

void drukuj(char **A,int n)
{ 
	int i;
	for (i=0;i<n;i++)
	{
		printf("%s",A[i]);   
		printf("\n");
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
    char **A = (char**) malloc(a*sizeof(char*));
	czytajplik(A,a,fp);
	fclose(fp);
    int x;
	int dwa = 0;
	int trzy = 0;
	int licznik[26]={0};
	int wynik1=0, wynik2=0;
	for(int i=0; i<a; i++)
	{
		dwa=0;
		trzy=0;
		int j=0;
		while(*(A[i]+j) != '\0')
		{
			if (*(A[i]+j) >= 'a' && *(A[i]+j) <= 'z')
			{
				x = *(A[i]+j) - 'a';
				licznik[x]++;
			}
			j++;
		}
		for(int c=0; c<26; c++)
		{
			printf("%d",licznik[c]);
			if(licznik[c]==2)
				dwa=1;
			if(licznik[c]==3)
				trzy=1;
				licznik[c]=0;
		}
		if(dwa>0)
			wynik1++;
		if(trzy>0)
			wynik2++;
			printf("\n");
	}
	int wynik = wynik1 * wynik2;
	printf("Wynik1 - %d\n", wynik1);
	printf("Wynik2 - %d\n", wynik2);		
	printf("Wynik - %d\n", wynik);	
	return 1;
}