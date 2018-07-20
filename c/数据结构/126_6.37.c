#include<stdio.h>
#include<stdlib.h>
struct node {
	char data;
	struct node *lchild,*rchild;
};
int r=0,s=0,t=0;
struct node *b_tree()
{
	struct node *root=NULL,*current,*p;
	char d;
	d=getchar();
	while(d!='0')
	{
		current=(struct node *)malloc(sizeof(struct node));
		current->data=d;
		current->lchild=NULL;
		current->rchild=NULL;
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
					if(p->rchild==NULL)
					{
						p->rchild=current;
						break;
					}
					p=p->rchild;
				}
				else
				{
					if(p->lchild==NULL)
					{
						p->lchild=current;
						break;
					}
					p=p->lchild;
				}
			}
		}
		d=getchar();
	}
	return root;
}
void prefind(struct node *p)
{
	if(p!=NULL)
	{
		if(p->lchild!=NULL&&p->rchild!=NULL)
			r++;
		if(p->lchild==NULL&&p->rchild!=NULL)
			s++;
		if(p->lchild!=NULL&&p->rchild==NULL)
			s++;
		if(p->lchild==NULL&&p->rchild==NULL)
			t++;
		printf("%c ",p->data);
		prefind(p->lchild);
		prefind(p->rchild);
	}
}
void main()
{
	struct node *p1;
	p1=b_tree();
	prefind(p1);
	printf("zore:%d   one:%d   two:%d\n",r,s,t);
	return;
}

