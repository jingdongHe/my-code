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
}stack;//ջ�Ľṹ�壬һ���ַ�������+һ�����α��������α�����ʾջ����
void b_stack(stack *p)
{
	int i;
	for(i=0;i<M;i++)
		p->s[i]='\0';//��ʼ���ַ�������
	p->i=0;//��ʾջ��Ϊ0������
}//������ջ
void print(stack *p)
{
	int i;
	for(i=0;i<p->i;i++)
		printf("%c ",p->s[i]);
}//��ӡջ�ڵ�����Ԫ��
char pop(stack *p)
{
	char d;
	if(p->i<0)//���ջΪ��ջ���򲻿�������κ�Ԫ��
	{
		printf("empty\n");
		return '\0';
	}
	d=p->s[p->i-1];//��Ϊ��ɾ��ջ��Ԫ�أ�������d����ʱ�洢ջ��Ԫ��
	p->s[p->i-1]='\0';//ɾ��ջ��Ԫ��
	p->i--;//ջ���ı�־������λ
	return d;
}//ȡջ��Ԫ�ز�����ɾ��
void push(stack *p,char a)
{
	if(p->i>=M-1)//��ջ�����򲻿�����ѹ��Ԫ��
	{
		printf("full\n");
		return;
	}
	p->s[p->i]=a;
	p->i++;
}//��Ԫ��aѹ��ջ
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
}//�����������ַ�ȷ�����ȼ���+��-�����ȼ���ͣ�Ϊ1��*��/�����ȼ�Ϊ2��#�����ȼ�Ϊ0����ͣ�
void change(stack *p,char a[])
{
	int i,k;
	char d;
	k=strlen(a);//k��ʾ����a�ĳ���
	for(i=0;i<k;i++)//��ͷ��β��������
	{
		if(a[i]<='9'&&a[i]>='0')//���a[i]��ʾ�������֣�ֱ�����
			printf("%c",a[i]);
		else//a[i]��ʾ���������
		{
			if(a[i]==')')//������������ţ���ջ����'('��')'����֮�ڵ�Ԫ�ش�ӡ����ջ
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
			while(compare(a[i])<=compare(d)&&a[i]!='(')//�ж�����������ȼ�����a[i]��ʾ������������ȼ��ϵͣ���ջ�����ȼ����ڻ��������Ԫ�ش�ӡ�����
			{
				printf("%c",d);
				d=pop(p);
			}
			push(p,d);//��ջ����Ԫ�ص����ȼ�С��a[i]�����ȼ�������ȡ�������ٽ���ѹ��
			push(p,a[i]);//��ջ�����ȼ����ڻ��������Ԫ�ش�ӡ��������ٽ�a[i]ѹ��ջ
			}
		}
	}
	d=pop(p);
	while(d!='#')//����������֮�󣬽�ջ������Ԫ�س�ջ
	{
		printf("%c",d);
		d=pop(p);
	}
}
int transfrom(char a,char b,char c)//a��b����c������
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
	char d,d1,d2;//d1.d2��ʾ���֣�d��ʾ������
	stack *p1,*p2;//p1���ڴ�����p2���ڴ������
	k=strlen(a);
	
	p1=(stack *)malloc(sizeof(stack));
	p2=(stack *)malloc(sizeof(stack));
	b_stack(p1);
	b_stack(p2);
	push(p2,'#');
	for(i=0;i<k;i++)
	{
		if(a[i]<='9'&&a[i]>='0')//���a[i]��ʾ�������֣�ֱ�����
			push(p1,a[i]);
		else//a[i]��ʾ���������
		{
			if(a[i]==')')//������������ţ���ջ����'('��')'����֮�ڵ�Ԫ�ش�ӡ����ջ
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
				while(compare(a[i])<=compare(d)&&a[i]!='(')//�ж�����������ȼ�����a[i]��ʾ������������ȼ��ϵͣ���ջ�����ȼ����ڻ��������Ԫ�ش�ӡ�����
				{
					d1=pop(p1);d2=pop(p1);
					s=transfrom(d2,d1,d);
					d=s+'0';
					push(p1,d);
					d=pop(p2);
				}
				push(p2,d);//��ջ����Ԫ�ص����ȼ�С��a[i]�����ȼ�������ȡ�������ٽ���ѹ��
				push(p2,a[i]);//��ջ�����ȼ����ڻ��������Ԫ�ش�ӡ��������ٽ�a[i]ѹ��ջ
			}
		}
	}
	d=pop(p2);
	while(d!='#')//����������֮�󣬽�ջ������Ԫ�س�ջ
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
	gets(a);//a���ڴ洢������ַ���
	b_stack(p);
	push(p,'#');//������Ϊp��ջ�����ҽ�#ѹ��ջ��
	change(p,a);
	printf("\nthe result is:");
	calcul(a);
}