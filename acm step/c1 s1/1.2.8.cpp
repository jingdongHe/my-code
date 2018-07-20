#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	string from[8]={"Zhejiang","Beijing","Taiwan","Hong Kong",
	"Macao","Tibet","Liaoning","Shanghai"};
	scanf("%d",&n);
	while(n--)
	{
		string s;
		cin>>s;
		string s_from=s.substr(0,6);
		cout<<"He/She is from ";
		if(s_from=="330000") cout<<from[0];
		else if(s_from=="110000") cout<<from[1];
		else if(s_from=="710000") cout<<from[2];
		else if(s_from=="810000") cout<<from[3];
		else if(s_from=="820000") cout<<from[4];
		else if(s_from=="540000") cout<<from[5];
		else if(s_from=="210000") cout<<from[6];
		else if(s_from=="310000") cout<<from[7];
		cout<<",and his/her birthday is on ";
		string birthday=s.substr(6,8);
		cout<<birthday.substr(4,2)<<","<<birthday.substr(6,2)<<","<<birthday.substr(0,4);
		cout<<" based on the table."<<endl;
	}
	return 0;
}
