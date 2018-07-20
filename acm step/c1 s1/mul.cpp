#include<stdio.h>
#include<iostream>
using namespace std;
string mul(string s,int a)
{
	int f=0;
	string x;
	for(int j=s.size()-1;j>=0;j--)
	{
		int k=a*(s[j]-'0')+f;
		x=char(k%10+'0')+x;
		f=k/10;
	}
	while(f!=0)
	{
		x=char(f%10+'0')+x;
		f/=10;
	}
	for(int i=0;i<x.size();i++)
	{
		if(x[i]=='0') x.erase(0);
		else break;
	}
	if(x=="") x="0";
	return x;
}
int main()
{
	string s;
	cin>>s;
		string k=mul(s,1333);
		cout<<k<<endl;
	return 0;
}
