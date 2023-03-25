//setting matrix values to zeros
#include<stdio.h>
int main()
{
	int a[20][20],d=0,c=0,m,n,i,j,b[20][20]; 
	scanf("%d",&m);   //no of rows
	scanf("%d",&n);   //no of columns
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			b[i][j]=1;
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]==0)
			{
				while(c<m)
				{
					b[c][j]=0;
					c++;
				}
				while(d<n)
				{
					b[i][d]=0;
					d++;
				}
			}
			c=0;
			d=0;
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(b[i][j]!=0)
			{
				b[i][j]=a[i][j];
			}
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}
}

