#include<stdio.h>
#include<string.h>
void replace(char a[],int i,int j,char b[])
{
	int r,s=0;
	i-=1;j-=1;
	if(i<0||j<1||i+j+1>strlen(a)||j>strlen(b))
	{
		printf("error\n");
		return ;
	}
	for(r=i;r<=j;r++)
	{
		a[r]=b[s];
		s++;
	}
	puts(a);
}
void main()
{
	char a[]="1235467890";
	char b[]="567";
	replace(a,1,3,b);
	//puts(a);
}