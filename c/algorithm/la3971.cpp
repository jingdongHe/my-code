#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
typedef struct node {
	char name[25];
	int Type,price,quality;
}node;
char type[1005][25];
int n,b;
int find(char b[])
{
	int i;
	for(i=0;i<1000;i++)
	{
		if(strcmp(type[i],b)==0)
			return i;
		if(type[i][0]=='\0')
		{
			strcpy(type[i],b);
			return i;
		}
	}
	return -1;
}
int type_num()
{
	int i;
	for(i=0;i<1000;i++)
	{
		if(type[i][0]=='\0')
			return i;
	}
	return i;
}
bool cmp1(node a,node b)
{
	return a.quality<b.quality;
}
bool cmp2(node a,node b)
{
	if(a.Type==b.Type)
	{
		if(a.price==b.price)
			return a.quality>b.quality;
		return a.price<b.price;
	}
	return a.Type<b.Type;
}
bool ok(int m,node acc[])//品质因子=m时是否可组建
{
	int i,j;
	node acc2[1005];
	sort(acc,acc+n,cmp1);
	/*printf("%d:\n",m);
	for(i=0;i<n;i++)
		printf("%d->%s:%d   %d\n",acc[i].Type,acc[i].name,acc[i].price,acc[i].quality);*/
	for(i=0,j=0;i<n;i++)
	{
		if(acc[i].quality>=m)
		{	
			acc2[j++]=acc[i];
		}
	}
	sort(acc2,acc2+j,cmp2);
	/*printf("----------------------------\n");
	for(i=0;i<j;i++)
		printf("%d->%s:%d   %d\n",acc2[i].Type,acc2[i].name,acc2[i].price,acc2[i].quality);*/
	int money=0,d=-1;
	for(i=0;i<j;i++)
	{
		if(d!=acc2[i].Type)
		{
			d++;money+=acc2[i].price;
		}
	}
	if(d==type_num()-1&&money<=b)
		return true;
	return false;
}
int main()
{
	node acc[1005];
	char a[25];
	int i,t,T;
	scanf("%d",&T);
	for(t=0;t<T;t++)
	{
		int L=9999,R=-1;
		scanf("%d%d",&n,&b);
		memset(type,'\0',sizeof(type));
		for(i=0;i<n;i++)
		{
			scanf("%s%s%d%d",&a,&acc[i].name,&acc[i].price,&acc[i].quality);
			acc[i].Type=find(a);
			L=L<acc[i].quality?L:acc[i].quality;
			R=R>acc[i].quality?R:acc[i].quality;
		}
		//以上为初始化
		while(L<R)
		{
			int M=L+(R-L+1)/2;
			if(ok(M,acc)) L=M;else R=M-1;
			//printf("===========================================\n");
		}
		printf("%d\n",L);
	}
	return 0;
}