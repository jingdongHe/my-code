#include<stdio.h>
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
	
	int m,n;int i,j;
	char ch;
	int L,R;
	int Map[1000][1000];
	int left[1000][1000],right[1000][1000],down[1000][1000];
	int ans=0;
	scanf("%d%d",&m,&n);getchar();
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			
			scanf("%c",&ch);
			Map[i][j]=ch=='F'?0:1;
		}
		getchar();
	}
	for(i=0;i<m;i++)
	{
		L=-1;R=n;
		for(j=0;j<n;j++)
		{
			if(Map[i][j]==1)
			{down[i][j]=left[i][j]=0;L=j;}
			else
			{
				down[i][j]=i==0?1:down[i-1][j]+1;
				left[i][j]=i==0?L+1:max(left[i-1][j],L+1);
			}
		}
		for(j=n-1;j>=0;j--)
		{
			if(Map[i][j]==1)
			{right[i][j]=R-1;R=j;}
			else
			{
				right[i][j]=i==0?R-1:min(R-1,right[i-1][j]);
				ans=max(ans,down[i][j]*(right[i][j]-left[i][j]+1));
			}
		}
	}
	/*for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("[%d][%d]:%d   %d    %d\n",i,j,up[i][j],left[i][j],right[i][j]);
		}
		printf("\n\n");
	}*/
	printf("%d\n",ans*3);
	/*for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",Map[i][j]);
		}
		printf("\n");
	}*/
	return 0;
}
