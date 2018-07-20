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
void main()
{
	struct node *p;
	char a[]="123456789";
	int k;
	k=strlen(a);
	p=b_tree(a,1,k);
	pre(p);
	return;
}
