/*����3����˳��ջʵ���������ʽ��ֵ��
���������ʽ�����ַ������У������﷨��ȷ�������б������������ʽ�����ʽ�е�������Ϊ��λ������
��1��������������ȹ�ϵ������׺���ʽת��Ϊ��׺���ʽ�������
Ȼ������ú�׺���ʽֵ��������ı��ʽΪ2*(6-4)+8/4��ת����õ��ĺ�׺���ʽΪ264-*84/+��
��2��ʵ�ֽ̲�P50�㷨3.13��*/
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
