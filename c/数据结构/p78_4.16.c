#include<stdio.h>
#include<string.h>
void change(char a[],int n)
{
	int i,j=0;
	char b[100];
	for(i=0;i<n;i++)
	{
		if(i%2==0)
			b[j]=a[i];
		if(i%2==1)
		{b[n-j-1]=a[i];j++;}
	}
	for(i=0;i<n;i++)
		a[i]=b[i];
}
void main()
{
	int n;
	char s[]="ABCDEFGHIJKL";
	n=strlen(s);
	change(s,n);
	puts(s);
}