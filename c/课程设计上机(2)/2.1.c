/*　　1. 实现二叉树的抽象数据类型定义。完成二叉树的基本操作：
　　初始化二叉树、按先序次序建立一个二叉树、检查二叉树是否为空、
按任一种遍历次序（包括按前序、中序、后序）输出二叉树中的所有结点、
求二叉树的深度、求二叉树中所有结点数。*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	char data;
	struct node *lchild,*rchild;
}node;
int f=0,num_node=0;
void Initialization(node *p)
{
	p->lchild=p->rchild=NULL;
}
node *b_preorder()
{
	node *p;
	char d;
	d=getchar();
	if(d=='#')
	{
		p=NULL;
		return p;
	}
	if(d!='\n')
	{
		p=(node *)malloc(sizeof(node));
		p->data=d;
		p->lchild=b_preorder();
		p->rchild=b_preorder();
	}
	return p;
}
int is_empty(node *head)
{
	if(head==NULL)
		return 1;
	return 0;
}
void Floor(node *p,int d)
{
	if(d>f)
		f=d;
	if(p!=NULL)
	{
		Floor(p->lchild,d+1);
		Floor(p->rchild,d+1);
	}
}
void pre_print(node *head)
{
	if(head!=NULL)
	{
		printf("%c ",head->data);
		pre_print(head->lchild);
		pre_print(head->rchild);
	}
}
void mid_print(node *head)
{
	if(head!=NULL)
	{
		mid_print(head->lchild);
		printf("%c ",head->data);
		mid_print(head->rchild);
	}
}
void aft_print(node *head)
{
	if(head!=NULL)
	{
		aft_print(head->lchild);
		aft_print(head->rchild);
		printf("%c ",head->data);
	}
}
void Node(node *head)
{
	if(head!=NULL)
	{
		num_node++;
		Node(head->lchild);
		Node(head->rchild);
	}
}
int main()
{
	node *p=NULL;
	printf("please entry the sequence of the tree\n");
	p=b_preorder();
	if(is_empty(p))
		printf("empty\n");
	else
		printf("noempty\n");
	pre_print(p);printf("\n");
	Floor(p,0);
	Node(p);
	printf("the height of the tree is %d\nthere are %d node\n",f,num_node);
	return 0;
}