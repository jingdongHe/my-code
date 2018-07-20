#include<stdio.h>
char map[10][10];
int t=0;
bool falg;
struct node {
	int x,y;
};
node local[90];
bool is_ok(int p,char c)
{
	for(int i=0;i<9;i++)
	{
		if(map[local[p].x][i]==c)
			return false;
		if(map[i][local[p].y]==c)
			return false;
	}
	int tx=local[p].x/3,ty=local[p].y/3;
	for(int i=tx*3;i<(tx+1)*3;i++)
	{
		for(int j=ty*3;j<(ty+1)*3;j++)
			if(map[i][j]==c)
				return false;
	}
	return true;
}
void dfs(int p,int s)
{
	if(falg) return;
	if(p>t) return;
	if(s==t)
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
				printf("%c ",map[i][j]);
			printf("\n");
		}
		falg=true;
		return;
	}
	for(char k='1';k<='9';k++)
	{
		if(is_ok(p,k))
		{
			map[local[p].x][local[p].y]=k;
			dfs(p+1,s+1);
			map[local[p].x][local[p].y]='?';
		}
	}
	return;
}
int main()
{
	int Case=0;
	while(scanf("%c",&map[0][0])!=EOF)
	{
		while(map[0][0]=='\n'||map[0][0]==' ')
			scanf("%c",&map[0][0]);
		getchar();t=0;falg=false;
		if(map[0][0]=='?')
		{local[t].x=0;local[t++].y=0;}
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				if(i==0&&j==0) continue;
				scanf("%c",&map[i][j]);
				if(map[i][j]=='?') {local[t].x=i;local[t].y=j;t++;}
				getchar();
				
			}
		}
		if(Case++) printf("\n");
		dfs(0,0);
	}
	return 0;
}
