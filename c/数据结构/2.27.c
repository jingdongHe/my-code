#include<stdio.h>
#include<stdlib.h>
struct node 
{
	char a;
	struct node *next;
};
struct node *b_link()
{
	struct node *p,*l;
	char a;
	l=(struct node *)malloc(sizeof(struct node));
	l->next=NULL;
	while(scanf("%c",&a)&&a!='\n')
	{
		p=(struct node *)malloc(sizeof(struct node));
		p->a=a;
		p->next=l->next;
		l->next=p;
	}
	return l;
}
void output(struct node *l)
{
	struct node *p;
	p=l->next;
	if(p==NULL)
		printf("It is empty");
	while(p!=NULL)
	{
		printf("%c",p->a);
		p=p->next;
	}
	printf("\n");
}
void classify(struct node *l,struct node *n,struct node *r,struct node *c)
{
	struct node *p,*x;
	p=l->next;
	while(p!=NULL)
	{	
		x=p;
		p=p->next;
		if((x->a>='a'&&x->a<='z')||(x->a>='A'&&x->a<='Z'))
		{x->next=c->next;c->next=x;}
		else if(x->a>='0'&&x->a<='9')
		{x->next=n->next;n->next=x;}
		else
		{x->next=r->next;r->next=x;}
		
	}
}
int main()
{
	struct node *L;
	struct node *n,*r,*c;
	n=(struct node *)malloc(sizeof(struct node));
	n->next=NULL;
	r=(struct node *)malloc(sizeof(struct node));
	r->next=NULL;
	c=(struct node *)malloc(sizeof(struct node));
	c->next=NULL;
	L=b_link();
	output(L);
	classify(L,n,r,c);
	output(n);
	output(c);
	output(r);
	return 0;
}
