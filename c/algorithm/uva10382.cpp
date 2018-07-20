#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
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
	int n;
	int i,k,t;
	double p,r,l,w;
	double L,L1,R;
	node point[10000+5];
	while(scanf("%d%lf%lf",&n,&l,&w)!=EOF)
	{
		t=0;
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf",&p,&r);
			if(w/2>=r)
				continue;
			double k=sqrt(r*r-w*w/4.0);
			point[t].L=p*1.0-k;point[t].R=p*1.0+k;t++;
		}
		L=0;R=l;
		sort(point,point+t,cmp);
		k=0;
		if(point[0].L>0)
		{printf("-1\n");continue;}
		i=0;L1=0;
		bool check=false;
		for(i=0;i<t;i++)
		{
			if(point[i].L<=L)
			{
				check=true;
				if(point[i].R>L1)
					L1=point[i].R;
				if(i==t-1)
				{L=L1;k++;}
			}
			else
			{L=L1;k++;if(check){i--;check=false;}}
		}
		if(L>=R)
			printf("%d\n",k);
		else
			printf("-1\n",k);
	}
	return 0;
}