#include<stdio.h>
const int maxn=20;
int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}
int main()
{
	int Heap[maxn][maxn][maxn];
	int Heap_sum[maxn][maxn][maxn];//三维的每个竖条的和
	int D[maxn][maxn],D_sum[maxn][maxn];
	int A,B,C;
	int ans=0;
	scanf("%d%d%d",&A,&B,&C);
	int i,j,k;
	for(i=0;i<A;i++)
	{
		for(j=0;j<B;j++)
		{
			for(k=0;k<C;k++)
			{
				scanf("%d",&Heap[i][j][k]);
				if(i==0)
					Heap_sum[i][j][k]=Heap[i][j][k];
				else
					Heap_sum[i][j][k]=Heap_sum[i-1][j][k]+Heap[i][j][k];
			}
		}
	}
	int z1,z2,y1,y2,x,y;
	for(z1=0;z1<A;z1++)
	{
		for(z2=z1+1;z2<A;z2++)
		{
			for(y=0;y<B;y++)
			{
				for(x=0;x<C;x++)
					D[y][x]=Heap_sum[z2][y][x]-Heap_sum[z1][y][x];
			}//已把立体的z1-z2之间的压为平面
			for(y=0;y<B;y++)
			{
				for(x=0;x<C;x++)
				{
					if(y==0)
						D_sum[y][x]=D[y][x];
					else
						D_sum[y][x]=D[y][x]+D_sum[y-1][x];
				}
			}//得出平面的竖列的和
			//取最上层一行，即y==B-1，x form 0 to C-1
			int D_sum2[maxn],D_sum3[maxn];
			for(y1=0;y1<B;y1++)
			{
				for(y2=y1+1;y2<B;y2++)
				{
					for(x=0;x<C;x++)
						D_sum2[x]=D_sum[y2][x]-D_sum[y1][x];
					for(x=0;x<C;x++)
					{
						if(x==0)
							D_sum3[x]=D_sum2[x];
						else
							D_sum3[x]=max(D_sum2[x]+D_sum3[x-1],D_sum2[x]);
					}
					for(x=0;x<C;x++)
						ans=ans>D_sum2[x]?ans:D_sum2[x];
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}

