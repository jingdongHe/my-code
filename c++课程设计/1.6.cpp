/*　　　6. 编写程序求解骑士巡游问题：在n行n列的棋盘上（如n=5），假设一位骑士（按象棋中“马走日”的行走法）
从初始坐标位置(x1，y1)出发，要遍访（巡游）棋盘中的每一个位置一次。请编一个程序，为骑士求解巡游“路线图”
（或告诉骑士，从某位置出发时，无法遍访整个棋盘 — 问题无解）。
　　　当n=5时，意味着要在5行5列的棋盘的25个“点”处，按骑士行走规则，
依次将1至25这25个“棋子”（数码）分别摆放到棋盘上（摆满25个位置则成功，否则失败问题无解）。
　　　例如，当n=5且初始坐标位置定为(1，1) — 即最左上角的那个点时，如下是一种巡游“路线图”。
程序执行后的输出结果为：
　　　(x1,y1)? => (1=>5, 1=>5) : 1 1
　　　 1?? 6? 15? 10? 21
　　　 14?? 9? 20?? 5? 16
　　　 19?? 2?? 7? 22? 11
　　　 8? 13? 24? 17?? 4
　　　 25? 18?? 3? 12? 23
　　　提示：
　　　（1）“棋盘”可用二维数组B表示。
　　　（2）编制一个具有如下原型的递归函数solve，用于完成任务：从(i,j)点出发，做第k至第n*n（即n的平方）次的移动
 — 将k直到n的平方这些数码按规则分别摆放到棋盘即数组B中，若成功则通过引用参数ok返回true，否则返回false。
　　　void solve(int i, int j, int k, bool& ok)；
　　　（3）编制主函数，让用户输入作为巡游起点的初始坐标位置(x1,y1)，在该处摆放“棋子”（数码）1，
而后进行调用“solve(x1, y1, 2, ok);”来完成所求任务。*/
#include<stdio.h>
#include<string.h>
int n;
int map[10][10];
int used[10][10];
int dir[][2]={{-2,1},{-2,-1},{2,-1},{2,1},{-1,2},{-1,-2},{1,-2},{1,2}};
void solve(int i,int j,int k,bool &ok)
{
	int a;
	if(ok) return;
	if(k==n*n+1)
	{ok=true;return;}//printf("%d...........\n",k);
	for(a=0;a<8;a++)
	{
		int x=i+dir[a][0],y=j+dir[a][1];
		if(x<0||x>=n||y<0||y>=n)
			continue;
		if(!used[x][y])
		{
			used[x][y]=true;
			map[x][y]=k;
			//printf("(%d,%d),%d\n",x,y,k);
			solve(x,y,k+1,ok);
			if(ok) return;
			used[x][y]=false;
			//map[x][y]=-1;
		}
	}
}
void print()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%-3d",map[i][j]);
		printf("\n");
	}
}
int main()
{
	bool k=false;
	scanf("%d",&n);
	memset(used,false,sizeof(used));
	memset(map,-1,sizeof(map));
	used[0][0]=true;
	map[0][0]=1;
	solve(0,0,2,k);
	if(k)
		print();
	else
		printf("NO WAY\n");
	return 0;
}