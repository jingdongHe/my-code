//用k来标记层次
#include<stdio.h>
#include<stdlib.h>
struct node {
	char data;
	struct node *left,*right;
};
struct node *b_tree()
{
	struct node *root=NULL,*current,*p;
	char d;
	d=getchar();
	while(d!='0')
	{
		current=(struct node *)malloc(sizeof(struct node));
		current->data=d;
		current->left=NULL;
		current->right=NULL;
		if(root==NULL)
			root=current;
		else
		{
			p=root;
			while(1)
			{
				if(p->data<current->data)
				{
					if(p->right==NULL)
					{p->right=current;break;}
					p=p->right;
				}
				else
				{
					if(p->left==NULL)
					{p->left=current;break;}
					p=p->left;
				}
			}
		}
		d=getchar();
	}
	return root;
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
int find(struct node *p,char x)
{
	int k=1;
	while(p!=NULL)
	{
		
		if(p->data==x)
			break;
		k++;
		if(p->data<x)
		{
			if(p->right==NULL)
			{k=0;break;}
			else
				p=p->right;
		}
		if(p->data>x)
		{
			if(p->left==NULL)
			{k=0;break;}
			else
				p=p->left;
		}
	}
		return k;
}
void main()
{
	struct node *p;
	int k;
	char x;
	p=b_tree();
	pre(p);
	printf("\n");
	x='1';
	k=find(p,x);
	if(k==0)
		printf("Sorry\n");
	else
		printf("X in %d\n",k);
	return;
}
	