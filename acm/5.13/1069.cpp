#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=250;
typedef struct node {
	int x,y,z;
}node;
bool cmp(node a,node b)//保证b一定是在a的下面 
{
	/*if(b.x>a.x&&b.y>a.y) return true;
	else if(b.y>a.x&&b.x>a.y) return true;
	else if(b.x==a.x&&b.y>a.y) return true;
	else if(b.x==a.y&&b.y>a.x) return true;
	else if(b.y==a.x&&b.x>a.y) return true;
	else if(b.x==a.y&&b.y>a.x) return true;
	return false;*/
	return a.x*a.y<b.x*b.y;
}
int main()
{
	int n,f=1;
	while(scanf("%d",&n)&&n)
	{
		int a,b,c;
		int k=0;
		node block[maxn];
		int dp[maxn];
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			block[k].x=a;block[k].y=b;block[k++].z=c;
			block[k].x=c;block[k].y=a;block[k++].z=b;
			block[k].x=b;block[k].y=c;block[k++].z=a;
			block[k].x=b;block[k].y=a;block[k++].z=c;
			block[k].x=a;block[k].y=c;block[k++].z=b;
			block[k].x=c;block[k].y=b;block[k++].z=a;
		}
		sort(block,block+k,cmp);
		for(int i=0;i<k;i++)
			dp[i]=block[i].z;
		for(int i=1;i<k;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(block[i].x>block[j].x&&block[i].y>block[j].y)
				{
					if(dp[i]<block[i].z+dp[j])
						dp[i]=block[i].z+dp[j];
				}
			}
		}
		int sum=0;
		for(int i=0;i<k;i++)
		{
			sum=sum<dp[i]?dp[i]:sum;
		}
		printf("Case %d: maximum height = %d\n",f++,sum);
	}
	return 0;
}
