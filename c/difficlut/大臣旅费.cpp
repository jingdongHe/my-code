#include<stdio.h>
#include<iostream>
using namespace std;
const int INF=999999;
int f(int k)
{
	int ans=0,cnt=1;
	for(int i=1;i<=k;i++)
		ans+=10+cnt++;
	return ans;
}
int main()
{
	int n;
	int **map;
	scanf("%d",&n);
	map=new int *[n+5];
	for(int i=0;i<n+5;i++)
		map[i]=new int[n+5];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) map[i][j]=0;
			else map[i][j]=INF;
		}
	}
	int x,y,c; 
	for(int i=0;i<n-1;i++)
	{
		scanf("%d%d%d",&x,&y,&c);
		map[x][y]=c;
		map[y][x]=c;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(map[i][k]+map[k][j]<map[i][j])
					map[i][j]=map[i][k]+map[k][j];
			}
		}
	}
	int max=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			max=max<map[i][j]?map[i][j]:max;
	}
	printf("%d\n",f(max));
	return 0; 
}
