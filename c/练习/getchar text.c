#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct string
{char c;
struct string *next;
};
int main()
{
	struct string str[80],*head,*p;
	int i,d=0;
	head=&str[0];
	for(i=0;i<80;i++)
	{
		if(i<79)
		{
			str[i].next=&str[i+1];
			str[i].c='\0';
		}
		else
		{
			str[i].next=NULL;
			str[i].c='\0';
		}
	}//将数组连接成链表
	for(i=0;(str[i].c=getchar())!='\n';i++,d++)

	p=head;
	for(i=0;i<d;i++)
	{
		printf("%c  ",p->c);
		p=p->next;
	}
	/*do
	{
		printf("%c  ",p->c);
		p=p->next;
	}while(p!=NULL);*/

return 0;
}