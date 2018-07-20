#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
#define M 1005
int main()
{
	string a,b,c;
	int T;
	scanf("%d",&T);getchar();
	for(int t=1;t<=T;t++)
	{
		c="";
		cin>>a>>b;
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
		cout<<"Case "<<t<<":"<<endl;
		cout<<a<<" + "<<b<<" = "<<c<<endl;
		if(t!=T) cout<<endl;
	}
	return 0;
}
