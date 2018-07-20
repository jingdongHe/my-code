#include<stdio.h>
#include<stdlib.h>
struct node {
	char data;
	struct node *left,*right;
};
struct node *b_tree()//����������
{
	struct node *root=NULL,*current,*p;
	char d;
	d=getchar();
	while(d!='0')//���ַ�0��Ϊ�������˴��ɸĳ�'\n'
	{
		current=(struct node *)malloc(sizeof(struct node));//�൱��new
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
void postpre(struct node *p)//�������������
{
	if(p!=NULL)
	{
		postpre(p->left);
		postpre(p->right);
		printf("%c ",p->data);
	}
}
void repostpre(struct node *p)//�������������
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