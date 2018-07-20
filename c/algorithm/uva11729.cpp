#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct node {
	int b,j;
	bool operator < (const node &x) const {
		if(x.j==j)
			return b<x.b;
		return j>x.j;
	}
}node;
int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}
int main()
{
	node a[1000];
	int i,n,k=0;
	while(scanf("%d",&n)!=EOF&&n)
	{
		k++;
		for(i=0;i<n;i++)
			scanf("%d%d",&a[i].b,&a[i].j);
		sort(a,a+n);
		int ans=0,s=0;
		for(i=0;i<n;i++)
		{
			s+=a[i].b;
			ans=max(ans,s+a[i].j);
		}
		printf("Case %d: %d\n",k,ans);
	}
	return 0;
}