#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct node {
	int x,y;
}node;
const int maxn=1000+5;
const int INF=999999999;
int n,w,v;
node p[maxn];
bool is_ok(int s)
{
	double L=0,R=INF;
	double l,r;
	for(int i=0;i<n-1;i++)
	{
		L=L>p[i].x?L:p[i].x;
		R=R<p[i].x+w?R:p[i].x+w;
		double t=(p[i+1].y-p[i].y)*1.0/s;
		L-=v*t;R+=v*t;
		if(L>p[i+1].x+w||R<p[i+1].x)
			return false;
	}
	return true;
}
int main()
{
	int S,s[10000+5];
	scanf("%d%d%d",&w,&v,&n);
	for(int i=0;i<n;i++)
		scanf("%d%d",&p[i].x,&p[i].y);
	scanf("%d",&S);
	for(int i=0;i<S;i++)
		scanf("%d",&s[i]);
	int k=-1;
	for(int i=0;i<S;i++)
	{
		if(is_ok(s[i])) k=k>s[i]?k:s[i];
	}
	if(k==-1) printf("IMPOSSIBLE\n");
	else printf("%d\n",k);
	return 0;
}
