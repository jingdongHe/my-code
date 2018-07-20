#include<stdio.h>
__int64 exgcd(__int64 a,__int64 b,__int64 &x1,__int64 &y1)
{
	__int64 t;
	__int64 d;
	if(b==0)
	{x1=1;y1=0;return a;}
	d=exgcd(b,a%b,x1,y1);
	t=x1;x1=y1;y1=t-a/b*y1;
	return d;
}
int main()
{
	__int64 x,y,m,n,l;
	__int64 a,b,d;
	__int64 x1,y1;
	while(scanf("%I64d%I64d%I64d%I64d%I64d",&x,&y,&m,&n,&l)!=EOF)
	{
		if(y==x)
		{
			printf("0\n");
			continue;
		}
		a=m-n;b=y-x;
		d=exgcd(a,l,x1,y1);
		if(d%b)
			printf("Impossible\n");
		else
		{
			x1=((x1*b/d)%l+l)%l;
			printf("%I64d\n",x1);
		}
	}
	return 0;
}