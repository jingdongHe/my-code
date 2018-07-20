#include<stdio.h>
#include<algorithm>
using namespace std;
struct node{
	int d,l,r;
};
bool cmp(node a,node b)
{
	return a.d<b.d;
}
node targe[5000+10];
int T,w,n;
int ok(double d)
{
	double L1,R1,L=(targe[0].l-d)*1.0/targe[0].d,R=(targe[0].r-d)*1.0/targe[0].d;
	int i;
	for(i=1;i<n;i++)
	{
		L1=(targe[i].l-d)*1.0/targe[i].d;
		R1=(targe[i].r-d)*1.0/targe[i].d;
		if(R<L1)
			return 1;
		if(R1<L)
			return -1;
		if(L1>L)
			L=L1;
		if(R1<R)
			R=R1;
	}
	return 0;
}
int main()
{
	
	scanf("%d",&T);
	while(T--)
	{
		int i;
		scanf("%d",&w);
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d%d%d",&targe[i].d,&targe[i].l,&targe[i].r);
		sort(targe,targe+n,cmp);
		double L=0,R=w;
		int res;
		while(R-L>1e-3)
		{
			double m=(L+R)*1.0/2;
			res=ok(m);
			if(res==0)
			{printf("YES\n");break;}
			else if(res==-1) L=m;
			else R=m;
		}
		if(res!=0)
			printf("NO\n");
	}	
	return 0;
}