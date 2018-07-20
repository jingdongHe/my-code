#include<stdio.h>
#include<math.h>
const __int64 N=pow(10,18);
const int M=105;
typedef struct number
{
	__int64 a,b,c,d;
}number;
void set(number &s,__int64 a,__int64 b,__int64 c,__int64 d)
{
	s.a=a;s.b=b;s.c=c;s.d=d;
}
number add(number x,number y)
{
	number z;
	__int64 d=x.d+y.d;
	__int64 c=x.c+y.c;
	__int64 b=x.b+y.b;
	__int64 a=x.a+y.a;
	z.d=d%N;
	z.c=(c+d/N)%N;
	z.b=(b+(c+d/N)/N)%N;
	z.a=(a+(b+(c+d/N)/N)/N)%N;
	return z;
}
void print(number a)
{
	if(a.a) printf("%I64d",a.a);
	if(a.b) printf("%I64d",a.b);
	if(a.c) printf("%I64d",a.c);
	printf("%I64d",a.d);
}
int main()
{
	number f[M+2][2*M+2];
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<2*M;j++)
			set(f[i][j],0,0,0,0);
	}
	set(f[1][1],0,0,0,1);
	for(int i=2;i<2*M;i++)
	{
		for(int j=0;j<=M;j++)
		{
			f[j][i]=f[j+1][i-1];
			if(j>=1)
				f[j][i]=add(f[j-1][i-1],f[j][i]);	
		}
			
	}
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		print(f[0][2*n]);
		printf("\n");
	}
	
	return 0;
}
