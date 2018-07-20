#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct node {
	int a,b;
}node;
bool cmp(node a,node b)
{
	return a.b-a.a>b.b-b.a;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int v,n;
		scanf("%d%d",&v,&n);
		node goods[1010];
		for(int i=0;i<n;i++)
			scanf("%d%d",&goods[i].a,&goods[i].b);
		sort(goods,goods+n,cmp);
		bool flag=true;
		for(int i=0;i<n;i++)
		{
			if(v>=goods[i].b) v-=goods[i].a;
			else
			{
				flag=false;
				break;
			}
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
