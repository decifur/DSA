//Kadane's Algorithm
#include<stdio.h>
int main()
{
	int a[20],i,n,sf,eh=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	sf=a[0];
	for(i=0;i<n;i++)
	{
		eh+=a[i];
		if(sf<eh)
		{
			sf=eh;
		}
		if(eh<0)
		{
			eh=0;
		}
	}
	printf("%d",sf);
	return 0;
}
