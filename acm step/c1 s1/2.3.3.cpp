#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
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
	int n;
	string s[4];
	
	while(scanf("%d",&n)!=EOF)
	{
		s[0]=s[1]=s[2]=s[3]="1";
		for(int i=4;i<n;i++)
		{
			s[i%4]=add(add(add(s[0],s[1]),s[2]),s[3]);
		}
		cout<<s[(n-1)%4]<<endl;
	}
	return 0;
} 
