#include<stdio.h>
int main()
{
	int n,i,j;
	int t,T;
	char k;
	char a[15][15];
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
	scanf("%d",&n);getchar();
	for(i=0;i<n;i++)
	{scanf("%s",&a[i]);getchar();}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]=='.')
			{
				for(k='A';k<='Z';k++)
				{
					if(i>=1&&a[i-1][j]==k)
						continue;
					if(i<n-1&&a[i+1][j]==k)
						continue;
					if(j>=1&&a[i][j-1]==k)
						continue;
					if(j<n-1&&a[i][j+1]==k)
						continue;
					a[i][j]=k;break;
				}
			}
		}
	}
	printf("Case %d:\n",t);
	for(i=0;i<n;i++)
		printf("%s\n",a[i]);
	}
	return 0;
}
