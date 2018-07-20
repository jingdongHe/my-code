/*　　2.一棵n个结点的完全二叉树存放在二叉树的顺序存储结构中，试编写非递归算法对该二叉树进行前序遍历。*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 100
typedef struct stack {
	int a[M];
	int i;
}stack;
int pop(stack *p)
{
	int d;
	if(p->i<0)
	{
		printf("empty\n");
		return '\0';
	}
	d=p->a[--p->i];
	p->a[p->i]='\0';
	return d;
}
void push(stack *p,int data)
{
	if(p->i>=M)
	{
		printf("full\n");
		return;
	}
	p->a[p->i++]=data;
}
int empty(stack *p)
{
	if(p->i<=0)
		return 1;
	return 0;
}
void print(char tree[])
{
	stack *s;
	int p,k;
	k=strlen(tree);
	s=(stack *)malloc(sizeof(stack));
	s->i=0;
	p=1;
	while(p<k||!empty(s))
	{
		while(tree[p]!='#')
		{
			printf("%c",tree[p]);
			push(s,p);
			p=2*p;
			if(p>=k)
				break;
		}
		if(!empty(s))
		{
			p=pop(s);
			p=p*2+1;
		}
	}
}
int main()
{
	char tree[M];
	int i=1;
	char d;
	printf("please entry the binary tree are stored in order\n");
	d=getchar();
	while(d!='\n')
	{
		tree[i++]=d;
		d=getchar();
	}
	print(tree);
	return 0;
}