#include<stdio.h>
#include<stdlib.h>//LEN的作用不大，且机器是从上往下跑，还未定义节点，用LEN来确定节点大小可能会出错
struct Student
{
	int num;
	float score;
	struct Student *next;
};

struct Student *creat()
{
	int n=0;
	struct Student *head=NULL;
	struct Student *p1,*p2;
	p1=(struct Student *)malloc(sizeof(struct Student));//此处我将你p1=p2....的p2删掉,用p1创建新节点，p2为链
	printf("please entry studrent's number and score:(entry end when number=0 and score=0)\n");
	scanf("%d %f",&p1->num,&p1->score);
	p1->next=NULL;//这两行作用是将每个学生的数据输入
	while(p1->num!=0)
	{
		//n=n+1;，此处的n没有必要,可删掉（写代码要尽量减少变量，不容易乱）
		if(head==NULL)
			head=p1;
		else
			p2->next=p1;
		p2=p1;		
		p1=(struct Student *)malloc(sizeof(struct Student));
		printf("please entry studrent's number and score:(entry end when number=0)\n");
		scanf("%d %f",&p1->num,&p1->score);
		p1->next=NULL;//此处将p1->next指向null好处是可随时停止链表的建立
	}
	//p2->next=NULL;
	return head;
}
void print(struct Student *head1)
{
	struct Student *p;
	p=head1;//此处完全没有必要再建立一个新指针
	/*printf("\nNow,These %d records are :\n",n);
	if(head1!=NULL)
		do
		{
			printf("%d %5.1f\n",p->num,p->score);
			p=p->next;
		}
		while(p!=NULL);*/
	while(p!=NULL)
	{
		printf("%d %5.1f\n",p->num,p->score);
		p=p->next;
	}
}
struct Student *delet(struct Student *head2)//此处删除节点，使链表发生变化，且有可能删除头结点，故，需返回一个链表（头结点），此处我改变了类型
{
	struct Student *p1,*head;
	int j;
	head=head2;//head为真正的头指针
	printf("please input the student's num you want to delete:\n");
	scanf("%d",&j);
	/*p1=head2;
	if(head2!=NULL) 
		while (p1->num!=j)
		{
			p2=p1;
			p1=p1->next;
		}
		if(p1==NULL)
		{
			if(p1=head2)
				head2=p1->next;
			else
				p2->next=p1->next;
		}
		print(head2);*/
	if(head2->num==j)//删除头结点
	{
		p1=head2;
		head=head2->next;
		free(p1);
		return head;
	}
	while(head2->next->num!=j)//找到要删除的节点的上一个节点,循环结束后head2就指向要删除节点的上一个节点
		head2=head2->next;
	p1=head2->next;//用p1标记要删除的节点
	head2->next=head2->next->next;//将要删除的节点的上一个节点，的下一个指针，指向要删除节点的下一个节点，借此跳过对删除节点的连接
	free(p1);
	print(head);
	return head;
}
void main()
{
	delet(creat());
}