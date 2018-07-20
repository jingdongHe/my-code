#include<stdio.h>
#include<string.h>
int huiwei(char a[],int n,int i)
{
	if(i>=(i+n)/2)
		return 1;
	if(a[i]==a[n-1-i])
	{
		return huiwei(a,n,i+1);
		printf("1111111111111\n");
	}
	else
		return 0;
}
void main()
{
	int n;
	char a[]="12321";
	n=strlen(a);
	if(huiwei(a,n,0)==1)
		printf("yes\n");
	else
		printf("no\n");
}
