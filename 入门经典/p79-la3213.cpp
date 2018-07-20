#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
const int maxn=100+5;
int main()
{
	string A,B;
	int mapping[26];
	cin>>A;cin>>B;
	for(int i=0;i<26;i++)
		mapping[i]=-1;
	for(int i=0;i<A.size();i++)
	{
		if(mapping[B[i]-'A']==-1)
			mapping[B[i]-'A']=A[i]-'A';
		else if(mapping[B[i]-'A']!=A[i]-'A')
		{printf("NO\n");return 0;}
	}
	printf("YES\n");
	return 0;
}
