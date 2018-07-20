#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
typedef struct node {
	int b,j;
}node;
bool cmp(node a,node b)
{
	return a.j>b.j;
}
int main()
{
	int n,k=1;
	node *array;
	scanf("%d",&n);
	while(n!=0)
	{
		//构造并输入 
		array=(node *)malloc(sizeof(node)*n);
		for(int i=0;i<n;i++)
			scanf("%d%d",&array[i].b,&array[i].j);
		
		sort(array,array+n,cmp);
		
		int cost=0,start=0;
		for(int i=0;i<n;i++)
		{
			start+=array[i].b;
			cost=cost>start+array[i].j?cost:start+array[i].j;
		}
		printf("Case %d: %d\n",k++,cost);
		scanf("%d",&n);
	}
	return 0;
}
