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
	for(int i=1; i<a; i++)
	{
		for(int j=0; j<i; j++)
		{
			int l=0;
			int c=0;
			int x=0;
			while(x<2 && c<26)
			{
				if(*(A[i]+c) == *(A[j]+c))
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


