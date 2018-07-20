#include<stdio.h>
const int maxn=20+2;
int main()
{
	int map[maxn][maxn][maxn];
	int sum[maxn][maxn][maxn]={0};
	int A,B,C;
	int ans=0;
	scanf("%d%d%d",&A,&B,&C);
	for(int i=1;i<=A;i++)
	{
		for(int j=1;j<=B;j++)
		{
			for(int k=1;k<=C;k++)
			{
				scanf("%d",&map[i][j][k]);
			}
		}
	}
	for(int i=1;i<=A;i++)
	{
		for(int j=1;j<=B;j++)
		{
			for(int k=1;k<=C;k++)
			{
				sum[i][j][k]=map[i][j][k]+sum[i-1][j][k];
			}
		}
	}
	/*for(int i=1;i<=A;i++)
	{
		for(int j=1;j<=B;j++)
		{
			for(int k=1;k<=C;k++)
			{
				printf("%d ",sum[i][j][k]);
			}
			printf("\n");
		}
	}*/
	int x,y,z;
	for(int z1=1;z1<=A;z1++)
	{
		for(int z2=z1;z2<=A;z2++)
		{
			//printf("A:%d  %d\n",z1,z2);
			int dim[maxn][maxn];
			for(int i=1;i<=B;i++)
			{
				for(int j=1;j<=C;j++)
				{
					dim[i][j]=sum[z2][i][j]-sum[z1-1][i][j];
				}
			}
			int sum_dim[maxn][maxn]={0};
			for(int i=1;i<=B;i++)
			{
				for(int j=1;j<=C;j++)
				{
					sum_dim[i][j]=dim[i][j]+sum_dim[i-1][j];
				}
			}
			for(int y1=1;y1<=B;y1++)
			{
				for(int y2=y1;y2<=B;y2++)
				{
					//printf("B:%d  %d\n",y1,y2);
					int one[maxn];
					for(int i=1;i<=C;i++)
						one[i]=sum_dim[y2][i]-sum_dim[y1-1][i];
					int sum_one[maxn]={0};
					int max=0,min=0;
					for(int i=1;i<=C;i++)
					{
						sum_one[i]=sum_one[i-1]+one[i];
						if(sum_one[i]>max) max=sum_one[i];
						if(sum_one[i]<min) min=sum_one[i];
					}
					ans=ans>max-min?ans:max-min;
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
