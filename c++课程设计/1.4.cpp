/*　　　4. 用户猜测藏物位置：计算机在n行n列（行号为0到n-1，列号为0到n-1）
的“棋盘”的某一位置处“藏放一物件”（具体位置通过使用“rand()%10”来随机产生）；
用户通过输入行列号来“寻找”该物件；
若没猜对时计算机要告诉用户与藏放物件的位置有多远（取整后的近似距离）。*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void Set(int n,int &x,int &y)
{
	srand(time(NULL));
	x=rand()%n;y=rand()%n;
}
void Find(int x,int y)
{
	int a,b;
	printf("Please entry the point set\n");
	scanf("%d%d",&a,&b);
	if(a==x&&b==y)
		printf("It is the point\n");
	else
		printf("It isn't the point,the distance is %d\n",(int)sqrt((a-x)*(a-x)+(b-y)*(b-y)));
}
int main()
{
	int n;
	int x,y;
	scanf("%d",&n);
	Set(n,x,y);
	printf("\"The point is (%d,%d)\"\n",x,y);
	Find(x,y);
	return 0;
}
