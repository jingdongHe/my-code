#include<stdio.h>
void exchange(int d,int f);
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
    exchange (a,b);
	printf("%d%d",a,b);
	return 0;
}
void exchange(int d,int f)
{
	int n;
	n=d;d=f;f=n;
}
