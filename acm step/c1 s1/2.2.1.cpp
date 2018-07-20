#include<stdio.h>
#include<math.h>
double th(double a,int f)
{
	if(f==0) return 1;
	double k=1;
	while(f--)
		k*=a;
	return k;
}
__int64 f(int n)
{
	/*double s1=th((1+sqrt(5.0))/2.0,n+1);
	double s2=th((1-sqrt(5.0))/2.0,n+1);*/
	double s1=pow(10,n*log10((1+sqrt(5.0))/2.0));
	double s2=pow(10,n*log10((1-sqrt(5.0))/2.0));
	double k=(s1-s2)*1.0/sqrt(5.0);
	return (__int64)k;
}
void tff(__int64 k)
{
	if(k<1000)
	{printf("%I64d\n",k);return;}
	int s=log10(k*1.0);
	int base=pow(10,s);
	for(int i=0;i<4;i++)
	{
		printf("%d",k/base);
		k%=base;
		base/=10;
	}
	printf("\n");
	return;
}
int main()
{
	/*for(int i=0;i<10;i++)
		tff(f(i));*/
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		n--;
		tff(f(n));
	}
	return 0;
}
