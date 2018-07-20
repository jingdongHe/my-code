/*题目26：你一定很熟悉著名的Hanoi塔游戏，当理解了圆盘数目较多需要的时间太长之后，
你可以放弃实际去移动圆盘，但你不应该放弃如下一个有点类似的游戏：设有n根柱子，
每根柱子上有一个圆盘，圆盘上有一个正整数，不同圆盘上的数不同。
初始时假定柱子按照其上圆盘上数的大小从左向右排列，移动规则是从左向右看，
当前一根柱子最下圆盘上数与后一根柱子最上圆盘上数相加的和是一个完全平方数时，
前一根柱子上所有圆盘移动到后一根柱子上方。要求你编写程序，输入柱子数目和圆盘上的整数
，输出移动的过程和结果。例如，一组输入是：4，1，3，5，6，第一个数4表示有4根柱子，
圆盘上的数依次是1，3，5，6。你的程序运行后，可以输出1->3->6, 5, c=2，
表示移动是1到3，3到6，因为1+3=4, 3+6=9,而4和9是完全平方数，符合条件的移动只有这两次。
移动结果是还有2根柱子上有圆盘，即c=2，有圆盘的一根柱子上圆盘3个，有数1->3->6，
有圆盘另一根柱子上圆盘一个，有数5，它其实没有发生移动。程序编写完成后，要求给出你的程序对下列两组输入的结果：
（1）9，1，2，3，4，5，6，7，8，9    （2）10，1，3，5，7，9，11，13，15，17，19  （本题为2010年ACM大赛题目。）
提示：输入：9，1，2，3，4，5，6，7，8，9 输出：1->3->6, 2->7->9,4->5,8,c=4
输入：10，1，3，5，7，9，11，13，15，17,19 输出：1->3->13, 5->11,7->9,15,17->19,c=5*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node {
	int data;
	struct node *next;
}node;
typedef struct {
	node *a[100];
}ha;
void build(int n,ha *p)
{
	int i;
	node *px;
	for(i=0;i<n;i++)
	{
		p->a[i]=(node *)malloc(sizeof(node));
		p->a[i]->next=NULL;
	}
	printf("请输入柱子上盘子的数字\n");
	for(i=0;i<n;i++)
	{
		px=(node *)malloc(sizeof(node));
		px->next=NULL;
		scanf("%d",&px->data);getchar();
		p->a[i]->next=px;
	}
}
void output(node *p)
{
	node *px;
	px=p->next->next;
	printf("%d",p->next->data);
	while(px!=NULL)
	{
		printf("->%d",px->data);
		px=px->next;
	}
	printf(",");
}
void han(int n,ha *p)
{
	int i,j,k,d=0;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			k=p->a[i]->next->data+p->a[j]->next->data;
			if((sqrt(k)-(int)sqrt(k))==0)
			{
				p->a[j]->next->next=p->a[i]->next;
				p->a[i]->next=NULL;
				break;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(p->a[i]->next!=NULL)
		{
			output(p->a[i]);
			d++;
		}
	}
	printf("%d\n",d);
}
void main()
{
	int n;
	ha *p;
	p=(ha *)malloc(sizeof(ha));
	printf("请输入柱子数量\n");
	scanf("%d",&n);getchar();
	build(n,p);
	han(n,p);
}
	
