/*������11����ͼ��ɫ
��������ͼ���в�ͬ���ң���ͬ���򣩣�ÿ�����Ҷ�������һЩ�����ڽӡ���Ҫ��Ե�ͼ��ɫ��ʹ���еĹ����������ڽӵĹ����в�ͬ����ɫ��
ͨ����������ɫ�����㹻��
��������ʾ���ɲ�ȡ��̽�ķ����𲽱ƽ����⣬����ĳ��ģʽ����һ�����ֽ⣬������Ƿ�ϸ�
��Ϊ�ϸ�����չ������ֽ�������ƽ�������Ϊ���ϸ񣬲��������չ������ֽⶼ����õ����⡣
��ʱ������������ɵĲ��ֽ��е�ĳЩ���������˷������ǰ�Ĳ��ֽ⣬������һ�����ֽ⣬ֱ��������⡣
�����㷨��Ϊ��˷�㷨������ɫһ����������ĵ�ͼΪ����*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int maxn=4;
class result{
private:
	int n;
	bool *array;
	int *contry;
public:
	void insert(int a,int b)
	{
		array[a*n+b]=true;
		array[b*n+a]=true;
	}
	result()
	{
		scanf("%d",&n);
		array=(bool *)malloc(sizeof(bool)*n*n);
		contry=(int *)malloc(sizeof(int)*n*n);
		int i;int a,b;
		for(i=0;i<n*n;i++)
			array[i]=false;
		for(i=0;i<n;i++)
			contry[i]=-1;
		printf("�������ԣ���-1��-1����\n");
		scanf("%d%d",&a,&b);
		while(a!=-1&&b!=-1)
		{	a--;b--;
			insert(a,b);
			scanf("%d%d",&a,&b);
		}
	}
	void huishuo(int k)
	{
		int i,j;
		if(k>=n)
		{
			for(i=0;i<=n;i++)
			{
				if(contry[i]==0) printf("�� ");
				if(contry[i]==1) printf("�� ");
				if(contry[i]==2) printf("�� ");
				if(contry[i]==3) printf("�� ");
			}
			printf("\n");
			return;
		}
		int f;
		for(i=0;i<maxn;i++)
		{
			f=0;
			for(j=0;j<n;j++)
			{
				if(array[k*n+j]==true&&contry[j]==i)
				{f=1;break;}
			}
			if(f) continue;
			contry[k]=i;
			huishuo(k+1);
		}
	}
};
int main()
{
	result r;
	r.huishuo(0);
	return 0;
}