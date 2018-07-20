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
			while(p->left!=NULL&&p->right!=NULL)
			{
				if(current->d>p->d)
					p=p->right;
				else
					p=p->left;
			}
			if(current->d>p->d)
				p->right=current;
			else
				p->left=current;
		}
		scanf("%d",&data);
	}
}
int main()
{
	btree();
	printf("%d33333333\n",root->d);
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
	return 0;
}
