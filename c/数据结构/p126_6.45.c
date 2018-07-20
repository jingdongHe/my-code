#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
	struct node *left,*right;
	char data;
};
struct link{
	struct node *data;
	struct link *next;
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
struct link *b_link()
{
	struct link *head;
	head=(struct link *)malloc(sizeof(struct link));
	head->next=NULL;
	return head;
}
struct link *push(struct link *head,struct node *p)
{	
	struct link *px,*py;
	py=(struct link *)malloc(sizeof(struct link));
	py->data=p;
	py->next=NULL;
	px=head;
	while(px->next!=NULL)
		px=px->next;
	px->next=py;
	return head;
}
struct link *pop(struct link *head)
{
	struct link *px;
	px=head->next;
	head->next=px->next;
	return px;
}
int empty(struct link *head)
{
	if(head->next==NULL)
		return 1;
	return 0;
}
int complete(struct node *p)
{
	struct link *L,*px;
	struct node *py;
	L=b_link();
	push(L,p);
	px=pop(L);
	py=px->data;
	while(py!=NULL)
	{
		push(L,py->left);
		push(L,py->right);
		px=pop(L);
		py=px->data;
		//printf("1111111111111\n");
	}
	//printf("!!!!!!!!!!!!\n");
	while(empty(L)==0)
	{
		px=pop(L);
		if(px->data!=NULL)
			return 0;
	}
	return 1;
}
void main()
{
	char a[]="123456789";
	int k;
	struct node *p;
	//struct link *l,*px;
	k=strlen(a);
	p=b_tree(a,1,k);
	pre(p);
	if(complete(p)==1)
		printf("\nYSE\n");
	else
		printf("\nNO\n");
	return;
}
	