#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
/*bool operator >(string a,string b)
{
	int i,j;
	int ki=a.size(),kj=b.size();
	for(i=0,j=0;i<ki&&j<kj;i++,j++)
	{
		if(a[i]>b[j])
			return true;
		if(a[i]<b[j])
			return false;
	}
	if(i==ki)//aÒÑ¾­Âú
	{
		i--;
		while(a[i]==b[j]&&j<kj)
			j++;
		if(j==kj)
			return false;
		if(a[i]>b[j])
			return true;
		else
			return false;
	}
	if(j==kj)
	{
		j--;
		while(a[i]==b[j]&&i<ki)
			i++;
		if(i==ki)
			return true;
		if(a[i]>=b[j])
			return true;
		else
			return false;
	}
	return true;
}*/
bool cmp(string a,string b)
{
	return a+b>b+a;
}
int main()
{
	string a[50+5];
	int i,n;
	while(scanf("%d",&n)&&n)
	{
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n,cmp);
	for(i=0;i<n;i++)
		cout<<a[i];
	printf("\n");
	}
	return 0;
}