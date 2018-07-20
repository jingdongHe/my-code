#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
	char data;
	struct node *left,*right;
};
struct node *b_tree(char a[],int d,int k)
{
	struct node *p;
	if(d>k)
		return NULL;
	else
	{
		p=(struct node *)malloc(sizeof(struct node));
		p->data=a[d-1];
		p->left=b_tree(a,2*d,k);
		p->right=b_tree(a,2*d+1,k);
	}
	return p;
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
int depth(struct node *p)
{
	if(p==NULL)
		return 0;
	else
		return 1+(depth(p->left)>depth(p->right)?depth(p->left):depth(p->right));
}
void put(struct node *p)
{
	if(p!=NULL)
	{
		printf("%c ",p->data);
		if(depth(p->left)>depth(p->right))
			put(p->left);
		if(depth(p->left)<depth(p->right))
			put(p->right);
		if(depth(p->left)==depth(p->right))
		{
			put(p->left);
			//put(p->right);
		}
		
	}//printf("\n");
	return;
}
void main()
{
	struct node *p;
	char a[]="123456789";
	p=b_tree(a,1,strlen(a));
	pre(p);
	printf("\n");
	put(p);
	printf("\n");
	return;
}