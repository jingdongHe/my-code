#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *left,*right;
	int d;
};
struct node *root=NULL,*current,*p;
void btree()
{
	int data;
	scanf("%d",&data);
	while(data!=0)
	{
		current=(struct node *)malloc(sizeof(struct node));
		current->d=data;
		current->left=NULL;
		current->right=NULL;
		if(root==NULL)
		{
			root=current;
			p=current;
			
		}
		else
		{
			p=root;
			while(1)
			{
				if(current->d>p->d)
				{
					if(p->right==NULL)
						break;
					p=p->right;
				}
				else
				{
					if(p->left==NULL)
						break;
					p=p->left;
				}
			}
			if(current->d>p->d)
				p->right=current;
			else
				p->left=current;
			p=current;
		}
		scanf("%d",&data);
	}
}
void preorder(struct node *x)
{
	if(x!=NULL)
	{
		printf("%d ",x->d);
		preorder(x->left);
		preorder(x->right);
	}
}
int main()
{
	btree();
	p=root;
	printf("left:\n");
	while(p!=NULL)
	{
		printf("%d ",p->d);
		p=p->left;
	}
	printf("\nringt:\n");
	p=root;
	while(p!=NULL)
	{
		printf("%d ",p->d);
		p=p->right;
	}
	printf("\n");
	p=root;
	preorder(p);
	return 0;
}
