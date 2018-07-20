#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
const int maxn=1000+5;
string add(string a,string b)
{
	string c="";
		int A=a.size()-1,B=b.size()-1;
		int k=0;
		while(A>=0&&B>=0)
		{
			int s=a[A--]+b[B--]-'0'-'0'+k;
			if(s>=10)
			{
				k=1;
				s=s%10;
			}
			else
				k=0;
			c=char(s+'0')+c;
		}
		while(A>=0)
		{
			int f=a[A--]-'0'+k;
			if(f>=10)
			{
				f%=10;
				k=1;
			}
			else k=0;
			c=char(f+'0')+c;
		}
		while(B>=0)
		{
			int f=b[B--]-'0'+k;
			if(f>=10)
			{
				f%=10;
				k=1;
			}
			else k=0;
			c=char(f+'0')+c;
		}
		if(k>0)
			c=char(k+'0')+c; 
		return c;
} 
int main()
{
	string a[maxn];
	a[1]="1";a[2]="2";
	a[3]="4";a[4]="7";
	for(int i=5;i<=1000;i++)
		a[i]=add(add(a[i-1],a[i-2]),a[i-4]);
	int n;
	while(scanf("%d",&n)!=EOF)
		cout<<a[n]<<endl;
	return 0;
}
