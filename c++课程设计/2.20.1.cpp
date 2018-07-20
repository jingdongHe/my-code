#include<stdio.h>
#include<stack>
using namespace std;
int main()
{
	stack<int> s;
	int k;
	for(int i=0;i<3;i++)
	{scanf("%d",&k);s.push(k);}
	while(!s.empty())
	{
		printf("%d\n",s.top());
		s.pop();
	}
	return 0;
}