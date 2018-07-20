#include<stdio.h>
#include<stdlib.h>
struct node {
	char data;
	struct node *left,*right;
};
struct node *b_tree()//建立二叉树
{
	struct node *root=NULL,*current,*p;
	char d;
	d=getchar();
	while(d!='0')//以字符0作为结束，此处可改成'\n'
	{
		current=(struct node *)malloc(sizeof(struct node));//相当于new
		current->data=d;
		current->left=current->right=NULL;
		if(root==NULL)
			root=current;
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
				else
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
void postpre(struct node *p)//后序遍历二叉树
{
	if(p!=NULL)
	{
		postpre(p->left);
		postpre(p->right);
		printf("%c ",p->data);
	}
}
void repostpre(struct node *p)//先序遍历二叉树
{
	if(p!=NULL)
	{
		printf("%c ",p->data);
		repostpre(p->right);
		repostpre(p->left);
	}
}
void main()
{
	struct node *p;
	p=b_tree();
	postpre(p);
	printf("\n");
	repostpre(p);
	return;
}