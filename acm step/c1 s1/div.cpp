#include<iostream>
#include<string>
using namespace std;
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
	string s;
	cin>>s;
	for(int i=1;i<=10;i++)
	{
		string k=div(s,i);
		cout<<k<<endl;
	}
	return 0;
}
