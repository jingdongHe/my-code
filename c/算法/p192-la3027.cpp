#include<stdio.h>
#include<math.h>
int p[200],d[200];
int find(int x)
{
	if(p[x]!=x)
	{
		d[x]+=d[p[x]];
		return p[x]=find(p[x]);
	}
	return x;
}
int main()
{
	char c;
	int u,v;
	int i,n;
	
	scanf("%d",&n);getchar();
	for(i=0;i<n;i++)
	{
		p[i]=i;d[i]=0;
	}
	while(c=getchar())
	{
		if(c=='o')
			break;
		getchar();
		if(c=='I')
		{
			scanf("%d%d",&u,&v);getchar();
			p[u]=v;d[u]=(abs(u-v))%1000;
		}
		if(c=='E')
		{
			scanf("%d",&u);getchar();
			find(u);
			printf("%d",d[u]);
		}
	}
	return 0;
}