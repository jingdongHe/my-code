#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
const int maxn=75*2+5;
int main()
{
	int n;
	int a[maxn][maxn];
	int sum[maxn][maxn];
	scanf("%d",&n);
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			a[i+n][j]=a[i][j];
			a[i][j+n]=a[i][j];
			a[i+n][j+n]=a[i][j];
		}
	}
	for(int i=1;i<=2*n;i++)
	{
		for(int j=1;j<=2*n;j++)
		{
			sum[i][j]=sum[i-1][j]+a[i][j];
		}
	}
	int temp[maxn];
	//int temp2[maxn];
	int MAX=-99999;
	for(int i=1;i<=2*n;i++)
	{
		for(int j=i;j<i+n&&j<=2*n;j++)
		{
			int max=-999999;
			int q[maxn];
			memset(q,0,sizeof(q));
			memset(temp,0,sizeof(temp));
			int rear=0,front=0;
			for(int k=1;k<=2*n;k++)
			{
				temp[k]=sum[j][k]-sum[i-1][k];
				temp[k]=temp[k-1]+temp[k];
			}
			for(int k=0;k<=2*n;k++)
			{
				while(rear!=front&&temp[k]<temp[q[rear-1]])
					rear--;
				while(rear!=front&&q[front]<k-n)
					front++;
				q[rear++]=k;
				max=temp[k]-temp[q[front]];
				MAX=MAX>max?MAX:max;
			}
		}
	}
	printf("%d\n",MAX);
	return 0;
}
