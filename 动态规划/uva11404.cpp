#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

const int maxn=1000+5;
struct node {
	int len;
	string s;
}dp[maxn][maxn];
int main()
{
	struct node temp;
	temp.len=0;
	temp.s="";
	string str1,str2="";
	cin>>str1;
	int len=str1.length();
	for(int i=len-1;i>=0;i--)
		str2+=str1[i];
	str2+='\0';
	for(int i=0;i<len;i++)
	{
		dp[0][i].s=dp[i][0].s="";
		dp[0][i].len=dp[i][0].len=0;
	}
	
	for(int i=1;i<=len;i++)
	{
		for(int j=1;j<=len;j++)
		{
			if(str1[i-1]==str2[j-1])
			{
				dp[i][j].len=dp[i-1][j-1].len+1;
				dp[i][j].s=dp[i-1][j-1].s+str1[i-1];
			}
			else 
			{
				if(dp[i-1][j].len>dp[i][j-1].len)
				{
					dp[i][j].len=dp[i-1][j].len;
					dp[i][j].s=dp[i-1][j].s;
				}
				else if(dp[i-1][j].len<dp[i][j-1].len)
				{
					dp[i][j].len=dp[i][j-1].len;
					dp[i][j].s=dp[i][j-1].s;
				}
			}
			if(dp[i][j].len==temp.len&&dp[i][j].s<temp.s)
				temp.s=dp[i][j].s;
			else if(dp[i][j].len>temp.len)
			{
				//cout<<dp[i][j].len<<"......."<<endl<<dp[i][j].s<<"......."<<endl;
				temp.len=dp[i][j].len;
				temp.s=dp[i][j].s;
			}
		}
	}
	if(temp.len&1)
	{
		for(int i=0;i<temp.len/2;i++)
			cout<<temp.s[i];
		for(int i=temp.len/2;i>=0;i--)
			cout<<temp.s[i];
		cout<<endl;
	}
	else
	{
		for(int i=0;i<temp.len/2;i++)
			cout<<temp.s[i];
		for(int i=temp.len/2-1;i>=0;i--)
			cout<<temp.s[i];
		cout<<endl;
	}
	//cout<<temp.s<<endl;
	return 0;
}
