/*��Ŀ1���ļ���ȡ��ϰ��Ҫ��ʵ�����¹��ܣ�
��1�����庯��Rand1000(), �������1000��������ͬ������������д�뵽�ı��ļ���file1.dat��
 �У�����֮���ÿո����ָ���
 ��2����дһ������input��int a[],int n�������������ݶ��뵽����a�С�
 ��3����дһ������digitcount(int a[],int n,int b[10]), 
 ͳ������a��ÿ��Ԫ�ر���������У�ÿλ���ֳ��ֵĴ��������ֱ𱣴���b[0]��b[9]�С�
 ��4����д����maxprime(int *p,int n), �ҳ�����������������������������������Ϊ0��
 ��5�� ������Щ��������֮�󣬷ֱ������������֮������֮����С��������������ж�����������Ҫ������еġ�
 ��6�����庯��myinput(int a[],int n)����fgetc�������ļ���file1.dat������������ַ���
 ������ת���ɶ�����������,�����δ�������a�С�
��ʾ���ɲ����κ�һ��C���Գ�����ƽ̿����й����ļ����֣�����̷��ǿ��C������ƣ������棩��
��13�¡�����Ҫ��Ϥ��������ɺ���rand��������Ҫ��д�ж�һ���������Ƿ������ĳ���ȡ�*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define M 1000
typedef struct node{//�����ṹ�壬Ϊ��5��׼��
	int big;
	int small;
	struct node *next;
}link;
void Rand1000()//����1000�����������������д�뵽�ı��ļ���1.dat����
{
	int i;
	int a[M]={0};
	FILE *p1;//p1ָ����Ҫ�������ļ�
	p1=fopen("1.dat","w");//��ֻдģʽ���ļ����ĵ���
	srand((unsigned  int )time(0));//��������
	for(i=0;i<M;i++)
		fprintf(p1,"%d ",rand());//д�������
	fclose(p1);//�ر��ļ�
}
void input(int a[],int n)//�����ݶ��뵽����a��,�����Ƕ�ȡ�ļ�������
{
	int i;
	FILE *p1;//��p1ָ����������ļ�
	p1=fopen("1.dat","r");//��ֻ��ģʽ���ļ�
	for(i=0;i<M;i++)//����������Ϊ���ļ��ڵ����ݶ���a��
		fscanf(p1,"%d",&a[i]);
	//a[i-1]=3;
	fclose(p1);//�ر��ļ�
}
void output(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
void digitcount(int a[],int n,int b[10])//ͳ������a��ÿλ���ֳ��ֵĴ���
{
	int i,d;
	for(i=0;i<n;i++)
	{
		d=a[i];//��d����ʾ����a�е�ÿ�������˴���ֱ����a���в�����Ϊ�˷�ֹ�ƻ�a���������
		while(d!=0)//�������б�ʾ��d��ֳ�һ��һ�������֡���d=123�����3��2��1,321������˳��
		{
			b[d%10]++;//��d�ĸ�λ���в���
			d=d/10;
		}
	}
}
int maxprime(int a[],int n)//�ҳ�������������
{
	int i,j,d,k=0;
	for(i=0;i<n;i++)//��������a��ÿһ������
	{
		d=0;
		for(j=2;j<sqrt(a[i]+1);j++)//�ж�a[i]�Ƿ�Ϊ����
		{
			if(a[i]%j==0&&a[i]!=j)//d=0������,d=1��������
			{d=1;break;}
		}
		if(d==0&&a[i]>k)//d�����������Ҵ���ԭ��������Ϊ���������kʱ����a[i]����k
			k=a[i];
	}
	return k;//������������в������������򷵻�k=0
}
//������Щ��������֮�󣬷ֱ������������֮������֮����С��������������ж�����������Ҫ������еġ����ѵ�����Ҫ��������������������ݣ�
//���µ�qss,Qs����Ϊ��������������ο����ݽṹ�̲ĵ�222ҳ
//�˴�������Ҳ�����ô�ͳ��ð������
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
//�����Ѿ����꣬���漸���������ڲ��Ҳ�ֵ�����С����������
//�������������洢�����ֵ�����С�������������˴�Ҳ����������
//������������������һ���򵥵�һά�������洢��ֵ���������������磺a[0]=1,a[1]=100,a[2]=101,a[2]=200���ʱ�ɶ��������
// b_link()��push()��FREE()��output_link()Ϊ����Ļ�������
link *b_link()//��������
{
	link *p;
	p=(link *)malloc(sizeof(link));
	p->next=NULL;
	return p;
}
void push(link *p,int a,int b)//������a��bѹ�ˣ����룩����p��
{
	link *p1;
	p1=(link *)malloc(sizeof(link));
	p1->big=a;
	p1->small=b;
	p1->next=p->next;
	p->next=p1;
}

void FREE(link *p)//�������p
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
void output_link(link *p)//��ӡ����p
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
	p2=b_link();//p1�����ֵ���Ķ�������p2�����ֵ��С�Ķ�����
	for(i=1;i<M;i++)
	{
		k=a[i]-a[i-1];//��k�����㣨��ʾ��������Ĳ
		//printf("%d ",k);
		if(k<Min)//���k<min������p1��գ��ٰ���֪�ĸ���С��һ�Դ��룬Ȼ����k������min
		{FREE(p1);push(p1,a[i],a[i-1]);Min=k;continue;}
		if(k==Min)//���k��min��ȣ����������p1��ֱ�ӽ���ֵΪmin��һ�������뼴��
		{push(p1,a[i],a[i-1]);continue;}
		//���Ҳ�ֵ������������������Ҳ�ֵ��С������������ԭ������
		if(k>Max)
		{FREE(p2);push(p2,a[i],a[i-1]);Max=k;continue;}
		if(k==Max)
		{push(p2,a[i],a[i-1]);continue;}
	}
	printf("\n��������֮����С�ļ���Ϊ:\n");
	output_link(p1);
	printf("֮�����ļ���Ϊ:\n");
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
	printf("ÿλ���ֳ��ֵĴ���Ϊ:\n");
	digitcount(a,M,b);
	output(b,10);
	printf("==========================================\n");
	if(maxprime(a,M))
	{
		printf("��������Ϊ:%d\n",maxprime(a,M));
	}
	else
		printf("�������������\n");
	printf("==========================================\n");
	printf("���������Ϊ:\n");
	QS(a,0,M-1);
	output(a,M);
	printf("==========================================\n");
	difference_max_min(a);
	
}