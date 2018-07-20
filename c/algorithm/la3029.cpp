#include<stdio.h>
const int maxn=1000+5;
int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}
int min(int a,int b)
{
	if(a<b)
		return a;
	return b;
}
int main()
{
	int T;
	int n,m;
	//ÕÏ°­0£¬¿ÕµØ1
	int i,j;
	int map[maxn][maxn];
	int left[maxn][maxn],right[maxn][maxn],up[maxn][maxn];
	scanf("%d",&T);getchar();
	while(T--)
	{
	scanf("%d%d",&m,&n);getchar();
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			char ch=getchar();
			if(ch=='F')
				map[i][j]=1;
			if(ch=='R')
				map[i][j]=0;
			getchar();
		}
		
	}
	int L,R;
	int ans=0;
	for(i=0;i<m;i++)
	{	L=-1;
		for(j=0;j<n;j++)
		{
			if(!map[i][j])
			{up[i][j]=left[i][j]=0;L=j;}
			else
			{
				up[i][j]=i==0?1:up[i-1][j]+1;
				left[i][j]=i==0?L+1:max(left[i-1][j],L+1);
			}
		}
		R=n;
		for(j=n-1;j>=0;j--)
		{
			if(!map[i][j])
			{right[i][j]=0;R=j;}
			else
			{
				right[i][j]=i==0?R-1:min(R-1,right[i-1][j]);
				ans=max(ans,up[i][j]*(right[i][j]-left[i][j]+1));
			}
		}
	}
	/*for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("(%d,%d,%d) ",up[i][j],left[i][j],right[i][j]);
		}
		printf("\n");
	}*/
	printf("%d\n",ans*3);
	}
	return 0;
}