#include<stdio.h>
#define n 5
typedef struct 
{
	int data[n];
	int rear,length;
}queue;
queue Queueinit()
{
	queue s;
	s.rear=s.length=0;
	return s;
}
queue Queuein(queue s,int x)
{
	if(s.length>=n)
	{
		printf("full\n");
		return s;
	}
	s.length++;
	s.data[s.rear]=x;
	s.rear++;
	s.rear=s.rear%n;
	return s;
}
queue Queueout(queue s)
{
	int j;
	if(s.length<=0)
	{
		printf("empty\n");
		return s;
	}
	j=s.rear-s.length;
	if(j<0)
		j=j+n;
	printf("%d\n",s.data[j]);
	s.length--;
	return s;
}
void output(queue s)
{
	int i,j;
	j=s.rear-s.length;
	if(j<0)
		j=j+n;
	for(i=0;i<s.length;i++)
	{
		printf("%d ",s.data[j%n]);
		j++;
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
