#include<stdio.h>

int mod(int a,int b)
{
	return (a%b+b)%b;
}
int exgcd(int a,int b,int &x1,int &y1)
{
	int t,d;
	if(b==0)
	{x1=1;y1=0;return a;}
	d=exgcd(b,a%b,x1,y1);
	t=x1;x1=y1;y1=t-a/b*y1;
	return d;
}
void result(int a,int b,int n)
{
	int d;int x1,y1;
	d=exgcd(a,n,x1,y1);
	printf("%d......%d\n",x1,y1);
	if(mod(b,d)>0)
		printf("impossible\n");
	else
		printf("%d....\n",x1*(b/d));
}
void main()
{
	int x,y,m,n,l;
	scanf("%d,%d,%d,%d,%d",&x,&y,&m,&n,&l);
	result(m-n,y-x,l);
}