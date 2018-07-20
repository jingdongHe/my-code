#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	string s,t;
	int i,j;
	while(cin>>s>>t)
	{
		j=0;
		//cout<<t<<endl;
		//while(t[j])
		//	printf("%d",j++);
		//j=0;
		for(i=0;i<t.size();i++)
		{
			//printf("%d  %d\n",i,j);
			if(t[i]==s[j])
				j++;
		}
		if(j==s.size())
			printf("YES\n");
		else
			printf("NO\n");
		//cout<<s<<endl<<t<<endl;
	}
	return 0;
}