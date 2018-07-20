#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
	char data;
	struct node *left,*right,*parent;
};
struct node *p9=NULL;
struct node *b_tree(char a[],int d,int k)
{
	struct node *p;
	if(d>k)
		return NULL;
	else
	{
		p=(struct node *)malloc(sizeof(struct node));
		p->data=a[d-1];
		p->left=b_tree(a,2*d,k);
		p->right=b_tree(a,2*d+1,k);
		p->parent=NULL;
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
	if(p!=NULL)
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
	return;
}
struct node *findx(struct node *p,char x)
{
	
	if(p->data==x)
		p9=p;
	if(p->left!=NULL)
		findx(p->left,x);
	if(p->right!=NULL)
		findx(p->right,x);
	return	p9;
}
void findencestor(struct node *p,char x)
{
	findx(p,x);
	findparent(p);
	while(p9->parent!=NULL)
	{
		printf("%c ",p9->parent->data);
		p9=p9->parent;
		
	}
}
void main()
{
	char a[]="123456789";
	struct node *p;
	p=b_tree(a,1,strlen(a));
	pre(p);printf("\n");
	findencestor(p,'5');
	return;
}