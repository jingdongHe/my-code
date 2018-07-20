/*2．约瑟夫环问题：任给正整数N和K，按下述方法可以得到1,2, …,n的一个置换，
将数字1,2,…,n环形排列，按顺时针方向自1开始报数，报到K时输出该位置上的数字，
并使其出列。然后从他在顺时针方向的下一个数字继续报数，如此下去，
直到所有的数字全部出列为止。例如N=10，K=3，则正确的出列顺序应为3，6，9，2，7，1，8，5，10，4。*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node *next;
}node;
node *b_circl(int d)
{
	node *p,*px,*head;
	int i;
	px=(node *)malloc(sizeof(node));
	px->data=1;
	head=p=px;
	for(i=2;i<=d;i++)
	{
		px=(node *)malloc(sizeof(node));
		px->data=i;
		p->next=px;
		p=p->next;
	}
	p->next=head;
	return head;
}
void print(node *head,int k)
{
	int i=0;
	node *p,*pp,*pd;
	pp=head;
	while(pp->next!=head)
		pp=pp->next;
	p=head;
	while(p->next!=p)
	{
		i++;
		if(i==k)
		{
			printf("%d ",p->data);
			pp->next=p->next;
			pd=p;
			p=p->next;
			free(pd);
			i=0;
		}
		else
		{
			pp=p;
			p=p->next;
		}
	}
	printf("%d\n",p->data);
}
int main()
{
	int n,k;
	node *p;
	scanf("%d%d",&n,&k);
	p=b_circl(n);
	print(p,k);
}
