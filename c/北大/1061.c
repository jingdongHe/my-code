#include<stdio.h>
#include<iostream.h>
int gcd(int a,int b)
{
	int t,r;
	if(a<b)
	{t=a;a=b;b=t;}
	r=a%b;
	if(r==0)
		return b;
	else
		return gcd(b,a%b);
}
void ex_gcd(int a,int b,__int64 &x1,__int64 &y1)//,
{
	__int64 t;
	printf("111111111\n");
	if(b==0)
	{x1=1;y1=0;return;}
	ex_gcd(b,a%b);
	t=x1;x1=y1;y1=t-a%b*y1;
	return;
}
void main()
{
	int x,y,m,n,l;
	__int64 x1,y1;
	int a,b,c,r;
	scanf("%d%d%d%d%d",&x,&y,&m,&n,&l);
	a=m-n;b=1;c=y-x;
	if(a<0)
	{a=a*-1;c=c*-1;}
	//printf("1111111111111\n");
	r=c%gcd(a,b,x1,y1);//printf("2222222222\n");
	printf("%d\n",gcd(a,b));
	if(r)
		printf("impossible\n");
	else
	{
		
		ex_gcd(a,b,x1,y1);
		printf("%I64d\n",x1);
	}
}