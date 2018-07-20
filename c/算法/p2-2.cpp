#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct node {
	int b,j;//b½»´ú£¬jÖ´ÐÐ
}node;
int comp(node x,node y)
{
	return x.j>y.j;
}
int main()
{
	int i,n;
	node A[1000];
	int cost,start;
	scanf("%d",&n);
	while(n!=0)
	{
		for(i=0;i<n;i++)
			scanf("%d%d",&A[i].b,&A[i].j);
		sort(A,A+n,comp);
		cost=0;start=0;
		for(i=0;i<n;i++)
		{
			start+=A[i].b;
			if(cost<start+A[i].j)
				cost=start+A[i].j;
		}
		printf("%d\n",cost);
		scanf("%d",&n);
	}
	return 0;
}
		