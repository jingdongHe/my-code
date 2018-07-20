#include<stdio.h>
#include<algorithm>
using namespace std;

typedef struct node {
	int x,y;
}node;
const int maxn=100+5;
bool cmpx(node a,node b)
{
	return a.x<b.x;
}
bool cmpy(node a,node b)
{
	return a.y<b.y;
}
int main()
{
	int n;
	node point[maxn];
	int y[maxn];
	int on[maxn]={0},on2[maxn]={0},left[maxn]={0};
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d",&point[i].x,&point[i].y);
		
		
	sort(point,point+n,cmpy);
	int cnty=0;
	y[cnty++]=point[0].y;
	for(int i=1;i<n;i++)
	{
		if(point[i].y!=point[i-1].y)
			y[cnty++]=point[i].y;
	}
	
	
	sort(point,point+n,cmpx);
	int ans=0;
	for(int a=0;a<cnty-1;a++)
	{
		for(int b=a+1;b<cnty;b++)
		{
			int miny=y[a],maxy=y[b];
			int k=0;
			for(int i=0;i<n;i++)
			{
				if(i==0||point[i].x!=point[i-1].x)
				{
					k++;
					if(k>0) left[k]=left[k-1]+on2[k-1]-on[k-1];
					else left[k]=0;
					on2[k]=on[k]=0;
				}
				if(point[i].y<=maxy&&point[i].y>=miny)
					on2[k]++;
				if(point[i].y<maxy&&point[i].y>miny)
					on[k]++;
			}
			
			int cnt=0;
			printf("%d.........%d...%d\n",miny,maxy,k);
			for(int i=1;i<=k;i++)
			{
				printf("%d:%d   %d   %d\n",i,on[i],on2[i],left[i]);
				ans=ans>left[i]+on2[i]+cnt?ans:left[i]+on2[i]+cnt;
				cnt=cnt>on[i]-left[i]?cnt:on[i]-left[i];
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
