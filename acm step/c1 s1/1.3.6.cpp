#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct node {
	int p,m;
}node;
bool cmp(node a,node b)
{
	return a.p>b.p;
}
int main()
{
	int v,n;
	while(scanf("%d",&v)!=EOF&&v!=0)
	{
		scanf("%d",&n);
		node goods[110];
		for(int i=0;i<n;i++)
			scanf("%d%d",&goods[i].p,&goods[i].m);
		sort(goods,goods+n,cmp);
		int k=0;
		for(int i=0;i<n;i++)
		{
			if(v>=goods[i].m)
			{
				k+=goods[i].m*goods[i].p;
				v-=goods[i].m;
			} 
			else 
			{
				k+=goods[i].p*v;
				v=0;break;
			}
		}
		printf("%d\n",k);
	}
	
}
