#include<stdio.h>
#include<math.h>
int movex[]={1,-1,0,0},movey[]={0,0,1,-1};//移动方向
int m,n,t,d=0;//输入控制
int k;//用于判断是否满足题目条件
int sx,sy,dx,dy,st,wallnumber=0;//起始点标记，终点标记，时间标记,墙的数量
char mi[7][7];//迷宫
void main()
{
	int i,j;
	void dfs(int sx,int sy,int st);//定义dfs
	while(scanf("%d%d%d",&n,&m,&t)!=EOF)
	{
		if(m==0&&n==0&&t==0)
			break;
		getchar();
		for(j=0;j<n;j++)
		{
			for(i=0;i<m;i++)
				scanf("%c",&mi[i][j]);
			getchar();
		}//j为列，i为行,录入迷宫矩阵
		for(j=0;j<n;j++)
		{
			for(i=0;i<m;i++)
			{
				if(mi[i][j]=='s')
				{sx=i;sy=j;}
				if(mi[i][j]=='d')
				{dx=i;dy=j;}
				if(mi[i][j]=='x')
					wallnumber++;
			}
		}//读入标记
		//printf("%d:%d  %d....%d   %d\n",wallnumber,sx,sy,dx,dy);
		if(n*m-wallnumber>=t)
			dfs(sx,sy,0);
		if(k==1)
			printf("yes\n");
		else
			printf("no\n");
		k=0;
		for(j=0;j<n;j++)
			for(i=0;i<m;i++)
				mi[i][j]='\0';
		printf("%d",d);
	}
}
void dfs(int sx,int sy,int st)
{
	int i,time;
	d++;
	printf("%d:%d    %d\n",st,sx,sy);
	if(sx==dx&&sy==dy&&st==t)
		k=1;
	time=t-st-abs(sx-dx)-abs(sy-dy);
	if(time<0||time%2!=0)
		return;
	for(i=0;i<4;i++)
	{
		if(sx+movex[i]>m-1||sx+movex[i]<0||sy+movey[i]>n-1||sx+movey[i]<0)
			continue;
		if(mi[sx+movex[i]][sy+movey[i]]!='x')
		{
			mi[sx+movex[i]][sy+movey[i]]='x';
			dfs(sx+movex[i],sy+movey[i],st+1);
			mi[sx+movex[i]][sy+movey[i]]='.';
		}
		if(k==1)
			break;
	}
}
