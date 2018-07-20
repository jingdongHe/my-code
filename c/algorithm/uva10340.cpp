#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s,t;
	while(cin>>s>>t)
	{
		int k1=s.length();
		int k2=t.length();
		int i,j,k=1;
		j=0;
		for(i=0;i<k1;i++,j++)
		{
			while(s[i]!=t[j]&&j<k2)
				j++;
			if(j==k2)
			{k=0;break;}
		}
		if(i==k1&&k)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}