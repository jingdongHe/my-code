#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int d;
	struct node *next;
}node;//用node来存储每个保安要求休息的时间
typedef struct {
	char a;
	struct node *next;
}day;//7个保安的休息日总成
typedef struct {
	day *a[7];
}se;
typedef struct result{
	char a[7];
	struct result *next;
}result;
se *b_link()
{
	int i;
	se *a;
	a=(se *)malloc(sizeof(se));
	
	for(i=0;i<7;i++)
	{
		a->a[i]=(day *)malloc(sizeof(day));
		a->a[i]->a='a'+i;//printf("1111111111111\n");
		a->a[i]->next=NULL;//printf("222222222222\n");
	}
	//for(i=0;i<7;i++)
	//	printf("%c ",a->a[i]->a);
	//printf("\n");
	return a;
}
void output_link(se *a)
{
	int i;
	node *p;
	for(i=0;i<7;i++)
	{
		printf("%c",a->a[i]->a);
		p=a->a[i]->next;
		while(p!=NULL)
		{printf("->%d",p->d);p=p->next;}
		printf("\n");
	}
}
void push(se *a,int i,int k)//将每个保安想要休息的时间压入链表中
{
	node *p,*px,*pp;
	px=(node *)malloc(sizeof(node));
	px->d=k;
	px->next=NULL;
	p=a->a[i]->next;
	if(p==NULL)
		a->a[i]->next=px;
	else
	{
		while(p!=NULL)
		{
			pp=p;
			p=p->next;
		}
		pp->next=px;
	}
}
void entry(se *a)//输入保安想要休息的时间
{
	int i,d;
	for(i=0;i<7;i++)
	{
		printf("请输入第%d人想要的休息时间,以9结束\n",i+1);//0为周日
		scanf("%d",&d);getchar();
		while(d!=9)
		{
			push(a,i,d);
			scanf("%d",&d);getchar();
		}
	}
}
int full(char a[])
{
	int i,d=0;
	for(i=0;i<7;i++)
	{
		//printf("%c ",a[i]);
		if(a[i]=='\0')
			d=1;
	}
	if(d==1)return 0;
	if(d==0)return 1;
	return 0;
}
void output_result(result *head)
{
	int i,k[7];
	int d=1;
	result *p;
	p=head->next;
	if(p!=NULL)
		printf("             赵    钱    孙    李    周    吴    陈\n");
	else
	{printf("NO\n");return;}
	while(p!=NULL)
	{
		for(i=0;i<7;i++)
		{
			k[p->a[i]-97]=i;
		}
		i=k[0];k[0]=k[1];k[1]=i;
		printf("Solution: %d ",d++);
		for(i=0;i<7;i++)
		{
			switch(k[i])
			{
			case 1:{printf("周一  ");break;}
			case 2:{printf("周二  ");break;}
			case 3:{printf("周三  ");break;}
			case 4:{printf("周四  ");break;}
			case 5:{printf("周五  ");break;}
			case 6:{printf("周六  ");break;}
			case 0:{printf("周日  ");break;}
			}
		}
		printf("\n");
		p=p->next;
	}
}
void copy(char a[],result *head)
{
	int i;
	result *px,*p;
	p=head;
	while(p->next!=NULL)
		p=p->next;
	px=(result *)malloc(sizeof(result));
	for(i=0;i<7;i++)
		px->a[i]=a[i];
	px->next=NULL;
	p->next=px;
}
void search(se *a,int i,char b[],result *c)
{
	node *p;
	if(full(b))
	{copy(b,c);puts(b);return;}//printf("11111111111\n");
	if(i==7)
		return;
	p=a->a[i]->next;
	while(p!=NULL)
	{
		if(b[p->d]=='\0')
		{
			b[p->d]=a->a[i]->a;
			//printf("%c ",a->a[i]->a);
			search(a,i+1,b,c);
			b[p->d]='\0';
		}
		p=p->next;
	}
	return;
}
void main()
{	
	se *a;
	char b[8]={'\0'};
	result *c;
	c=(result *)malloc(sizeof(result));
	c->next=NULL;
	a=b_link();
	entry(a);
	output_link(a);
	search(a,0,b,c);
	output_result(c);
}