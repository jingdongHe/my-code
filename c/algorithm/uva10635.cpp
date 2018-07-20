#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn=250*250;
int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}
int main()
{
	int t,T;int i,j;int n,p,q;int x;
	int s[maxn]={0},g[maxn]={0},d[maxn]={0},num[maxn]={0};
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d%d%d",&n,&p,&q);
		
		memset(num,0,sizeof(num));
		for(i=1;i<=p+1;i++)
		{scanf("%d",&x);num[x]=i;}
		int k=0;
		for(j=0;j<=q;j++)
		{
			scanf("%d",&x);
			if(num[x])
				s[k++]=num[x];
		}
		for(i=1;i<=k;i++)
			g[i]=999999;
		int ans=0;
		for(i=0;i<k;i++)
		{
			int a=lower_bound(g+1,g+n+1,s[i])-g;
			d[i]=a;
			g[a]=s[i];
			ans=max(ans,d[i]);
		}
		printf("Case %d: %d\n",t,ans);
	}
	return 0;
}
