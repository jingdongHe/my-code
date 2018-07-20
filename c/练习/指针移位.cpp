#include<stdio.h>
void main()
{
	int a[]={1,2,3,4,5,6,7,8,9};
	int n=9;int *p;
	p=a;
	printf("%d....\n",*(p+4));
}