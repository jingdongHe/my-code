/*　　　10．调车头
　　下面铁路线A段中，有n个车头，按图中所示的顺序编号为1，2，...，n。
每个车头都可以在铁路上独立行驶，但约定，当B段或C段已有车头时，
新进入这二段的车头号必须比该段中已有的车头号小。设计一个程序，调用递归过程，将A段中车头的顺序颠倒过来。*/
#include<stdio.h>
int hannuota(int a,int b,int c,int n)
{
	if(n==1)
	{printf("%d->%d\n",a,c);return 1;}
	int d=0;
	d+=hannuota(a,c,b,n-1);
	d+=1;printf("%d->%d\n",a,c);
	d+=hannuota(b,a,c,n-1);
	return d;
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",hannuota(1,2,3,n));
	return 0;
}
