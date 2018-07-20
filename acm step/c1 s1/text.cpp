#include<stdio.h>
int main()
{
	int a[4];
	a[0]=a[1]=a[2]=a[3]=1;
	for(int i=5;i<=20;i++)
	{
		a[i%4]=a[(i-1)%4]+a[(i-2)%4]+a[(i-3)%4]+a[(i-4)%4];
		printf("%3d:%d\n",i,a[i%4]);
	}
	return 0;
}
