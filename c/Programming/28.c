#include<stdio.h>
#include<stdlib.h>
struct node {
	int a,b,c;
}p[100];
void Min(int n)
{
	int i,j,d=0;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i].a>p[j].a||p[i].b>p[j].b||p[i].c>p[j].c)
				break;
			else
			{
				d++;
				//printf("%d...%d...%d\n",p[i].a,p[i].b,p[i].c);
				break;
			}
		}
	}
	printf("��СԪ�ص���ĿΪ��%d\n",d);
}
void bu(int n)
{
	int i,j;
	struct node t;
	for(i=0;i<n;i++)
	{
		printf("���������Ƴɼ�\n");
		scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);getchar();
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i].a>p[j].a)
			{t=p[i];p[i]=p[j];p[j]=t;}
		}
	}
	//for(i=0;i<n;i++)
	//	printf("%d...%d...%d\n",p[i].a,p[i].b,p[i].c);
	Min(n);
}
void main()
{
	int n;
	printf("������ͬѧ����\n");
	scanf("%d",&n);getchar();
	bu(n);
}