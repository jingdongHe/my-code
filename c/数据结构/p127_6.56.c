#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
	char data;
	struct node *left,*right;
};
struct link {
	struct link *next;
	struct node *pr;
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
/*struct link *b_link()
{
	struct link *p;
	p=(struct link *)malloc(sizeof(struct link));
	p->next=NULL;
	return p;
}*/
struct link *p1=NULL,*p2,*head=NULL;
void linking(struct node *p)
{
	
	if(p!=NULL)
	{
		if(p->left==NULL&&p->right==NULL)
		{
			p2=(struct link *)malloc(sizeof(struct link));
			p2->pr=p;
			p2->next=NULL;
			if(p1==NULL)
			{
				p1=p2;
			}
			else
			{
				p1->next=p2;
				p1=p1->next;
			}
		}
		linking(p->left);
		linking(p->right);
	}
	if(head==NULL)
		head=p1;
	return ;
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
void main()
{
	struct node *p;
	char a[]="123456789";
	p=b_tree(a,1,strlen(a));
	pre(p);
	printf("\n");
	linking(p);
	//printf("111111111\n");
	while(head!=NULL)
	{
		printf("%c ",head->pr->data);
		head=head->next;
	}
	return;
}