#include<stdio.h>
#include<stdlib.h>
struct node {
	char data;
	struct node *left,*right;
};
int k=0;
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
				if(p->data>current->data)
				{
					if(p->left==NULL)
					{p->left=current;break;}
					p=p->left;
				}
				else
				{
					if(p->right==NULL)
					{p->right=current;break;}
					p=p->right;
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
void findleaf(struct node *p)
{
	if(p!=NULL)
	{
		if(p->left==NULL&&p->right==NULL)
			k++;
		findleaf(p->left);
		findleaf(p->right);
	}
	return;
}
void main()
{
	struct node *p;
	p=b_tree();
	pre(p);
	printf("\n");
	findleaf(p);
	printf("%d\n",k);
	return ;
}