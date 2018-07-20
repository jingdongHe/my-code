#include<stdio.h>
#include<string.h>
int change1(char c[])
{
	if(strcmp(c,"one")==0)
		return 1;
	if(strcmp(c,"two")==0)
		return 2;
	if(strcmp(c,"three")==0)
		return 3;
	if(strcmp(c,"five")==0)
		return 5;
	if(strcmp(c,"six")==0)
		return 6;
	if(strcmp(c,"seven")==0)
		return 7;
	if(strcmp(c,"eight")==0)
		return 8;
	if(strcmp(c,"nine")==0)
		return 9;
	if(strcmp(c,"four")==0)
		return 4;
	if(strcmp(c,"zero")==0)
		return 0;
}
void main()
{
	char a[]="two";
	printf("%d........\n",change1(a));
}