#include<stdio.h>
typedef struct node {
	int money;
	double probability;
}node;
const int maxn=10000+5;
int main()
{
	int m,n;
	while(scanf("%d%d",&n,&m)!=EOF&&(m!=0||n!=0))
	{
		node school[maxn];
		for(int i=1;i<=m;i++)
		{double temp;scanf("%d%lf",&school[i].money,&temp);school[i].probability=1-temp;}
		double p[maxn];
		for(int i=0;i<=n;i++) p[i]=1;
		for(int i=1;i<=m;i++)
		{
			for(int j=n;j>=school[i].money;j--)
			{
				if(p[j]>p[j-school[i].money]*school[i].probability)
					p[j]=p[j-school[i].money]*school[i].probability;
			}
		}
		printf("%.1lf%%\n",(1-p[n])*100);
	}
	return 0;
}
