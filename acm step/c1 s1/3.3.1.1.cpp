#include<stdio.h>
const int maxn=1000+5;
typedef struct node {
	int volume,value;
}bone;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,v;
		bone arr[maxn];
		scanf("%d%d",&n,&v);
		for(int i=1;i<=n;i++)
			scanf("%d",&arr[i].value);
		for(int i=1;i<=n;i++)
			scanf("%d",&arr[i].volume);
		int a[maxn]={0};
		for(int i=1;i<=n;i++)
		{
			for(int j=v;j>=arr[i].volume;j--)
			{
				int k=a[j-arr[i].volume]+arr[i].value;
				if(a[j]<k) a[j]=k;
			}
		}
		printf("%d\n",a[v]);
	}
	return 0;
}
