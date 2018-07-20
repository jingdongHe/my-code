#include<stdio.h>
int a[10][10];
int visit[10][10];
//int c[20];
int n,m;
int s=1000;int k;
/*void print(int a[],int k)
{
	int i;
	for(i=0;i<k;i++)
		printf("%d ",a[i]);
	printf("\n");
}*/
void DFS(int i,int j,int d,int q)
{
	if(i<0||i>=m||j<0||j>=n||visit[i][j]==1)
		return;
//	c[q]=a[i][j];
	if(d>=k)
	{
		if(d==k&&q<s)
		{
			s=q+1;
			//print(c,q);
		}
		return;
	}	
	visit[i][j]=1;
	DFS(i+1,j,d+a[i+1][j],q+1);
	DFS(i-1,j,d+a[i-1][j],q+1);
	DFS(i,j+1,d+a[i][j+1],q+1);
	DFS(i,j-1,d+a[i][j-1],q+1);
	visit[i][j]=0;
	return;
}
int main()
{
	
	int i,j;
	int d;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			k+=a[i][j];
		}
	}
	k=k/2;d=a[0][0];
	DFS(0,0,d,0);
	printf("%d\n",s);
}