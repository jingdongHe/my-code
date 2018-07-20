#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define maxnum 8
int n,m,t,q=0;
void search(char a[][maxnum],int x,int y,int d,int x2,int y2)
{
	//printf("%d...%d\n",x,y);
	if(q==1)
		return;
	if((abs(x-x2)+abs(y-y2)+d>t)||((t-d-abs(x-x2)-abs(y-y2))%2==1)||a[x][y]=='X'||x>=n||x<0||y>=m||y<0||(a[x][y]=='D'&&d!=t))
		return;
	if(a[x][y]=='D'&&d==t)
	{q=1;return ;}
	if(a[x][y]=='.'||a[x][y]=='S')
		a[x][y]='X';
	search(a,x+1,y,d+1,x2,y2);
	search(a,x-1,y,d+1,x2,y2);
	search(a,x,y+1,d+1,x2,y2);
	search(a,x,y-1,d+1,x2,y2);
	if(a[x][y]!='D')
		a[x][y]='.';
	return ;
}
void main()
{
	char a[maxnum][maxnum];
	int i,j;
	int x1,y1,x2,y2;
	scanf("%d%d%d",&n,&m,&t);getchar();
	while(n!=0&&m!=0&&t!=0)
	{
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%c",&a[i][j]);
			if(a[i][j]=='S')
			{x1=i,y1=j;}
			if(a[i][j]=='D')
			{x2=i;y2=j;}
		}getchar();
		
	}
	search(a,x1,y1,0,x2,y2);
	if(q==1)
		printf("YES\n");
	else
		printf("NO\n");
	q=0;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			a[i][j]='\0';
	scanf("%d%d%d",&n,&m,&t);getchar();
	}
}