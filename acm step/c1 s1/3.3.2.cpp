#include<stdio.h>
#include<string.h>
typedef struct node {
	int p,w;
}coin;
const int maxn=500+5;
const int INF=999999;
int a[10000+5];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int e,f;
		scanf("%d%d",&e,&f);
		int v=f-e;
		int n;
		scanf("%d",&n);
		coin arr[maxn];
		for(int i=1;i<=n;i++)
			scanf("%d%d",&arr[i].p,&arr[i].w);
		for(int j=1;j<=v;j++) a[j]=-INF;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=v;j++)
			{
				for(int k=0;k<=(int)(j/arr[i].w);k++)
				{
					int f=a[j-k*arr[i].w]+arr[i].p*k;
					if(f<0) continue;
					else if(f<a[j]||a[j]==-INF) a[j]=f;
				}
			}
		}
		if(a[v]!=-INF)
			printf("The minimum amount of money in the piggy-bank is %d.\n",a[v]);
		else
			printf("This is impossible.\n");
	}
	return 0;
}
