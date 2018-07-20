#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a,b;
	while(cin>>a>>b)
	{
		int dp[500][500]={0};
		for(int i=1;i<=a.size();i++)
		{
			for(int j=1;j<=b.size();j++)
			{
				if(a[i-1]==b[j-1])
					dp[i][j]=dp[i-1][j-1]+1;
				else
					dp[i][j]=dp[i-1][j]>dp[i][j-1]?dp[i-1][j]:dp[i][j-1];
			}
		}
		printf("%d\n",dp[a.size()][b.size()]);
	}
	return 0;
}
