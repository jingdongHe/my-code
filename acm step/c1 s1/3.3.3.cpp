#include<stdio.h>
#include<string.h>
const int maxn=100+5;
const int maxm=100000+5;
typedef struct node {
	int a,c;
}coin;
bool f[maxm];int k;
void zero_one_pack(int cost,int v)
{
	for(int i=v;i>=cost;i--)
	{
		if(f[i-cost]==true)
		{if(f[i]==false)k++;f[i]=true;}
	}
}
void complet_pack(int cost,int v)
{
	for(int i=cost;i<=v;i++)
	{
		if(f[i-cost]==true)
		{if(f[i]==false)k++;f[i]=true;}
	}
}
void multiple_pack(int cost,int amount,int v)
{
	if(cost*amount>=v)
	{complet_pack(cost,v);return;}
	for(int k=1;k<amount;k*=2)
	{
		zero_one_pack(k*cost,v);
		amount=amount-k;
	}
	zero_one_pack(cost*amount,v);
}
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m)&&n&&m)
	{
		coin arr[maxn];k=0;
		memset(f,false,sizeof(f));
		f[0]=true;
		for(int i=1;i<=n;i++)
			scanf("%d",&arr[i].a);
		for(int i=1;i<=n;i++)
			scanf("%d",&arr[i].c);
		for(int i=1;i<=n;i++)
			multiple_pack(arr[i].a,arr[i].c,m);
		printf("%d\n",k);
		/*for(int i=0;i<=m;i++)
			printf("%d ",f[i]);
		printf("\n");*/
	}
	return 0;
}
