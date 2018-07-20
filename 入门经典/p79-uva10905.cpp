#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	string temp,res;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		string temp1,temp2;
		temp1=res+temp;
		temp2=temp+res;
		res=temp1>temp2?temp1:temp2;
	}
	cout<<res<<endl;
	return 0;
}
