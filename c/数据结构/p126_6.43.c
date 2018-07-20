#include<stdio.h>
#include<stdlib.h>
struct node {
	char data;
	struct node *left,*right;
	struct node *parent;
};
struct node *pa,*pb;
struct node *b_tree(char a[])
{
	struct node *root=NULL,*current,*p;
	int d=0;
	while(a[d]!='\0')
	{
		current=(struct node *)malloc(sizeof(struct node));
		current->data=a[d++];
		current->left=current->right=NULL;
		if(root==NULL)
		{root=current;root->parent=NULL;}
		else
		{
			p=root;
			while(1)
			{
				if(p->data>current->data)
				{
					if(p->left==NULL)
					{current->parent=p;p->left=current;break;}
					p=p->left;
				}
				else
				{
					if(p->right==NULL)
					{current->parent=p;p->right=current;break;}
					p=p->right;
				}
			}
		}
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
struct node *findparent(struct node *root,char a,char b)
{
	struct node *p,*px;
	p=root;
	while(1)
	{
		if(p->data>a)
		{
			if(p->left==NULL)
			{printf("sorry\n");break;}
			p=p->left;
		}
		if(p->data<a)
		{
			if(p->right==NULL)
			{printf("sorry\n");break;}
			p=p->right;
		}
		if(p->data==a)
		{pa=p;break;}
	}
	p=root;
	while(1)
	{
		if(p->data>b)
		{
			if(p->left==NULL)
			{printf("sorry\n");break;}
			p=p->left;
		}
		if(p->data<b)
		{
			if(p->right==NULL)
			{printf("sorry\n");break;}
			p=p->right;
		}
		if(p->data==b)
		{pb=p;break;}
	}
	p=pa;px=pb;
	while(pa->parent!=NULL)
	{
		pb=px;
		while(pb->parent!=NULL)
		{
			if(pa->parent->data==pb->parent->data)
				return pa->parent;
			pb=pb->parent;
		}
		pa=pa->parent;
	}
	return NULL;
}
void main()
{
	struct node *p,*px;
	char a[]="678912345";
	p=b_tree(a);
	pre(p);
	px=findparent(p,'2','3');
	printf("\n%c\n",px->data);
	return;
}
