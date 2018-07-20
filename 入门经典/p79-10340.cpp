#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s,t;
	cin>>s;cin>>t;
	int j=0,i;
	for(i=0;i<s.size();i++,j++)
	{
		while(s[i]!=t[j]) j++;
		if(j>=t.size()) break;
	}
	if(i==s.size())
		cout<<"YES\n";
	else 
		cout<<"NO\n";
	return 0;
}
