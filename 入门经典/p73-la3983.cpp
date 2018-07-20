#include<stdio.h>
const int maxn=100000+5;
typedef struct point{
	int x,y,w;
}point;
int main()
{
	int c;
	int n,s[maxn]={0},w[maxn]={0};
	point r[maxn];
	scanf("%d%d",&c,&n);
	r[i].x=r[i].y=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&r[i].x,&r[i].y,&r[i].w);
		s[i]=s[i-1]+(r[i].x-r[i-1].x)+(r[i].y-r[i-1].y);
		w[i]=w[i-1]+r[i].w;
	}
}
