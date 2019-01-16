#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MDN 254
#define MN 10

void czytajplik(char **A, int ilosc, FILE *fp)
{
	char slowo[MDN];// wczytanie wyrazow z pliku
	int i=0;
	for (i=0;i<ilosc; i++)
	{
		fscanf(fp,"%s",slowo);
		A[i] = (char*) malloc(sizeof(char)*MDN);
		strcpy(A[i],slowo);//przeniesienie do tablicy A z slowo
	}
}

void zliczlitery(char **A, int a)
{
	int x;
	int dwa = 0;
	int trzy = 0;
	int licznik[26]={0};//26x0w tablicy poczatkowych wartosci
	int wynik1=0, wynik2=0;
	for(int i=0; i<a; i++)
	{
		dwa=0;//liczniki 2 i 3
		trzy=0;
		int j=0;
		while(*(A[i]+j) != '\0')
		{
			if (*(A[i]+j) >= 'a' && *(A[i]+j) <= 'z')//sprawdza czy jest litera
			{
				x = *(A[i]+j) - 'a';//kod asci -a=liczba od 0 do 26 ktora bedzei miejscem w tablicy
				licznik[x]++;//dane miejsc zmeini sie z 0 na 1
			}
			j++;
		}
		for(int c=0; c<26; c++)// kontrola wartosci na pozycjach c w wyarazie
		{
			if(licznik[c]==2)
				dwa=1;
			if(licznik[c]==3)
				trzy=1;
			licznik[c]=0;//zerowanie by nie mieszalo sie przy kolejnych wyrazach
		}
		if(dwa>0)//nie ma zliczac podwojnie
			wynik1++;
		if(trzy>0)
			wynik2++;
	}
	int wynik = wynik1 * wynik2;
	/*printf("Wynik1 - %d\n", wynik1);
	printf("Wynik2 - %d\n", wynik2);	*/	
	printf("Wynik - %d\n", wynik);	
}

int main()
{
	int a=250;
	FILE *fp = fopen("slowa","r");
  char **A = (char**) malloc(a*sizeof(char*));//tablica wyrazow
	czytajplik(A,a,fp);
	fclose(fp);
	zliczlitery(A,a);
}
