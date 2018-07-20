#include<stdio.h>
const int MAXI=21;
const int MAX=100;
int main()
{
	int i,j,k;
	int d[MAX][MAX]={0};
	d[0][0]=1;
	for(i=1;i<MAXI;i++)
	{
		for(j=0;j<=MAX;j++)
		{
			for(k=0;j+k*i*i*i<=MAX;k++)
				d[i][j+k*i*i*i]+=d[i-1][j];
		}
	}
	int n;
	while(scanf("%d",&n))
	{
		printf("%d",d[10][n]);
	}
	return 0;
}