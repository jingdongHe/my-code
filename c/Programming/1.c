/*题目1：文件存取练习：要求实现如下功能：
（1）定义函数Rand1000(), 随机生成1000个均不相同的正整数，并写入到文本文件“file1.dat”
 中，各数之间用空格来分隔。
 （2）编写一个函数input（int a[],int n），将上述数据读入到数组a中。
 （3）编写一个函数digitcount(int a[],int n,int b[10]), 
 统计数组a的每个元素保存的整数中，每位数字出现的次数，并分别保存在b[0]到b[9]中。
 （4）编写函数maxprime(int *p,int n), 找出其中最大的素数，如果不存在素数函数结果为0。
 （5） 对于这些整数排序之后，分别输出相邻两数之差最大和之差最小的两个数，如果有多组满足条件要输出所有的。
 （6）定义函数myinput(int a[],int n)，用fgetc函数从文件“file1.dat”上逐个读入字符，
 并将其转换成独立的正整数,并依次存入数组a中。
提示：可查阅任何一本C语言程序设计教科书中关于文件部分，例如谭浩强，C程序设计（第三版），
第13章。还需要熟悉随机数生成函数rand（），需要编写判断一个奇整数是否素数的程序等。*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define M 1000
typedef struct node{//建立结构体，为第5问准备
	int big;
	int small;
	struct node *next;
}link;
void Rand1000()//生成1000个随机的正整数，并写入到文本文件“1.dat”中
{
	int i;
	int a[M]={0};
	FILE *p1;//p1指向需要操作的文件
	p1=fopen("1.dat","w");//以只写模式打开文件（文档）
	srand((unsigned  int )time(0));//设置种子
	for(i=0;i<M;i++)
		fprintf(p1,"%d ",rand());//写入随机数
	fclose(p1);//关闭文件
}
void input(int a[],int n)//将数据读入到数组a中,考点是读取文件的内容
{
	int i;
	FILE *p1;//用p1指向需操作的文件
	p1=fopen("1.dat","r");//以只读模式打开文件
	for(i=0;i<M;i++)//以下两行意为将文件内的数据读入a中
		fscanf(p1,"%d",&a[i]);
	//a[i-1]=3;
	fclose(p1);//关闭文件
}
void output(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
void digitcount(int a[],int n,int b[10])//统计数组a的每位数字出现的次数
{
	int i,d;
	for(i=0;i<n;i++)
	{
		d=a[i];//用d来表示数组a中的每个数，此处不直接用a进行操作是为了防止破坏a数组的数据
		while(d!=0)//以下三行表示将d拆分成一个一个的数字。如d=123，拆成3、2、1,321是析出顺序
		{
			b[d%10]++;//对d的个位进行操作
			d=d/10;
		}
	}
}
int maxprime(int a[],int n)//找出其中最大的素数
{
	int i,j,d,k=0;
	for(i=0;i<n;i++)//遍历数组a中每一个数据
	{
		d=0;
		for(j=2;j<sqrt(a[i]+1);j++)//判断a[i]是否为素数
		{
			if(a[i]%j==0&&a[i]!=j)//d=0是素数,d=1不是素数
			{d=1;break;}
		}
		if(d==0&&a[i]>k)//d是素数，并且大于原本我们认为的最大素数k时，用a[i]代替k
			k=a[i];
	}
	return k;//如果整个数组中不存在素数，则返回k=0
}
//对于这些整数排序之后，分别输出相邻两数之差最大和之差最小的两个数，如果有多组满足条件要输出所有的。（难点在于要输出多组满足条件的数据）
//以下的qss,Qs函数为，快速排序详情参考数据结构教材的222页
//此处的排序也可以用传统的冒泡排序法
int qss(int a[],int i,int j)
{
	int x;
	x=a[i];
	while(i<j)
	{
		while(i<j&&a[j]>=x)
			j--;
		a[i]=a[j];
		while(i<j&&a[i]<=x)
			i++;
		a[j]=a[i];
	}
	a[i]=x;
	return i;
}
void QS(int a[],int i,int j)
{
	int k;
	if(i<j)
	{
		k=qss(a,i,j);
		QS(a,i,k-1);
		QS(a,k+1,j);
	}
	return ;
}
//排序已经排完，下面几个函数用于查找差值最大、最小的相邻两数
//以下用链表来存储多组差值最大最小的相邻两数，此处也可用数组做
//若用数组做，可以做一个简单的一维数组来存储差值最大的相邻两数，如：a[0]=1,a[1]=100,a[2]=101,a[2]=200输出时成对输出即可
// b_link()、push()、FREE()、output_link()为链表的基本操作
link *b_link()//建立链表
{
	link *p;
	p=(link *)malloc(sizeof(link));
	p->next=NULL;
	return p;
}
void push(link *p,int a,int b)//将数据a、b压人（存入）链表p中
{
	link *p1;
	p1=(link *)malloc(sizeof(link));
	p1->big=a;
	p1->small=b;
	p1->next=p->next;
	p->next=p1;
}

void FREE(link *p)//清空链表p
{
	link *p1,*p2;
	p1=p->next;
	p->next=NULL;
	while(p1!=NULL)
	{
		p2=p1;
		p1=p1->next;
		free(p2);
	}
}
void output_link(link *p)//打印链表p
{
	link *p1;
	p1=p->next;
	while(p1!=NULL)
	{
		printf("%d...%d",p1->big,p1->small);
		p1=p1->next;
		printf("\n");
	}
}
void difference_max_min(int a[])
{
	int i,k;
	//int j,b,c,d;
	int Max=0,Min=999;
	link *p1,*p2;
	p1=b_link();
	p2=b_link();//p1代表差值最大的多组数，p2代表差值最小的多组数
	for(i=1;i<M;i++)
	{
		k=a[i]-a[i-1];//用k来计算（表示相邻两项的差）
		//printf("%d ",k);
		if(k<Min)//如果k<min，将链p1清空，再把已知的更加小的一对存入，然后用k来代替min
		{FREE(p1);push(p1,a[i],a[i-1]);Min=k;continue;}
		if(k==Min)//如果k与min相等，则不用清空链p1，直接将差值为min的一对数存入即可
		{push(p1,a[i],a[i-1]);continue;}
		//查找差值最大的相邻两个数与查找差值最小的相邻两个数原理类似
		if(k>Max)
		{FREE(p2);push(p2,a[i],a[i-1]);Max=k;continue;}
		if(k==Max)
		{push(p2,a[i],a[i-1]);continue;}
	}
	printf("\n相邻两数之差最小的几对为:\n");
	output_link(p1);
	printf("之差最大的几对为:\n");
	output_link(p2);
}
void main()
{
	int a[1000];
	int b[10]={0};
	//int k;
	Rand1000();
	input(a,M);
	output(a,M);
	printf("每位数字出现的次数为:\n");
	digitcount(a,M,b);
	output(b,10);
	printf("==========================================\n");
	if(maxprime(a,M))
	{
		printf("最大的素数为:%d\n",maxprime(a,M));
	}
	else
		printf("不存在最大素数\n");
	printf("==========================================\n");
	printf("排序后的输出为:\n");
	QS(a,0,M-1);
	output(a,M);
	printf("==========================================\n");
	difference_max_min(a);
	
}