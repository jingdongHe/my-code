#include<stdio.h>
#include<string.h>
int win[20][20];
const int Max=10;
int is_win(int n,int m)
{
	int s=0;
	if(win[n][m]!=-1)
		return win[n][m];
	if(win[m][n]!=-1)
		return win[n][m]=win[m][n];
	int k;
	for(k=1;k<m;k++)
		if(!is_win(k,m-k))
		{win[n][m]=win[m][n]=1;s=1;}
	for(k=1;k<n;k++)
		if(!is_win(n-k,k))
		{win[n][m]=win[m][n]=1;s=1;}
	if(s==1)
		return win[n][m];
	else
		return win[n][m]=0;
}
int main()
{
	int i,j;
	memset(win,-1,sizeof(win));
	win[1][1]=0;
	printf("%d\n",is_win(Max,Max));
	for(i=1;i<=Max;i++)
	{
		for(j=1;j<=Max;j++)
			printf("%3d",win[i][j]);
		printf("\n");
	}
	return 0;
}