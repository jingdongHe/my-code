#include<iostream>
#include<string>
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
string div(string s,int a)
{
	string x="";
	int k=0;
	for(int j=0;j<s.size();j++)
	{
		k*=10;k+=(s[j]-'0');
		if(k<a&&x!="")
			x+=0+'0';
		else
		{
			int f=int(k/a);
			if(f!=0)
				x+=f+'0';
			else if(x!="") x+=f+'0';
			k=k%a;
		}
	}
	return x;
}
int main()
{
	string a;
	int n;
	while(cin>>n&&n!=-1)
	{
		a="1";
		for(int i=2;i<=n;i++)
		{
			a=mul(a,4*i-2);
			a=div(a,i+1);
			
		}
		cout<<a<<endl;
	}
	return 0;
}
