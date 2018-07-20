#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int main()
{
	vector <string> v[100];int i;
	string a;
	for(i=0;i<3;i++)
	{
		scanf("%s",&a);
		v.push_back(a);
		printf("%s......\n",v.front());
	}
	vector<string>::iterator j;
	for(j=v.begin();j!=v.end();j++)
		printf("%s\n",v[i]);
	return 0;
}