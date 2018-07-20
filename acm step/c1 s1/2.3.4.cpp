#include<stdio.h>
int main()
{
	int h[30]={0};
	h[0]=h[1]=1;
	for(int i=2;i<=20;i++)
	{
		for(int j=0;j<i;j++)
			h[i]+=h[j]*h[i-j-1];
	}
	for(int i=0;i<=20;i++)
		printf("%d\n",h[i]);
	int a=1;
	printf("1\n");
	for(int i=2;i<=20;i++)
	{
		a=(4*i-2)*1.0/(i+1)*a;
		printf("%d\n",a);
	}
	return 0;
}
