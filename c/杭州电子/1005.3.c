#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct film{
	char a;
	struct film*next;
};
int main()
{
	struct film *current,*head=NULL,*prev,*c1,*c2;
	int i,r,s,n;
	scanf("%d%d%d",&r,&s,&n);
	for(i=0;i<2;i++)
	{
		current=(struct film *)malloc(sizeof(struct film));
		current->a=1;
		if(head==NULL)
			head=current;
		else
			prev->next=current;
		current->next=NULL;
		prev=current;
	}
	c1=head;c2=prev;
	for(;i<n;i++)
	{
		current=(struct film *)malloc(sizeof(struct film));
		current->a=(r*(c2->a)+s*(c1->a))%7;
		c1=c1->next;
		c2=c2->next;
		prev->next=current;
		current->next=NULL;
		prev=current;
	}
	/*current=head;
	while(current!=NULL)
	{
		printf("%d\n",current->a);
		current=current->next;
	}*/
	printf("%d\n",current->a);
	return 0;
}
