/*������8. ��һ�Թ���Ϸ�����Թ��������û�����ͳ����Զ��������ַ�ʽ(�Թ��Ծ����ʾ)��Ҫ������Թ����߳��Թ���·����*/
/*������Ŀ����������̫�٣��ڴ˶����Թ���СΪ10*10,sΪ��ʼλ�ã�eΪ���ڣ�*Ϊǽ���������߹��ĵط�����oΪ���ߵĵط�*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
int dir[][2]={{1,0},{-1,0},{0,1},{0,-1}};
char map[10][10];
bool used[10][10];
typedef struct node {
	int x,y;
}node;
node point[100];
int d=0;
bool ok=false;
void DFS(int x,int y,bool &ok)
{
	int i;
	if(ok) return;
	for(i=0;i<4;i++)
	{
		int a=x+dir[i][0],b=y+dir[i][1];
		if(a<0||a>=10||b<0||b>=10||map[a][b]=='*')
			continue;
		if(used[a][b]==true)
			continue;
		if(map[a][b]=='e')
		{ok=true;return;}
		if(map[a][b]=='o')
		{
			point[d].x=a;point[d++].y=b;
			used[a][b]=true;
			DFS(a,b,ok);
			if(ok) return;
			d--;
			used[a][b]=false;
		}
	}
}
void print()
{
	int i,j;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
			printf("%c ",map[i][j]);
		printf("\n");
	}
}
void print_result()
{
	int i;
	for(i=0;i<d;i++)
		printf("(%d,%d)",point[i].x,point[i].y);
	printf("\n");
}
void bulid()//�ɼ����������ͼ
{
	srand((unsigned)time(NULL));
	int x,y;
	int xe,ye;
	x=rand()%10;y=rand()%10;
	xe=rand()%10;ye=rand()%10;
	map[xe][ye]='e';map[x][y]='s';
	point[d].x=x;point[d++].y=y;
	int i,j;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(map[i][j]!='s'&&map[i][j]!='e')
			{
				int d=rand()%4;
				if(d!=3)
					map[i][j]='o';
				else
					map[i][j]='*';
			}
		}
	}
	DFS(x,y,ok);
	point[d].x=xe;point[d++].y=ye;
}
int main()
{
	memset(map,'o',sizeof(map));
	memset(used,false,sizeof(used));
	int x,y;
	int xe,ye;
	int i,j;
	printf("1���ֶ������Թ�   2������������Թ�\n");
	int d;
	scanf("%d",&d);
	if(d==1)
	{
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				scanf("%c",&map[i][j]);
				if(map[i][j]=='s')
				{x=i;y=j;}
				if(map[i][j]=='e')
				{xe=i;ye=j;}
			}
		}
		point[d].x=x;point[d++].y=y;
		DFS(x,y,ok);
		point[d].x=xe;point[d++].y=ye;
	}
	else
		bulid();
	print();
	if(ok)
		print_result();
	else
		printf("NO WAY\n");
	return 0;
}