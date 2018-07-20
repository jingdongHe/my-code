#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=100;
typedef struct node {
	int x,y;
}node;
bool cmp(node a,node b)
{
	if(a.x==b.x)
		return a.y<b.y;
	return a.x<b.x;
}
int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}
int main()
{
	int T=0,n,i,j,k,ans;
	int y[maxn];
	node seq[maxn];
	int on[maxn],on2[maxn],left[maxn];
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++)
		{scanf("%d%d",&seq[i].x,&seq[i].y);y[i]=seq[i].y;}
		sort(y,y+n);ans=0;
		int m=0;//用于计数有多少不同的j
		for(i=0;i<n;i++)
		{
			if(y[i]!=y[i+1])
				y[m++]=y[i];
		}
		if(m<2)
		{ans=n;printf("Case %d: %d\n",++T,ans);continue;}
		sort(seq,seq+n,cmp);
		for(i=0;i<m;i++)
		{
			for(j=i+1;j<m;j++)
			{
				int d=0;
				for(k=0;k<n;k++)
				{
					if(k==0||seq[k].x!=seq[k-1].x)
					{
						d++;
						on[d]=on2[d]=0;//第d条竖线
						left[d]=k==0?0:left[d-1]+on2[d-1]-on[d-1];
						
					}
					if(seq[k].y>y[i]&&seq[k].y<y[j])
						on[d]++;
					if(seq[k].y>=y[i]&&seq[k].y<=y[j])
						on2[d]++;
				}
				if(d<2)
				{i=m;ans=n;break;}
				int m=0;
				for(k=1;k<=d;k++)
				{
					ans=max(ans,left[k]+on2[k]+m);
					m=max(m,on[k]-left[k]);
				}
			}
		}
		printf("Case %d: %d\n",++T,ans);
	}
	return 0;
}