#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
bool comp(string a,string b)
{
	return a+b>b+a;
}
int main()
{
	int n,i;
	string A[50],B;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
	getchar();
	B="";
	//memset(B,'\0',sizeof(B));
	for(i=0;i<n;i++)
		cin>>A[i];
	sort(A,A+n,comp);
	for(i=0;i<n;i++)
		B+=A[i];
	cout<<B<<endl;
	}
	return 0;
}
