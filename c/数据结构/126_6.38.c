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
		{
			root=current;
		}
		else
		{
			p=root;
			while(1)
			{
				if(current->data>p->data)
				{
					if(p->right==NULL)
					{
						p->right=current;
						break;
					}
						p=p->right;
				}
				if(current->data<p->data)
				{
					if(p->left==NULL)
					{
						p->left=current;
						break;
					}
						p=p->left;
				}
			}
		}
		d=getchar();
	}
	return root;
}
void inorder(struct node *p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		printf("%c ",p->data);
		inorder(p->right);
	}
}
void main()
{
	struct node *p1;
	p1=b_tree();
	inorder(p1);
	return;
}

