/*　分别实现顺序表和单链表完成线性表的基本操作：
　　　初始化线性表、清空线性表、求线性表长度、检查线性表是否为空、遍历线性表、从线性表中查找元素、
从线性表中查找与给定元素值相同的元素在线性表中的位置、插入元素、删除元素。*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	char data;
	struct node *next;
}node;
node *Initialization()
{
	node *p,*px,*head;
	char d;
	p=(node *)malloc(sizeof(node));
	p->next=NULL;
	head=p;
	printf("请输入链表,以单一的空格结束\n");
	d=getchar();
	while(d!='\n')
	{
		px=(node *)malloc(sizeof(node));
		px->next=NULL;
		px->data=d;
		p->next=px;
		p=p->next;
		d=getchar();
	}
	return head;
}
void Empty(node *head)
{
	node *px,*pd;
	px=head->next;
	head->next=NULL;
	while(px!=NULL)
	{
		pd=px;
		px=px->next;
		free(pd);
	}
}
int getlength(node *head)
{
	node *p;
	int d=0;
	p=head->next;
	while(p!=NULL)
	{
		d++;
		p=p->next;
	}
	return d;
}
void Traversal(node *head)
{
	node *p;
	p=head->next;
	if(p==NULL)
	{
		printf("empty\n");
		return;
	}
	while(p!=NULL)
	{
		printf("%c",p->data);
		p=p->next;
	}
	printf("\n");
}
int is_empty(node *head)
{
	if(head->next==NULL)
		return 1;
	return 0;
}
int find(node *head,char a)
{
	node *p;
	int d=0;
	p=head->next;
	while(p!=NULL)
	{
		d++;
		if(p->data==a)
			return d;
		p=p->next;
	}
	return -1;
}
void insert(node *head,char a,int d)
{
	int i;
	node *p,*px;
	if(d>getlength(head))
	{
		printf("no enough space\n");
		return;
	}
	px=(node *)malloc(sizeof(node));
	px->data=a;
	p=head->next;
	for(i=1;i<d;i++)
		p=p->next;
	px->next=p->next;
	p->next=px;
}
void del(node *head,char a)
{
	node *p,*pd,*pp;
	p=head->next;
	pp=head;
	while(p!=NULL)
	{
		if(p->data==a)
		{
			pp->next=p->next;
			pd=p;
			p=p->next;
			free(pd);
		}
		else
		{
			pp=p;
			p=p->next;
		}
	}
}
int main()
{
	node *p;
	char a;
	int d,k;
	while(1)
	{
	p=Initialization();
	if(p->next->data==' '&&p->next->next==NULL)
		break;
	while(1)
	{
		printf("请输入操作\n1、求顺序表的长度\n2、判断顺序表是否为空\n3、遍历顺序表\n4、查找元素\n5、插入元素\n6、删除元素\n7、清空线性表\n输入0结束\n");
		scanf("%d",&k);getchar();
		if(k==0)
			break;
		switch(k)
		{
			case 7:Empty(p);break;
			case 1:
				    printf("%d\n",getlength(p));
					Traversal(p);
			case 2:
					if(is_empty(p))
						printf("空\n");
					else
						printf("不空\n");
					break;
			case 3: Traversal(p);break;
			case 4:
					printf("请输入想要查找的元素\n");
					a=getchar();
					d=find(p,a);getchar();
					if(d!=-1)
						printf("%c in %d\n",a,d);
					else
						printf("输入的元素不在链表内\n");
					break;
			case 5:
					printf("请输入元素 \'a\' 和元素 \'a\'插入的位置 \n");
					a=getchar();scanf("%d",&d);getchar();
					insert(p,a,d);
					Traversal(p);
					break;
			case 6:
					printf("请输入想要删除的元素\n");
					a=getchar();
					del(p,a);
					Traversal(p);
					break;
		}
	}
	}
	return 0;
}