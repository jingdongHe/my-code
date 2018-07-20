#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct node {
	int l,r,id;
}node;
int ans[100][2],n;
bool comp(node a,node b)
{
	if(a.l==b.l)
		return a.r<b.r;
	return a.l<b.l;
}
bool ok(node a[],int pos)
{
	int max=0,cur,i;
	for(i=0;i<n;i++)
	{
		if(a[i].r<max)
			return false;
		cur=max>a[i].l?max:a[i].l;
		ans[a[i].id][pos]=cur;
		max=cur+1;
	}
	return true;
}
int main()
{
	int i;
	node A[100],B[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&A[i].l,&B[i].l,&A[i].r,&B[i].r);
		A[i].id=B[i].id=i;
	}
	sort(A,A+n,comp);
	sort(B,B+n,comp);
	if(ok(A,0)&&ok(B,1))
	{
		for(i=0;i<n;i++)
			printf("%d %d\n",ans[i][0],ans[i][1]);
	}
	else
		printf("IMPOSSIBLE\n");
	return 0;
}