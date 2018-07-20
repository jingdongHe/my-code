#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef struct node {
	int p;
	double l,r;
}node;
bool cmp(node a,node b)
{
	if(a.l==b.l)
		return a.r<b.r;
	return a.l<b.l;
}
const int maxn=10000+5;
int main()
{
	int n,l,w;
	scanf("%d%d%d",&n,&l,&w);
	int p,r;
	node point[maxn];
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&p,&r);
		point[i].p=p;
		double k=sqrt(r*r-w*w/4);
		point[i].l=p-k;
		point[i].r=p+k;
	}
	sort(point,point+n,cmp);
	/*printf("------------------------\n");
	for(int i=0;i<n;i++)
	{
		printf("%d  %lf  %lf\n",i,point[i].l,point[i].r);
	}
	printf("------------------------\n");*/
	double L=0,R=0;
	if(point[0].l>0||point[n-1].r<l)
	{
		printf("-1\n");
		return 0;
	}
	int k=1;
	for(int i=0;i<n;i++)
	{
		if(point[i].l<L)
		{
			if(point[i].r>R)
				R=point[i].r;
		}
		else
		{
			k++;
			i--;
			L=R;
		}
	}
	printf("%d\n",k);
	return 0;
}
