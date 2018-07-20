#include<stdio.h>
#define maxn 1005
char seq[maxn];
bool ok(int l,int r)
{
	while(l<r)
	{
		if(seq[l]!=seq[r])
			return false;
		l++;r--;
	}
	return true;
}
int main()
{
	int n;
	int dp[manx];
	scanf("%d",&n);getchar();
	for(int i=0;i<n;i++)
	{
		scanf("%c",&seq[i]);
		dp[i]=9999;
	}
	dp[1]=0;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(ok(j,i))
			{
				dp[i]=dp[i]<dp[j]+1?dp[i]:dp[j+1];
			}
		}
	}
	return 0;
}
