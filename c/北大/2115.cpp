#include<stdio.h>
#include<math.h>
int exgcd(int a,int b,__int64 &x,__int64 &y)
{
	if(b==0)
	{x=1;y=0;return a;}
	int d=exgcd(b,a%b,x,y);
	__int64 t=x;
	x=y;
	y=t-a/b*y;
	return d;
}
/*int Pow(int k,int n)
{
	int i;
	int q=1;
	if(n==0)
		return 1;
	for(i=0;i<n-1;i++)
		q=q*k;
	return q;
}*/
int main()
{
	__int64 x,y;
	int A,B,C,K;
	int a,b;
	while(scanf("%d%d%d%d",&A,&B,&C,&K)!=EOF)
	{
		if(A==0&&B==0&&C==0&&K==0)
			break;
		a=C;
		b=B-A;
		int n=(int)pow(2.0,(double)K);
		
		int d=exgcd(a,n,x,y);
		if(b%d)
			printf("forver\n");
		else
		{
			//printf("11111111111\n");
			x=(x*b/d)%n;//printf("33333333333333\n");
		//	x=(x%(b/d)+b/d)%(b/d);printf("144444444441\n");
			x=(x%(n/d)+n/d)%(n/d);
			printf("%I64d\n",x);
		}
	}
	return 0;
}