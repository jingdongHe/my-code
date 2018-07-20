#include<stdio.h>
#include<string.h>
char order[300];
int d[100][100];
int dp(int i,int j)
{
	int k,sum=0;
	if(order[i]!=order[j])
		return 0;
	if(d[i][j]!=-1)
		return d[i][j];
	if(i==j)
		return 1;
	for(k=i+2;k<=j;k++)
		sum+=dp(i+1,k-1)*dp(k,j);
	return d[i][j]=sum;
}
int main()
{
	int l,r;
	while(gets(order))
	{
		l=0;r=strlen(order)-1;
		memset(d,-1,sizeof(d));
		printf("%d\n",dp(l,r));
	}
	return 0;
}
