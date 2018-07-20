#include<stdio.h>
int map[4][5]={{0,1,2,3,4},{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7}};
int visit[4][5];
int full[8]={0};
int n=0;
void DFS(int i,int j)
{
	if(i<0||i>=4||j<0||j>=5||full[map[i][j]]==1||visit[i][j]==1)
		return;
	full[map[i][j]]=1;
	if(map[i][j]==7)
	{
		full[map[i][j]]=0;
		n++;
		return;
	}
	visit[i][j]=1;
	DFS(i+1,j);
	DFS(i-1,j);
	DFS(i,j+1);
	DFS(i,j-1);
	visit[i][j]=0;
	full[map[i][j]]=0;
	return;
}
int main()
{
	
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
			printf("%d ",map[i][j]);
		printf("\n");
	}
	DFS(0,0);
	printf("%d\n",n);
	return 0;
}