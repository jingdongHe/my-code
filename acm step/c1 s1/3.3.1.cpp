#include<stdio.h>
#include<string.h>
typedef struct node {
	int value,volume;
}bone;
const int maxn=1000+5;
int a[maxn][maxn];
int max(int a,int b)
{
	if(a>b) return a;
	return b;
}
int main()
{
	int t;
	bone arr[maxn];
	scanf("%d",&t);
	while(t--)
	{
		int n,v;
		memset(a,0,sizeof(a));
		scanf("%d%d",&n,&v);
		for(int i=1;i<=n;i++)
			scanf("%d",&arr[i].value);
		for(int i=1;i<=n;i++)
			scanf("%d",&arr[i].volume);
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=v;j++)
			{
				if(j>=arr[i].volume)
					a[i][j]=a[i-1][j-arr[i].volume]+arr[i].value;
				if(a[i][j]<a[i-1][j]) a[i][j]=a[i-1][j];
			}
		}
		printf("%d\n",a[n][v]);
	}
}
