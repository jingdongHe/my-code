/*　　　7. 编写程序对八皇后问题进行求解：在8行8列的棋盘上放置8个皇后，
使任一个皇后都不能吃掉其他的7个皇后（注：皇后可吃掉与她处于同行或同列或同一对角线上的其他棋子）
，并将结果以某种方式显示出来。
　　　例如，当求出下述的一个解时，可输出如下信息来表示该解
（输出了表示摆放皇后的坐标位置以及“棋盘状态”— 棋盘中有皇后的位置放一个“Q”字符，其他位置为“+”字符）。*/
#include<stdio.h>
#include<string.h>
int LineNum[9];
bool a[9], b[15], c[15];
void solve(int i, bool& ok)
{
	int k;
	if(i==8)
	{ok=true;return;}
	for(k=0;k<8;k++)
	{
		if(a[k]==true&&b[i+k-2]==true&&c[i-k+7]==true)
		{
			//printf("%d   %d\n",i,k);
			a[k]=false;b[i+k-2]=false;c[i-k+7]=false;
			LineNum[i]=k;
			solve(i+1,ok);
			if(ok==true) return;
			a[k]=true;b[i+k-2]=true;c[i-k+7]=true;
		}
	}
}
int main()
{
	bool ok=false;
	memset(a,true,sizeof(a));
	memset(b,true,sizeof(b));
	memset(c,true,sizeof(c));
	char map[8][8];int i,j;
	memset(map,'+',sizeof(map));
	solve(0,ok);
	for(i=0;i<8;i++)
		map[i][LineNum[i]]='Q';
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
			printf("%c ",map[i][j]);
		printf("\n");
	}
	return 0;
}