/*������5. ������ü�������²��û������ǡ���ĳ���˿��ƣ��������һ���˿��ƣ�54�ţ���������27�ţ�
�ڷ��ڲ�ͬ�������ϣ�ÿ��9�ţ����û������ǡ�ĳ��ֽ�ƣ�������߼�����������ǡ�������ֽ�ƴ�����һ���У�
֮�����������ν�ֽ�����°ڷţ������û��ٻش�������ͬ�����ʣ�����ֽ�������°ڷź��ִ�����һ���ϣ���
��ʱ������Ὣ�û��������ǡ�������ֽ�Ƹ���������
���������磬����ִ�к����Ļ��ʾ��������Ϊ�����е�ǰ׺a��b��c��d�������ֲ�ͬ�Ļ�ɫ����
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn=27;
int pai[maxn];
bool used[54];
int pick[54];
void PickUp()
{
	memset(used,false,sizeof(used));
	srand((unsigned)time(NULL));
	int k=0;
	while(k<maxn)
	{
		int d=rand()%54;
		if(!used[d])
		{
			used[d]=true;
			pai[k++]=d;
		}
	}
}
void change(int i)
{
	int k=13;
	if(i==53)
		{printf("KING2 ");return;}
		if(i==52)
		{printf("KING1 ");return;}
		if(i/k==0)
			printf("a-");
		if(i/k==1)
			printf("b-");
		if(i/k==2)
			printf("c-");
		if(i/k==3)
			printf("d-");
		int d=i%k;
		if(d+1==11)
			printf("J ");
		if(d+1==12)
			printf("Q ");
		if(d+1==13)
			printf("K ");
		if(d+1<=10)
			printf("%d ",d+1);
}
void Print()
{
	int i,k=13,d=1;;
	for(i=0;i<maxn;i++)
	{
		if(i%9==0)
			printf("Line\n%d:   ",d++);
		if(pai[i]==53)
		{printf("KING2 ");if(i!=0&&(i+1)%9==0) printf("\n");continue;}
		if(pai[i]==52)
		{printf("KING1 ");if(i!=0&&(i+1)%9==0) printf("\n");continue;}
		if(pai[i]/k==0)
			printf("a-");
		if(pai[i]/k==1)
			printf("b-");
		if(pai[i]/k==2)
			printf("c-");
		if(pai[i]/k==3)
			printf("d-");
		int d=pai[i]%k;
		if(d+1==11)
			printf("J ");
		if(d+1==12)
			printf("Q ");
		if(d+1==13)
			printf("K ");
		if(d+1<=10)
			printf("%d ",d+1);
		if(i!=0&&(i+1)%9==0)
			printf("\n");
	}
}
void exchange(int &a,int &b)
{
	int temp;
	temp=a;a=b;b=temp;
}
void Shuffle()
{
	int i;
	srand((unsigned)time(NULL));
	for(i=0;i<maxn;i++)
	{
		int d=rand()%maxn;
		exchange(pai[i],pai[d]);
	}
}
void Rember()
{
	int i,k;
	memset(pick,false,sizeof(pick));
	for(i=0;i<3;i++)
	{
		printf("-------------------------------------------------------------\n");
		Print();
		printf("-------------------------------------------------------------\nRemember a card, and tell me what line it reside in(1/2/3): ");
		scanf("%d",&k);
		for(int j=maxn/3*(k-1);j<maxn/3*k;j++)
		{pick[pai[j]]++;}
		printf("\n");
		Shuffle();
	}
}
void find()
{
	int i;
	for(i=0;i<54;i++)
	{
		if(pick[i]==3)
		{
			change(i);
			printf("\n");
		}
	}
}
int main()
{
	PickUp();
	Rember();
	find();
	return 0;
}