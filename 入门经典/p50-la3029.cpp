#include<stdio.h>
const int maxn=100+5;
int main()
{
	int m,n;
	int map[maxn][maxn];
	int left[maxn][maxn],right[maxn][maxn],up[maxn][maxn];
	scanf("%d%d",&m,&n);getchar();
	char ch;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			ch=getchar();getchar();
			map[i][j]=ch=='F'?0:1;
		}
		//getchar();
	}
	/*for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",map[i][j]);
		}
		printf("\n");
	}*/
	for(int i=0;i<m;i++)
	{
		int L=-1,R=n;
		for(int j=0;j<n;j++)
		{
			if(map[i][j]==1)
			{
				up[i][j]=left[i][j]=0;
				L=j;
			}
			else
			{
				if(i==0)
				{
					up[i][j]=1;
					left[i][j]=L+1;
				}
				else
				{
					up[i][j]=up[i-1][j]+1;
					left[i][j]=L+1>left[i-1][j]?L+1:left[i-1][j];
				}
			}
		}
		for(int j=n-1;j>=0;j--)
		{
			if(map[i][j]==1)
			{
				right[i][j]=n-1;
				R=j;
			}
			else
			{
				if(i==0) right[i][j]=R-1;
				else right[i][j]=R-1<right[i-1][j]?R-1:right[i-1][j];
			}
		}
	}
	int cnt=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			int area=up[i][j]*(right[i][j]-left[i][j]+1);
			cnt=cnt>area?cnt:area;
			printf("(%d,%d,%d)  ",up[i][j],left[i][j],right[i][j]);
		}
		printf("\n");
	}
	printf("%d\n",cnt*3);
	return 0;
} 
