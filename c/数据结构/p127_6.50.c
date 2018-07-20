#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
	char data;
	struct node *left,*right,*brother,*parent;
};
struct node *pp;
struct node *b_tree(char a[],int d,int k)
{
	struct node *p;
	if(d>k)
	{
		return NULL;
	}
	else
	{
		p=(struct node *)malloc(sizeof(struct node));
		p->data=a[d-1];
		p->left=b_tree(a,2*d,k);
		p->right=b_tree(a,2*d+1,k);
	}
	return p;
}
void pre(struct node *p)
{
	if(p!=NULL)
	{
		pre(p->left);
		printf("%c ",p->data);
		pre(p->right);
	}
	return ;
}
void findparent(struct node *p)
{
	if(p->left!=NULL)
	{
		p->left->parent=p;
		findparent(p->left);
	}
	if(p->right!=NULL)
	{
		p->right->parent=p;
		findparent(p->right);
	}
}
void findbrother(struct node *p)
{
	if(p->left!=NULL&&p->right!=NULL)
	{
		p->left->brother=p->right;
		p->right->brother=p->left;
		findbrother(p->left);
		findbrother(p->right);
	}
	if(p->left==NULL&&p->right!=NULL)
	{
		p->right->brother=NULL;
		findbrother(p->right);
	}
	if(p->left!=NULL&&p->left==NULL)
	{
		p->left->brother=NULL;
		findbrother(p->right);
	}
}
void findrel(struct node *p)
{
	findparent(p);
	findbrother(p);
}
void findx(struct node *p,char x)
{
	if(p->data==x)
		pp=p;
	if(p->left!=NULL)
		findx(p->left,x);
	if(p->right!=NULL)
		findx(p->right,x);
	return ;
}
void prichild(struct node *p)
{
	if(p->left!=NULL)
	{
		printf("%c ",p->left->data);
		
	}
	if(p->right!=NULL)
	{
		printf("%c ",p->right->data);
		
	}
	if(p->left!=NULL)
	{
		prichild(p->left);
	}
	if(p->right!=NULL)
	{
		prichild(p->right);
	}
	return;
}
void findchild(struct node *p,char x)
{
	findx(p,x);
	findrel(p);
	prichild(pp);
}
void main()
{
	struct node *p;
	char a[]="12345678902";
	p=b_tree(a,1,strlen(a));
	findchild(p,'1');
	return;
}




