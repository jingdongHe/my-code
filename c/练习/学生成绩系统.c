#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int number;
	char name[20];
	int cm,em,mm;
	struct node *next;
};
char name1[20];
struct node *head=NULL,*rare,*p;
int main()
{
	int d=0,n,t;

	printf("How many studrents in this class?");
	scanf("%d",&n);
	getchar();
	for(d=0;d<n;d++)
	{
		rare=(struct node *)malloc(sizeof(struct node));
		printf("Please entry the %d studrent'number:\n",d+1);
		scanf("%d",&rare->number);
		getchar();
		printf("Please entry studrent'name:\n");
		gets(rare->name);
		printf("Please entry each subject mark;\n");
		scanf("%d%d%d",&rare->cm,&rare->em,&rare->mm);
		getchar();
		rare->next=NULL;
		if(head==NULL)
			head=rare;
		else
			p->next=rare;
		p=rare;
	}
	printf("Information output:\n");
	p=head;
	while(p!=NULL)
	{
		printf("%d  %s  %d  %d  %d\n",p->number,p->name,p->cm,p->em,p->mm);
		p=p->next;
	}
	while(1)
	{
		printf("Now what you want?(entry 0 to break)\n1.check mark   2.change mark   3.delete mark   4.add mark    5.calculate\n");
	    scanf("%d",&t);
		getchar();
		if(t==1)
		{
			printf("Who do you want to delete his marks?\n");
			gets(name1);
			p=head;
			while(p!=NULL)
			{
				if(!strcmp(p->name,name1))
				{rare=p;break;}
				else
				{printf("Sorry we didn't find this studrent\n");break;}
				p=p->next;
			}
			printf("%s marks are:%d  %d  %d\n",name1,rare->cm,rare->em,rare->mm);
		}
		if(t==2)
		{
			printf("Who do you want to delete his marks?\n");
			gets(name1);
			p=head;
			while(p!=NULL)
			{
				if(!strcmp(p->name,name1))
				{rare=p;break;}
				else
				{printf("Sorry we didn't find this studrent\n");break;}
				p=p->next;
			}
			printf("Please entry marks after change\n");
			scanf("%d%d%d",&rare->cm,&rare->em,&rare->mm);
		}
		if(t==3)
		{
			printf("Who do you want to delete his marks?\n");
			gets(name1);
			p=head;
			while(p!=NULL)
			{
				if(!strcmp(p->next->name,name1))
				{rare=p;break;}
				else
				{printf("Sorry we didn't find this studrent\n");break;}
				p=p->next;
			}
			p=rare;rare=p->next;
			p->next=p->next->next;
			free(rare);
		}
		if(t==4)
		{
			p=head;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			rare=(struct node *)malloc(sizeof(struct node));
			printf("Please entry the studrent'number:\n");
			scanf("%d",&rare->number);
			getchar();
			printf("Please entry studrent'name:\n");
			gets(rare->name);
			printf("Please entry each subject mark;\n");
			scanf("%d%d%d",&rare->cm,&rare->em,&rare->mm);
			getchar();
			rare->next=NULL; 
			p->next=rare;
			p=rare;
		}
		if(t==5)
		{
			int k=0;
			d=0;
			p=head;
			while(p!=NULL)
			{
				d+=p->cm+p->em+p->mm;
				k++;
				p=p->next;
			}
			printf("Class average is %d\n",d/(k*3));
		}
		if(t==0)
			break;
	}
	p=head;
	while(p!=NULL)
	{
		printf("%d  %s  %d  %d  %d\n",p->number,p->name,p->cm,p->em,p->mm);
		p=p->next;
	}
	p=head;
	while(p!=NULL)
	{
		rare=p->next;
		free(p);
		p=rare;
	}
	return 0;
}
