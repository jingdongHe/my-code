#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct {
	char english[10];
	char china[20];
}node;
typedef struct {
	node *a[7];
}keyword;
void intialize(keyword *k)
{
	node *p;
	p=(node *)malloc(sizeof(node));
	strcpy(p->english,"int");
	strcpy(p->china,"整型变量");
	k->a[0]=p;
	p=(node *)malloc(sizeof(node));
	strcpy(p->english,"auto");
	strcpy(p->china,"声明自动变量");
	k->a[1]=p;
	p=(node *)malloc(sizeof(node));
	strcpy(p->english,"long");
	strcpy(p->china,"长整型");
	k->a[2]=p;
	p=(node *)malloc(sizeof(node));
	strcpy(p->english,"double");
	strcpy(p->china,"双精度");
	k->a[3]=p;
	p=(node *)malloc(sizeof(node));
	strcpy(p->english,"unsigned");
	strcpy(p->china,"无符号");
	k->a[4]=p;
	p=(node *)malloc(sizeof(node));
	strcpy(p->english,"break");
	strcpy(p->china,"跳出当前循环");
	k->a[5]=p;
	p=(node *)malloc(sizeof(node));
	strcpy(p->english,"continue");
	strcpy(p->china,"开始下一轮循环");
	k->a[6]=p;
}
void translat(keyword *k,char a[])
{
	
	int i;
	if(a[0]>='a'&&a[0]<='z')//为英文字符
	{
		for(i=0;i<7;i++)
		{
			//printf("%s",k->a[i]->english);
			if(strcmp(a,k->a[i]->english)==0)
			{puts(k->a[i]->china);return;}
		}
	}
	else
	{
		for(i=0;i<7;i++)
		{
			if(strcmp(a,k->a[i]->china)==0)
			{puts(k->a[i]->english);return;}
		}
	}
}
void main()
{
	char a[20]={'\0'};
	int i;
	keyword *k;
	k=(keyword *)malloc(sizeof(keyword));
	intialize(k);	
	printf("请输入需要翻译的关键字,输入bye结束\n");
	scanf("%s",&a);getchar();
	while(strcmp(a,"bye")!=0)
	{
		translat(k,a);
		printf("请输入需要翻译的关键字,输入bye结束\n");
		for(i=0;i<20;i++)
			a[i]='\0';
		gets(a);
	}
}