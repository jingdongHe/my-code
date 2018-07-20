#include<stdio.h>
#include<vector>
#include<queue>
#include<iterator>
using namespace std;
typedef struct node {
	int data;
}node;
struct cmp {
	bool operator () (node a,node b)
	{
		return a.data>b.data;
	}
};
int main()
{
	priority_queue<node,vector<node>,cmp> a;
	int i,n;
	node x;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x.data);
		a.push(x);
	}
	while(!a.empty())
	{
		x=a.top();
		printf("%d ",x.data);
		a.pop();
	}
	return 0;
}