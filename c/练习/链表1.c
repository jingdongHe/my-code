#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct film{
	char a[10];
	struct film*next;
};
int main()
{
	struct film *current,*head=NULL,*prev;
	char a[10];
	while(gets(a)!=NULL&&a[0]!='0')
	{
		current=(struct film *)malloc(sizeof(struct film));
		strcpy(current->a,a);
		if(head==NULL)
			head=current;
		else
			prev->next=current;
		current->next=NULL;
		prev=current;
	}
	current=head;
	while(current!=NULL)
	{
		printf("%s\n",current->a);
		current=current->next;
	}
	return 0;
}



