#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
	char data;
	struct node *left,*right;
};
int k=0;
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
void compare(struct node *p1,struct node *p2)
{	
	if((p1->left==NULL&&p2->left!=NULL)||(p1->left!=NULL&&p2->left==NULL)||(p1->right==NULL&&p2->right!=NULL)||(p1->right!=NULL&&p2->right==NULL))
		k=1;
	printf("%c   %c\n",p1->data,p2->data);
	if(p1->data==p2->data)
	{
		
		if(p1->left!=NULL&&p2->left!=NULL)
			compare(p1->left,p2->left);
		if(p2->right!=NULL&&p2->right!=NULL)
			compare(p1->right,p2->right);
	}
	else
		k=1;
	return;
	//return 1;
}
void main()
{
	struct node *p1,*p2;
	char a[]="123456789";
	char b[]="123456789";
	p1=b_tree(a,1,strlen(a));
	p2=b_tree(b,1,strlen(b));
	pre(p1);printf("\n");
	pre(p2);printf("\n");
	compare(p1,p2);
	printf("%d\n",k);
	return;
}
