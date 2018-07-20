#include<stdio.h>
#include<string.h>
#define n 10
int main()
{
	char a[9],b[1];//无论b数组多大，都能把a全部录入，包括'\0'，但a数组则需给'\0'一个储存空间
	gets(a);
	strcpy(b,a);
	puts(b);
	return 0;
}