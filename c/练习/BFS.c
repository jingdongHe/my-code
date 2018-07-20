#include<stdio.h>
#include<stdlib.h>
#define n 8
struct node{
	int d;
	struct node *next;
};
struct node head[n];
struct node *queue,*head_queue=NULL;
int a[n],visit[n]={0};
void b_graph(int a,int b)//建立领接连表
{
	struct node *current,*p;
	current=(struct node *)malloc(sizeof(struct node));
	current->d=b;
	current->next=NULL;
	p=&head[a];
	while(p->next!=NULL)
		p=p->next;
	p->next=current;
}
void enqueue(int i)
{
	struct node *now;
	//printf("11111111111111111");
	now=(struct node *)malloc(sizeof(struct node));
	now->d=i;
	now->next=NULL;
	if(head_queue==NULL)
		head_queue=now;
	else
		queue->next=now;
	queue=now;
}
int dequeue()
{
	int k;
	queue=head_queue;
	k=queue->d;
	head_queue=head_queue->next;
	free(queue);
	return k;
}
void BFS(int i)
{
	struct node *p;
	enqueue(i);
	printf("%d",i);
	visit[i]=1;//标明已查找
	while(head_queue!=NULL)
	{
		i=dequeue();
		p=head[i].next;
		while(p!=NULL)
		{
			if(visit[p->d]==0)
			{
				enqueue(p->d);
				visit[p->d]=1;
				printf("==>%d",p->d);
			}	
			p=p->next;
		}

	}
}
void main()
{
	int Node[20][2]={1,2,2,1,1,3,3,1,2,4,4,2,2,5,5,2,3,6,6,3,3,7,7,3,4,8,8,4,5,8,8,5,6,8,8,6,7,8,8,7};
	int i;
	struct node *p;
	for(i=1;i<=n;i++)
		head[i].d=i;
	for(i=0;i<20;i++)
		b_graph(Node[i][0],Node[i][1]);
	for(i=1;i<=n;i++)
	{
		p=head[i].next;
		printf("[%d]",head[i].d);
		while(p!=NULL)
		{
			printf("==>%d",p->d);
			p=p->next;
		}
		printf("\n");
	}
	BFS(4);
	/*push(4);
	push(5);
	push(6);
	for(i=0;i<3;i++)
		printf("%d",a[i]);
	i=pop();
	printf("\n%d\n",i);
	i=0;
	while(a[i]!='\0')
		printf("%d",a[i++]);*/
	return ;
}
