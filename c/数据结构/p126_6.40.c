#include<stdio.h>
#include<stdlib.h>
typedef struct node{
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
		current->left=current->right=NULL;
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
	return;
}
void change(struct node *p)
{
	struct node *px;
	if(p->left!=NULL||p->right!=NULL)
	{
		px=p->left;
		p->left=p->right;
		p->right=px;
	}
	if(p->left!=NULL)
		change(p->left);
	if(p->right!=NULL)
		change(p->right);
	return;
}
void main()
{
	struct node *p;
	p=b_tree();
	pre(p);
	printf("\n");
	change(p);
	pre(p);
	return;
}
