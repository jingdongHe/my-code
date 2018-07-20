#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct node {
	int x,y;
}node;
int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}
bool com(node x,node y)
{
	return x.x<y.x;
}
int main()
{
	int i,j,k,n;
	node map[100];
	int y[100];
	int Max,Min,ans=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{scanf("%d%d",&map[i].x,&map[i].y);y[i]=map[i].y;}
	sort(map,map+n,com);
	sort(y,y+n);
	/*for(i=0;i<n;i++)
		printf("%d...%d....%d\n",map[i].x,map[i].y,y[i]);*/
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			Max=y[j];Min=y[i];
			int s=0;
			int left[100],on[100],on2[100];
			for(k=0;k<n;k++)
			{
				if(k==0||map[k].x!=map[k-1].x)
				{s++;on[s]=on2[s]=0;left[s]=k==0?0:left[s-1]+on2[s-1]-on[s-1];}
				if(map[k].y<Max&&map[k].y>Min)on[s]++;
				if(map[k].y<=Max&&map[k].y>=Min)on2[s]++;
			}
			int m=0;
			for(k=1;k<=s;k++)
			{
				//printf("%d,%d,%d:%d   %d    %d\n",i,j,k,on[k],on2[k],left[k]);
				ans=max(ans,left[k]+on2[k]+m);
				//printf("%d\n",ans);
				m=max(m,on[k]-left[k]);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}