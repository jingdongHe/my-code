#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
	struct node *left,*right;
	char data;
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
	return ;
}
void inordepre(struct node *p)
{
	struct node *a[100],*px;
	int d=0;
	px=p;
	while(px!=NULL||d>0)
	{
		while(px!=NULL)
		{
			a[d++]=px;
			px=px->left;
		}
		d--;
		px=a[d];
		printf("%c ",px->data);
		px=px->right;
	}
	printf("\n");
}
void main()
{
	struct node *p;
	char a[]="123456789";
	p=b_tree(a,1,strlen(a));
	pre(p);printf("\n");
	//inordepre(p);
	
	return;
}
