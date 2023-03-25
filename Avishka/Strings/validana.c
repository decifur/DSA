//Anagram
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
bool ana_gram(char a[],char b[]);
int main()
{
	char a[20],b[20];
	gets(a);
	gets(b);
	ana_gram(a,b);
	return 0;
}
bool ana_gram(char a[],char b[])
{
	int l,l1,i,j;
	char k;
	l=strlen(a);
	l1=strlen(b);
	if(l==l1)
	{
		for(i=1;i<l;i++)
		{
			k=a[i];
			j=i-1;
			while(k<a[j] && j>=0)
			{
				a[j+1]=a[j];
				--j;
			}
			a[j+1]=k;
		}
		for(i=1;i<l;i++)
		{
			k=b[i];
			j=i-1;
			while(k<b[j] && j>=0)
			{
				b[j+1]=b[j];
				--j;
			}
			b[j+1]=k;
		}
		for(i=0;i<l;i++)
		{
			if(a[i]!=b[i])
			{
				printf("false");
				return false;
			}
		}
		puts(a);
		puts(b);
		printf("true");
		return true;
	}
	else
	{
		printf("false");
		return false;
	}
}
