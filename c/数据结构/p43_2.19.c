#include<stdio.h>
#include<stdlib.h>
struct node {
	int d;
	struct node *next;
};
struct node *b_list()
{
	char d;
	struct node *head,*current,*p;
	head=(struct node *)malloc(sizeof(struct node));
	p=head;
	printf("Please entry the list\n");
	d=getchar();
	while(d!='\n')
	{
		current=(struct node *)malloc(sizeof(struct node));
		current->d=d;
		current->next=NULL;
		p->next=current;
		p=current;
		d=getchar();
	}
	return head;
}
void output(struct node *head)
{
	struct node *p;
	p=head->next;
	while(p!=NULL)
	{
		printf("%c",p->d);
		p=p->next;
	}
	printf("\n");
	return;
}
struct node *mix(struct node *a,struct node *b,struct node *c)
{
	struct node *pa,*pb,*pc,*pd,*parent_a,*parent_b,*parent_c;
	pa=a->next;pb=b->next;pc=c->next;
	parent_a=a;parent_b=b;parent_c=c;
	while(pa!=NULL&&pb!=NULL&&pc!=NULL)
	{
		if(pa->d>pb->d)//pb移动
		{
			pd=pb;
			parent_b->next=pb->next;
			pb=pb->next;
			free(pd);
		}
		if(pa->d<pb->d)//pa移动
		{
			pd=pa;
			parent_a->next=pa->next;
			pa=pa->next;
			free(pd);
		}
		if(pa->d==pb->d)//pa,pb同时移动
		{
			while(1)
			{
				if(pa->d==pc->d)
				{
					parent_a=pa;
					pa=pa->next;
					pd=pb;
					parent_b->next=pb->next;
					pb=pb->next;
					free(pd);
					pd=pc;
					parent_c->next=pc->next;
					pc=pc->next;
					break;
				}
				if(pa->d<pc->d)
				{
					parent_a->next=pa->next;
					pd=pa;
					pa=pa->next;
					free(pd);
					parent_b->next=pb->next;
					pd=pb;
					pb=pb->next;
					free(pd);
					parent_c->next=pc->next;
					pd=pc;
					pc=pc->next;
					free(pd);
					if(pa==NULL||pb==NULL||pc==NULL)
						break;
				}
				if(pa->d>pc->d)
				{
					pd=pc;
					parent_c->next=pc->next;
					pc=pc->next;
					free(pd);
					if(pc==NULL)
						break;
				}
			}
		}
	}
	while(pa!=NULL)
	{
		pd=pa;
		parent_a->next=pa->next;
		pa=pa->next;
		free(pd);
	}
	return a;
}
void main()
{
	struct node *a,*b,*c,*L;
	a=b_list();
	b=b_list();
	c=b_list();
	L=mix(a,b,c);
	output(L);
	return;
}

