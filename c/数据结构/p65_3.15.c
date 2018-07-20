#include<stdio.h>
#define n 5
typedef struct 
{
	int data[n];
	int front,rear;
	int tag;
}queue;
queue Queueinit()
{
	queue q;
	q.front=q.rear=q.tag=0;
	return q;
}
queue Queuein(queue q,int x)
{
	
	if(q.front==q.rear&&q.tag==1)
	{
		printf("full\n");
		return q;
	}
	q.data[q.rear]=x;q.tag=1;
	q.rear=(q.rear+1)%n;
	return q;
}
queue Queueout(queue q)
{
	if(q.rear==q.front&&q.tag==0)
	{
		printf("empty\n");
		return q;
	}
	//printf("%d",q.data[q.front]);
	q.tag=0;
	q.front=(q.front+1)%n;
	return q;
}
void output(queue q)
{
	int i;
	q.rear=q.rear-1;
	if(q.front==q.rear&&q.tag==0)
	{
		printf("empty\n");
		return;
	}
	if(q.front==q.rear&&q.tag==1)
	{
		for(i=0;i<n;i++)
		{
			printf("%d ",q.data[q.front]);
			q.front++;
			q.front=q.front%n;
		}
	}
	if(q.front<q.rear)
	{
		for(i=q.front;i<=q.rear;i++)
		{
			printf("%d ",q.data[i]);
		}
	}
	if(q.front>q.rear)
	{
		for(i=q.front;i<=q.rear+n;i++)
		{
			printf("%d ",q.data[i%n]);
		}
	}
	printf("\n");
}
void main()
{
	queue q;
	q=Queueinit();
	q=Queuein(q,1);
	q=Queuein(q,2);
	q=Queuein(q,3);
	q=Queuein(q,4);
	q=Queuein(q,5);
	output(q);
	q=Queuein(q,1);
	q=Queueout(q);
	q=Queueout(q);
	output(q);
	q=Queuein(q,6);
	q=Queuein(q,7);
	output(q);
}