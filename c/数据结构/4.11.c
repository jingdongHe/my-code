#include<stdio.h>
#include<string.h>
void invert(char a[],int i)
{
	int n;
	char temp;
	n=strlen(a);
	temp=a[i];a[i]=a[n-i-1];a[n-i-1]=temp;
	if(i>n/2)
		return ;
	invert(a,i+1);
}
void main()
{
	char a[10]="1234567890";
	invert(a,0);
	puts(a);
}