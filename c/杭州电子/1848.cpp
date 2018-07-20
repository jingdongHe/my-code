/*任何一个大学生对菲波那契数列(Fibonacci numbers)应该都不会陌生，它是这样定义的：
F(1)=1;
F(2)=2;
F(n)=F(n-1)+F(n-2)(n>=3);
所以，1,2,3,5,8,13……就是菲波那契数列。
在HDOJ上有不少相关的题目，比如1005 Fibonacci again就是曾经的浙江省赛题。
今天，又一个关于Fibonacci的题目出现了，它是一个小游戏，定义如下：
1、  这是一个二人游戏;
2、  一共有3堆石子，数量分别是m, n, p个；
3、  两人轮流走;
4、  每走一步可以选择任意一堆石子，然后取走f个；
5、  f只能是菲波那契数列中的元素（即每次只能取1，2，3，5，8…等数量）；
6、  最先取光所有石子的人为胜者；

假设双方都使用最优策略，请判断先手的人会赢还是后手的人会赢。*/
#include<stdio.h>
#include<string.h>
int f[16],g[1010];
void fibonacci()
{
	int i;
	f[1]=1;f[2]=2;
	for(i=3;i<16;i++)
		f[i]=f[i-1]+f[i-2];
}
void G(int x)
{
	int i;
	bool vis[1010];
	g[0]=0;
	for(i=1;i<=x;i++)
	{
		memset(vis,0,sizeof(vis));
		int j;
		for(j=0;f[j]<=i;j++)
			vis[g[i-f[j]]]=1;
		for(j=0;;j++)
		{
			if(vis[j]==0)
			{g[i]=j;break;}
		}
	}
	return ;
}
int main()
{
	fibonacci();
	G(1001);
	int m,n,p;
	while(scanf("%d%d%d",&m,&n,&p)&&n&&m&&p)
	{
		m=g[m];n=g[n];p=g[p];
		int d=m^n^p;
		if(d!=0)
			printf("Fibo\n");
		else
			printf("Nacci\n");
	}
	return 0;
}