/*　　　9. 编一棋盘游戏程序，人为一方，计算机为一方，人下时字符 * 将放在所指定的位置，
而计算机下时字符 @ 将放在某一空格位置。行、列、或两对角线有连续三个相同字符一方为胜方，
也有平局情况。要求能动态演示。
*/
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<time.h>
const int n=3;
char map[3][3];
void print()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%c ",map[i][j]);
		printf("\n");
	}
}
int win()
{
	int i;
	for(i=0;i<n;i++)
	{
		if(map[i][0]=='*'&&map[i][1]=='*'&&map[i][2]=='*')
			return 1;
		if(map[0][i]=='*'&&map[1][i]=='*'&&map[2][i]=='*')
			return 1;
		if(map[i][0]=='@'&&map[i][1]=='@'&&map[i][2]=='@')
			return -1;
		if(map[0][i]=='@'&&map[1][i]=='@'&&map[2][i]=='@')
			return -1;
	}
	if(map[0][0]=='*'&&map[1][1]=='*'&&map[2][2]=='*')
		return 1;
	if(map[0][2]=='*'&&map[1][1]=='*'&&map[2][0]=='*')
		return 1;
	if(map[0][0]=='@'&&map[1][1]=='@'&&map[2][2]=='@')
		return -1;
	if(map[0][2]=='@'&&map[1][1]=='@'&&map[2][0]=='@')
		return -1;
	return 0;
}
void jiqixiaqi()
{
	int d=rand()%9;
	while(map[d/n][d%n]!=' ')
		d=rand()%9;
	map[d/n][d%n]='@';
}
int xiaqi()
{
	int i;
	for(i=0;i<5;i++)
	{
		int d;
		scanf("%d",&d);
		d--;
		if(map[d/n][d%n]!=' ')
		{
			i--;
			printf("The point have set,please entry the another point\n");
			continue;
		}
		map[d/n][d%n]='*';
		system("cls");
		print();
		if(win()==1)
		{printf("You win\n");return 0;}
		if(win()==-1)
		{printf("Computer win\n");return 0;}
		if(i<4)
		{
			jiqixiaqi();
			system("cls");
			print();
			if(win()==1)
			{printf("You win\n");return 0;}
			if(win()==-1)
			{printf("Computer win\n");return 0;}
		}
	}
	return 1;
}
int main()
{
	memset(map,' ',sizeof(map));
	srand((unsigned)time(NULL));
	if(xiaqi())
		printf("Draw\n");
	return 0;
}
