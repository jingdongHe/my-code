#include<stdio.h>
int digui(int x,int y)
{
	if(y==0||y==x+1)
		return 1;
	else
		return digui(x-1,y)+digui(x-1,y-1);
}
void main()
{
	int i,j;
	int n;
	/*int a[22];
	int b[22];
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			a[0]=a[i]=1;
			b[0]=b[i]=1;
			for(j=1;j<i;j++)
				b[j]=a[j-1]+a[j];
			for(j=0;j<i+1;j++)
			{
				a[j]=b[j];
				printf("%-3d",b[j]);
			}
			printf("\n");
		}
	}*/
	/*int a[21][22];
	a[0][0]=1;a[1][0]=a[1][1]=1;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=2;i<n;i++)
		{
			a[i][0]=1;
			for(j=1;j<i;j++)
			{
				a[i][j]=a[i-1][j]+a[i-1][j-1];
			}
			a[i][i]=1;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<i+1;j++)
				printf("%-3d",a[i][j]);
			printf("\n");
		}
	}*/
	int k,m;
	int x=0,y=0;
	int d=0;
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%d",&m);
		printf("1\n");
		for(i=0;i<n;i++)
		{
			for(j=0;j<=i+1;j++)
			{
				k=digui(i,j);
				if(k==m&&d==0)
				{x=i;y=j;d=1;}
				printf("%-3d",k);
			}
			printf("\n");
		}
		if(x==0&&y==0)
			printf("NO\n");
		else
		{
			if(m==1)
				printf("m所在的位置为:[0][0]\n");
			else
				printf("m所在的位置为:[%d][%d]\n",x+1,y);
		}
	}
}