/*��Ŀ35����1����n�����������д������n*n��ħ���󣬼��С��С����Խ�����n����֮����ȵķ���
ͼ1��һ��3*3ħ����ʵ������ʾ����2������3*3����ħ����
���ҳ�9��������500���������ų�ħ����ͼ2��һ��ʵ�������С��С����Խ�����3����֮�Ͷ���177��
������8  1  6              17  113   47
������3  5  7              89   59   29
������4  9  2              71    5  101
������ͼ1������ħ����     ͼ2 ����ħ����
���ɲ��ģ���˲������������������Ƶ������⾫�⣬
�����Ƽ���ѧ��ѧ�����磬1999��3�£���157-162ҳ��
��ʾ����1����������ǣ���1���ڵ�һ���м䣬��2��ʼ��
i+1����i����һ�к�һ�У���5��4���ϣ�������λ�ó��磬
���nȡģ����2���ϳ��磬ȡģ���󷽣�����Ӧ��������������
����ڴ����£���7��6�£�4��3�£�����2��˼·��ö�����п����ԣ�
��Ҫ�跨����ö�ٷ�Χ���������3*3����ħ�����֪��Ӧ����ʽ��
		 n-x  n+w  n-y
         n+z   n   n-z
         n+y  n-w  n-x
�м����кͶԽ���֮�Ͷ���3n����������ҲӦ�ǣ�
����֪z=x-y, w=x+y�ȹ�ϵ����˿�����С��500����������
��ÿ������������n��ö��x��y������Ƿ�����ħ����*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#define n 5
int q[100];
int a[3][3];
void b_a()
{
	int a[n][n];
	int i,j;
	int x,y;
	memset(a,0,sizeof(a));
	x=0;y=n/2;
	//printf("%d......%d\n",x,y);
	a[x][y]=1;
	for(i=2;i<=n*n;i++)
	{
		//printf("%d......%d\n",x,y);
		if(a[(x-1+n)%n][(y+1)%n]!=0)
			x=(x+1)%n;
		else
		{x=(x-1+n)%n;y=(y+1)%n;}
		a[x][y]=i;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%-4d ",a[i][j]);
		printf("\n");
	}
}
int is_su(int d)
{
	int i;
	if(d<=1)
		return 0;
	for(i=2;i<sqrt(d)+1;i++)
	{
		if(d%i==0)
			return 0;
	}
	return 1;
}
void su()
{
	int i;
	int d=0;
	for(i=2;i<500;i++)
	{
		if(is_su(i))
		{
			//printf("%d ",i);
			q[d++]=i;
		}
	}
//	printf("\n%d\n",d);
}
int thim(int b[])
{
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=i+1;j<9;j++)
		{
			if(b[i]==b[j])
				return 1;
		}
	}
	return 0;
}
void output()
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			printf("%5d",a[i][j]);
		printf("\n");
	}
	printf("----------------\n");
}
void b_su()
{
	int x,y,m;
	int i,j,k,r;
	int c[9];
	for(i=0;i<94;i++)
	{
		m=q[i];
		for(j=0;j<94;j++)
		{
			x=q[j];
			for(k=0;k<94;k++)
			{
				y=q[k];
				//printf("%d....%d.....%d\n",x,y,m);
				if((is_su(3*m-x-y)==0)||(is_su(x+y-m)==0)||(is_su(2*m-x)==0)||(is_su(2*m-y)==0)||(is_su(m-y+x)==0)||(is_su(m+y-x)==0))
					continue;
				//memset(c,0,sizeof(c));
				c[0]=x;c[1]=y;c[2]=m;c[3]=3*m-x-y;c[4]=x+y-m;c[5]=2*m-x;c[6]=2*m-y;c[7]=m-y+x;c[8]=m+y-x;
				//for(r=0;r<9;r++)
				//	printf("%6d",c[r]);
				//printf("\n");
				if(thim(c)==1)
					continue;
				else
				{
					a[0][0]=x;a[0][1]=3*m-x-y;a[0][2]=y;a[1][0]=m+y-x;a[1][1]=m;a[1][2]=m-y+x;a[2][0]=2*m-y;a[2][1]=x+y-m;a[2][2]=2*m-x;
					output();
				}
			}
		}
	}
}
void main()
{
	//int i;
	b_a();
	printf("======================\n");
	su();
	//for(i=0;i<94;i++)
	//	printf("%d  ",q[i]);
	b_su();
}
