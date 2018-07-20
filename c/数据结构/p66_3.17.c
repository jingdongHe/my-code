#include<stdio.h>
int akm(int m,int n)
{
	if(m==0)
		return n+1;
	if(m!=0&&n==0)
		return akm(m-1,1);
	if(m!=0&&n!=0)
		return akm(m-1,akm(m,n-1));
}
void main()
{
	printf("%d",akm(1,1));
}