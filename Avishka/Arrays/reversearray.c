#include<stdio.h>
void reverse(int a[],int n);
int main()
{
	int a[20],n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	//e=n-1;
	reverse(a,n);
	//int s=0,e=n-1,t;
/*	while(s<e)
	{
		t=a[s];
		a[s]=a[e];
		a[e]=t;
		s++;
		e--;
	}
	for(i=0;i<n;i++)
	{
	printf("%d ",a[i]);
	}*/
	return 0;
}
void reverse(int a[],int n)
{
	int s=0,e=n-1,t,i;
	while(s<e)
	{
		t=a[s];
		a[s]=a[e];
		a[e]=t;
		s++;
		e--;
	}
	for(i=0;i<n;i++)
	{
	printf("%d ",a[i]);
	}
}
