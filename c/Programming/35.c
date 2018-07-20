/*题目35：（1）设n是奇数，请编写程序构造n*n阶魔方阵，即行、列、两对角线上n个数之和相等的方阵，
图1是一个3*3魔方阵实例。提示：（2）构造3*3素数魔方阵
即找出9个不大于500的素数并排成魔方阵，图2是一个实例，其行、列、两对角线上3个数之和都是177。
　　　8  1  6              17  113   47
　　　3  5  7              89   59   29
　　　4  9  2              71    5  101
　　　图1奇数阶魔方阵     图2 素数魔方阵
（可查阅：杨克昌编著，计算机程序设计典型例题精解，
国防科技大学大学出版社，1999年3月，第157-162页）
提示：（1）构造规则是：数1填在第一行中间，从2开始，
i+1放在i的上一行后一列（如5在4右上），若格位置超界，
则对n取模（如2右上出界，取模到左方），若应放数处已有数，
则放在此数下（如7放6下，4放3下）。（2）思路是枚举所有可能性，
但要设法减少枚举范围。例如分析3*3素数魔方阵可知它应有形式：
		 n-x  n+w  n-y
         n+z   n   n-z
         n+y  n-w  n-x
中间行列和对角线之和都是3n，其它行列也应是，
可推知z=x-y, w=x+y等关系。因此可生成小于500所有素数，
对每个这样的素数n，枚举x，y，检查是否素数魔方阵。*/
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
