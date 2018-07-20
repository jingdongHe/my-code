#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct inform{
	char name[10],phone[12];
	int number;
	struct inform *next;
};
int main()
{
	struct inform *head=NULL,*p,*current;
	int a;
	char b[10],c[12];
	while(scanf("%s%s%d",&b,&c,&a)!=EOF&&a!=0)
	{
		current=(struct inform *)malloc(sizeof(struct inform));
		
		if(head==NULL)
			head=current;
		else
			p->next=current;
		current->next=NULL;
		strcpy(current->name,b);
		strcpy(current->phone,c);
		current->number=a;
		p=current;
	}
	p=head;
	while(p!=NULL)
	{
		printf("%s:%d  %s\n",p->name,p->number,p->phone);
		p=p->next;
	}
	return 0;
}