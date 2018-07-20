#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn=20+5;
const int INF=99;
int main()
{
	int w,d;
	int h1[maxn],h2[maxn];
	int h[maxn][maxn];
	int i,j;
	while(scanf("%d%d",&w,&d)&&w&&d)
	{
		memset(h,0,sizeof(h));
		for(i=0;i<w;i++)
			scanf("%d",&h1[i]);
		for(i=0;i<d;i++)
			scanf("%d",&h2[i]);
		sort(h2,h2+d);sort(h1,h1+w);
		int sum=0,f;
		int k=1;
		for(j=0;j<w;j++)
		{
			if(h2[0]>h1[j])
			{sum+=h1[j];h[0][j]=h1[j];h1[j]=INF;}
			else if(h2[0]==h1[j])
			{sum+=h1[j];h[0][j]=h1[j];h1[j]=INF;k=0;break;}
			else
				break;
		}//结束后，j都是>=h2[0]
		if(k) {sum+=h2[0];h[0][w-1]=h2[0];}
		for(i=1;i<d;i++)
		{
			if(i==d-1)
			{
				for(j=0;j<w;j++)
				{
					if(h1[j]!=INF)
					{h[i][j]=h1[j];sum+=h1[j];}
				}
			}
			else
			{
				int k=1;
				for(j=0;j<w;j++)
				{
					if(h1[j]<h2[i])
					{h[i][j]=h1[j];sum+=h1[j];h1[j]=INF;}
					if(h1[j]==h2[i])
					{h[i][j]=h1[j];sum+=h1[j];h1[j]=INF;k=0;f=j;break;}
				}
				if(k) {h[i][w-1]=h2[i];sum+=h2[i];f=j;}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}