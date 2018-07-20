#include<stdio.h>
#define size 10
int a[size],p=0;//´æÕ»µÄÊý×é£¬Õ»¶¥
void push(int i)//Ñ¹ÈëÔªËØ
{
	
	if(p>=size)
	{
		printf(" full\n");
	}
	else
	{
		a[p]=i;
		p++;
	}
}
void output(int a[])
{
	int i;
	if(p==0)
		printf("empty");
	for(i=0;i<p;i++)
	{
		printf("%d",a[i]);
	}
	printf("\n");
}
void pop()//É¾³ý¶¥Õ»
{
	if(p==0)
		printf("tempty");
	else
	{
		a[p-1]='\0';
		p--;
	}
}
void top()//·µ»ØÕ»¶¥ÔªËØ
{
	if(p==0)
		printf("tempty\n");
	else
		printf("%d\n",a[p-1]);
}
int main()
{
	output(a);
	push(1);
	output(a);
	push(2);
	push(3);
	push(4);
	push(5);
	output(a);
	pop();
	output(a);
	top();
	return 0;
}

