#include<stdio.h>
int main()
{
	int n,m,i;
	_int64 a,b,c;
	while(scanf("%d%d",&n,&m)&&n!=0&&m!=0)
	{
		//��
		a=n*m*(m-1);
		//��
		b=n*m*(n-1);
		//б
		c=0;
		for(i=0;i<n-1;i++)
			c+=(i+1)*i;
		c*=2;
		c+=(m-n+1)*(n-1)*n;
		c*=2;
		printf("%I64d",a+b+c);
	}
	return 0;
}