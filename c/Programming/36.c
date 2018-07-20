/*一个思路是记点集Pi = { p1, p2, ……, pi}, Di为点集Pi 的最小包围圆。
注意到以下性质是可以利用的：
若点p i ∈Di-1, 则Di = Di-1, 
即若i-1个点的最小包围圆Di-1已经求出，新的一点pi，若在Di-1内部，
则Di-1也是加入新点后的最小包围圆；
若点 pi 不是在Di-1内部，则最小包围圆Di是圆周边界通过点pi 并包含了前面i-1个点的一个圆，不再是Di-1了。
这样可以通过下面三个函数求出最小包围圆: 
求输入点集Pn的最小包围圆MiniDisc( Pn )。
 求通过点q，包含了点集Pn中所有点的最小包围圆MiniDiscOne( Pn, q )。
 求通过点q1和q2，包含了点集Pn中所有点的最小包围圆MiniDiscTwo( Pn, q1, q2 ) 。*/
#include<stdio.h>
#include<math.h>
int x=1000,y=1000,r=0,n;
void mindisc(int a[])
{
	int i;
	for(i=0;i<n;i+=2)
	{
		if(x==1000&&y==1000)
		{
			x=a[i];y=a[i+1];
			r=0;
		}
		if(sqrt((a[i]-x)*(a[i]-x)+(a[i+1]-y)*(a[i+1]-y))<=r)
			continue;
		else
		{
			x=abs(a[i]-x)
void main()
{
	int i;
	int a[100];
	printf("please entry the number of point\n");
	scanf("%d",&n);getchar();
	for(i=0;i<n;i+=2)
		scanf("%d%d",&a[i],&a[i+1]);
}