/*　　3．用顺序栈实现算术表达式求值。
　　将表达式看成字符串序列，输入语法正确、不含有变量的整数表达式（表达式中的数字限为个位数）。
（1）利用算符的优先关系，把中缀表达式转换为后缀表达式后输出，
然后求出该后缀表达式值，如输入的表达式为2*(6-4)+8/4，转换后得到的后缀表达式为264-*84/+。
或（2）实现教材P50算法3.13。*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M 100
typedef struct stack{
	char s[M];
	int i;
}stack;
void b_stack(stack *p)
{
	int i;
	for(i=0;i<M;i++)
		p->s[i]='\0';
	p->i=0;
}
void print(stack *p)
{
	int i;
	for(i=0;i<p->i;i++)
		printf("%c...",p->s[i]);
}
char pop(stack *p)
{
	char d;
	if(p->i<0)
	{
		printf("empty\n");
		return 0;
	}
	d=p->s[p->i-1];
	p->s[p->i-1]='\0';
	p->i--;
	return d;
}
void push(stack *p,char a)
{
	if(p->i>=M-1)
	{
		printf("full\n");
		return;
	}
	p->s[p->i]=a;
	p->i++;
	//printf("%d.......%c\n",p->i,p->s[p->i-1]);
	//print(p);
}
int compare(char data)
{
	if(data=='-'||data=='+')
		return 1;
	if(data=='*'||data=='/')
		return 2;
	if(data=='#')
		return 0;
	if(data=='('||data==')')
		return -1;
	return 3;
}
void change(stack *p,char a[])
{
	int i,k;
	char d;
	k=strlen(a);
	for(i=0;i<k;i++)
	{
		if(a[i]<='9'&&a[i]>='0')
			printf("%c",a[i]);
		else
		{
			if(a[i]==')')
			{
				d=pop(p);
				while(d!='(')
				{
					printf("%c",d);
					d=pop(p);
				}
			}
			else
			{
			d=pop(p);//printf("%c....\n",d);
			while(compare(a[i])<=compare(d)&&a[i]!='(')
			{
				printf("%c",d);
				d=pop(p);
			}
			push(p,d);
			push(p,a[i]);
			}
		}
	}
	d=pop(p);
	while(d!='#')
	{
		printf("%c",d);
		d=pop(p);
	}
}

int main()
{
	stack *p;
	char a[M];
	p=(stack *)malloc(sizeof(stack));
	printf("please entry the expression\n");
	gets(a);
//	puts(a);
	b_stack(p);
	push(p,'#');
	//print(p);
	change(p,a);
}
