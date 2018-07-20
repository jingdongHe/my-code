#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
const int maxn=200+5;
struct node{
	int f,k;
};
int arr[maxn];
bool use[maxn];
int n,a,b;
struct cmp {
	bool operator () (node &A,node &B)
	{
		return A.k>B.k;
	}
};
int BFS()
{
	node temp;
	temp.f=a;temp.k=0;
	priority_queue<int,vector<node>,cmp> q;
	q.push(temp);use[temp.f]=true;
	while(!q.empty())
	{
		temp=q.top();
		//printf("%d,%d\n",temp.f,temp.k);
		if(temp.f==b) return temp.k;
		q.pop();
		if(temp.f+arr[temp.f]<=n&&use[temp.f+arr[temp.f]]==false)
		{
			node s;
			s.f=temp.f+arr[temp.f];
			s.k=temp.k+1;
			q.push(s);
			use[s.f]=true;
		}
		if(temp.f-arr[temp.f]>=1&&use[temp.f-arr[temp.f]]==false)
		{
			node s;
			s.f=temp.f-arr[temp.f];
			s.k=temp.k+1;
			q.push(s);
			use[s.f]=true;
		}
	}
	return -1;
}
int main()
{
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		scanf("%d%d",&a,&b);
		for(int i=1;i<=n;i++)
			scanf("%d",&arr[i]);
		memset(use,false,sizeof(use));
		printf("%d\n",BFS());
	}
	return 0;
}
