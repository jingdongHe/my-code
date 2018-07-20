#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *a,*b,*c;
	a=(int *)malloc(sizeof(int));
	b=(int *)malloc(sizeof(int));
	c=(int *)malloc(sizeof(int));
	*a=0;*b=1;*c=2;
	printf("%d  %d  %d\n",*a,*b,*c);
	a=b;*b=*c;b=c;
	printf("%d  %d  %d\n",*a,*b,*c);
	return 0;
}
