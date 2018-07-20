#include<stdio.h>
#include<stdlib.h>
struct node{
	int number;
	int password;
	struct node *next;
};
int main()
{
	int i,n,m=20,j;
	struct node *p,*head=NULL,*current,*rare;
	scanf("%d",&n);
	getchar();
	for(i=1;i<=n;i++)
	{
		current=(struct node *)malloc(sizeof(struct node));
		current->number=i;
		scanf("%d",&current->password);
		//current->next=NULL;
		if(head==NULL)
		{p=current;head=current;}
		else
			p->next=current;
		p=current;
	}
	p->next=head;
	p=head;
	/*for(i=1;i<=3*n;i++)
	{
		
		printf("%d  ",p->number);
		p=p->next;
	}
	printf("%d",p->number);*/
	//p=head;
	//printf("%d   %d\n",p->number,p->password);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<m-1;j++)
		{
			p=p->next;
		}
		printf("%d ",p->next->number);
		m=p->next->password;
		printf("%d......\n",m);
		rare=p->next;
		p->next=p->next->next;
		free(rare);
		if(m!=1)
			p=p->next;
	}
	printf("\n");
	return 0;
}

