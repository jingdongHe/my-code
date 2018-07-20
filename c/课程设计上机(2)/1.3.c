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
}stack;//栈的结构体，一个字符型数组+一个整形变量（整形变量表示栈顶）
void b_stack(stack *p)
{
	int i;
	for(i=0;i<M;i++)
		p->s[i]='\0';//初始化字符型数组
	p->i=0;//表示栈顶为0，即空
}//建立空栈
void print(stack *p)
{
	int i;
	for(i=0;i<p->i;i++)
		printf("%c ",p->s[i]);
}//打印栈内的所有元素
char pop(stack *p)
{
	char d;
	if(p->i<0)//如果栈为空栈，则不可能输出任何元素
	{
		printf("empty\n");
		return '\0';
	}
	d=p->s[p->i-1];//因为会删除栈顶元素，所以用d来临时存储栈顶元素
	p->s[p->i-1]='\0';//删除栈顶元素
	p->i--;//栈顶的标志向下移位
	return d;
}//取栈顶元素并将其删除
void push(stack *p,char a)
{
	if(p->i>=M-1)//若栈满，则不可能再压入元素
	{
		printf("full\n");
		return;
	}
	p->s[p->i]=a;
	p->i++;
}//将元素a压入栈
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
}//给各个运算字符确定优先级，+、-的优先级最低，为1；*、/的优先级为2，#的优先级为0（最低）
void change(stack *p,char a[])
{
	int i,k;
	char d;
	k=strlen(a);//k表示数组a的长度
	for(i=0;i<k;i++)//从头到尾遍历数组
	{
		if(a[i]<='9'&&a[i]>='0')//如果a[i]表示的是数字，直接输出
			printf("%c",a[i]);
		else//a[i]表示的是运算符
		{
			if(a[i]==')')//如果遇到右括号，则将栈内左'('右')'括号之内的元素打印并出栈
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
			d=pop(p);
			while(compare(a[i])<=compare(d)&&a[i]!='(')//判断运算符的优先级，若a[i]表示的运算符的优先级较低，则将栈内优先级大于或等于它的元素打印并输出
			{
				printf("%c",d);
				d=pop(p);
			}
			push(p,d);//若栈顶的元素的优先级小于a[i]的优先级，则提取出来后，再将其压入
			push(p,a[i]);//将栈内优先级大于或等于它的元素打印并输出后，再将a[i]压入栈
			}
		}
	}
	d=pop(p);
	while(d!='#')//遍历完数组之后，将栈内所有元素出栈
	{
		printf("%c",d);
		d=pop(p);
	}
}
int transfrom(char a,char b,char c)//a，b数，c操作符
{
	switch(c)
	{
	case '+':return(a-'0')+(b-'0');
	case '-':return(a-'0')-(b-'0');
	case '*':return(a-'0')*(b-'0');
	case '/':return(a-'0')/(b-'0');
	}
	return '0';
}
void calcul(char a[])
{
	int i,k,s;
	char d,d1,d2;//d1.d2表示数字，d表示操作符
	stack *p1,*p2;//p1用于存数，p2用于存操作符
	k=strlen(a);
	
	p1=(stack *)malloc(sizeof(stack));
	p2=(stack *)malloc(sizeof(stack));
	b_stack(p1);
	b_stack(p2);
	push(p2,'#');
	for(i=0;i<k;i++)
	{
		if(a[i]<='9'&&a[i]>='0')//如果a[i]表示的是数字，直接输出
			push(p1,a[i]);
		else//a[i]表示的是运算符
		{
			if(a[i]==')')//如果遇到右括号，则将栈内左'('右')'括号之内的元素打印并出栈
			{
				d=pop(p2);
				while(d!='(')
				{
					d1=pop(p1);d2=pop(p1);
					s=transfrom(d2,d1,d);
					d=s+'0';
					push(p1,d);
					d=pop(p2);
				}
			}
			else
			{
				d=pop(p2);
				while(compare(a[i])<=compare(d)&&a[i]!='(')//判断运算符的优先级，若a[i]表示的运算符的优先级较低，则将栈内优先级大于或等于它的元素打印并输出
				{
					d1=pop(p1);d2=pop(p1);
					s=transfrom(d2,d1,d);
					d=s+'0';
					push(p1,d);
					d=pop(p2);
				}
				push(p2,d);//若栈顶的元素的优先级小于a[i]的优先级，则提取出来后，再将其压入
				push(p2,a[i]);//将栈内优先级大于或等于它的元素打印并输出后，再将a[i]压入栈
			}
		}
	}
	d=pop(p2);
	while(d!='#')//遍历完数组之后，将栈内所有元素出栈
	{
		d1=pop(p1);d2=pop(p1);
		s=transfrom(d2,d1,d);
		d=s+'0';
		push(p1,d);
		d=pop(p2);
	}
	printf("%c\n",pop(p1));
}
int main()
{
	stack *p;
	char a[M];
	p=(stack *)malloc(sizeof(stack));
	printf("please entry the expression\n");
	gets(a);//a用于存储输入的字符串
	b_stack(p);
	push(p,'#');//建立名为p的栈，并且将#压入栈底
	change(p,a);
	printf("\nthe result is:");
	calcul(a);
}