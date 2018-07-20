#include<stdio.h>
int check[101][101]={0};
int m,n;
char a[101][101];
int ok(int i,int j)
{
	if(i>=0&&i<m&&j>=0&&j<n&&check[i][j]!=1&&a[i][j]=='@')
		return 1;
	return 0;
}
void bfs(int i,int j)
{
	check[i][j]=1;
	if(ok(i,j+1))
		bfs(i,j+1);
	if(ok(i+1,j+1))
		bfs(i+1,j+1);
	if(ok(i+1,j))
		bfs(i+1,j);
	if(ok(i+1,j-1))
		bfs(i+1,j-1);
	if(ok(i,j-1))
		bfs(i,j-1);
	if(ok(i-1,j-1))
		bfs(i-1,j-1);
	if(ok(i-1,j))
		bfs(i-1,j);
	if(ok(i-1,j+1))
		bfs(i-1,j+1);
}
int main()
{
	
	int i,j,sum=0;//n为行，i与n匹配；m为列，j与m匹配；a[i][j]
	while(scanf("%d%d",&n,&m)!=EOF&&n!=0&&m!=0)
	{
		for(i=0;i<n;i++)
			scanf("%s",&a[i]);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(ok(i,j))
				{
					sum++;
					bfs(i,j);
				}
			}
		}
		printf("%d\n",sum);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{a[i][j]='\0';check[i][j]=0;}
		sum=0;
	}
	return 0;
}


