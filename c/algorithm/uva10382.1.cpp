#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
const int maxn=10000+5;
typedef struct node {
	double L,R;
}node;
bool cmp(node a,node b)
{
	if(a.L==b.L)
		return a.R>b.R;
	return a.L<b.L;
}
int main()
{
	int n,tn;
	double l,w;
	double p,r;
	node point[maxn];
	while(scanf("%d%lf%lf",&n,&l,&w)!=EOF)
	{
		tn=0;
		while(n--)
		{
			scanf("%lf%lf",&p,&r);
			if(w/2>=r)
				continue;
			double k=sqrt(r*r-w*w/4);
			point[tn].L=p-k;point[tn++].R=p+k;
		}
		sort(point,point+tn,cmp);
		int i,L=0,R=0,k=0;
		bool check=false;
		for(i=0;i<tn;i++)
		{
			if(point[i].L<=L)
			{
				check=true;
				if(point[i].R>R)
					R=point[i].R;
				if(i==tn-1)
				{L=R;k++;R=0;}
			}
			else
			{L=R;k++;if(check) i--;}
		}
		if(L>=R)
			printf("%d\n",k);
		else
			printf("-1\n");
	}
	return 0;
}


