#include<stdio.h>
int main()
{
	int n,a[30][30],i,j,k=0;
	a[0][0]=1;a[1][0]=1;a[1][1]=1;
	while(scanf("%d",&n)!=EOF)
	{
		k=0;
		for(i=2;i<=n;i++)
		{
			a[i][i]=1;
			a[i][0]=1;
		}
		
		for(i=2;i<n;i++)
		{
			for(j=1;j<i;j++)
			{
				
				a[i][j]=a[i-1][j-1]+a[i-1][j];
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<i+1;j++)
			{
				printf("%d",a[i][j]);
				if(j!=i)
					printf(" ");
			}
			printf("\n");
		}
			printf("\n");
		for(i=2;i<n;i++)
		{
			for(j=1;j<i;j++)
			{
				
				a[i][j]='\0';
			}
		}

	}
	return 0;
}

