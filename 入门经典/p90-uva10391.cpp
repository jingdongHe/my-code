#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=120000+5;
int a[maxn],t=-1,sum=0;
string s[maxn],s1,s2;
int Bkdrhash(string s)
{
	int seed=31,hash=0,i=0;
	while(s[i])
		hash=hash*seed+s[i++];
	return hash&0x7FFFFFFF;
}
bool cmp(int a,int b)
{
	return a<b;
}
bool find(int k,int b,int e)
{
	while(b<=e)
	{
		int m=(b+e)/2;
		if(a[m]>k)
			e=m-1;
		else if(a[m]<k)
			b=m+1;
		else if(a[m]==k)
			return true;
	}
	return false;
}
int main()
{
	while(cin>>s[++t])
		a[t]=Bkdrhash(s[t]);
	sort(a,a+t,cmp);
	for(int i=0;i<t;i++)
	{
		int l=s[i].length();
		for(int j=1;j<=l;j++)
		{
			s1=s[i].substr(0,j);
			s2=s[i].substr(j,l-j);
			cout<<s1<<endl<<s2<<endl;
			if(find(Bkdrhash(s1),0,t)&&find(Bkdrhash(s2),0,t))
			 {
			 	printf("11111111\n");
			 	cout<<s[i]<<endl;
			 }
		}
	}
	return 0;
}

