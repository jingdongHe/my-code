#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef struct node {
	double l,r;
}node;
bool comp(node x,node y)
{
	if(x.l==y.l)
		return x.r>y.r;
	return x.l<y.l;
}
int main()
{
	int n,l,w,i,r,loc,maxn,ans;
	double left,right,max;
	node A[10000];
	while(scanf("%d%d%d",&n,&l,&w))
	{
		left=0;right=l*1.0;ans=0;max=0;maxn=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&loc,&r);
			A[i].l=loc-sqrt(1.0*r*r-(w*1.0/2)*(w*1.0/2));
			A[i].r=2*loc-A[i].l;
		}
		sort(A,A+n,comp);
		//for(i=0;i<n;i++)
		//	printf("%lf.....%lf\n",A[i].l,A[i].r);
		//printf("\n");
		i=0;
		if(A[0].l>left)
		{
			printf("-1\n");
			continue;
		}
		while(left<right)
		{
			if(i==n)
				break;
			max=0;
			for(;i<n;i++)
			{
				if(A[i].l>left)
					break;
				if(max<A[i].r-A[i].l)
				{max=A[i].r-A[i].l;maxn=i;}
				
			}
			left=A[maxn].r;ans++;
			
			//printf("%lf     %lf\n",left,right);
		}
		if(left>=right)
			printf("%d\n",ans);
		else
			printf("-1\n");
	}
	return 0;
}
