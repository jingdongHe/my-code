#include<stdio.h>
int main()
{
	int n;
	int a[20][20]={0};
	int f=0;//方向,d=0，顶上右；d=1，右往下；d=2，底下左；d=3，左往上
	int i=0,j=0;//数组
	int up=0,down,left=0,right;//四个阻拦方向
	int k;//计数

	scanf("%d",&n);
	down=right=n;
	for(k=1;k<=n*n;k++)
	{
		if(f==0)
		{
			if(i==right)
			{
				f=1;
				up++;
				j++;
				i--;
				k--;
				//printf(",,,,,,,,,,,,,,,,,,\n");
				continue;
			}
			else
			{
				a[i][j]=k;//printf("%d   %d\n",i,j);
				i++;
			}
		}
		if(f==1)
		{
			if(j==down)
			{
				f=2;
				right--;
				j--;
				i--;
				k--;
				continue;
			}
			else
			{
				a[i][j]=k;
				j++;
			}
		}
		if(f==2)
		{
			if(i+1==left)
			{
				f=3;
				i++;
				down--;
				j--;
				k--;
				continue;
			}
			else
			{
				a[i][j]=k;
				i--;
			}
		}
		if(f==3)
		{
			if(j+1==up)
			{
				f=0;
				j++;
				left++;
				i++;
				k--;
				continue;
			}
			else
			{
				a[i][j]=k;
				
				j--;
			}
		}
	}
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
		{
			printf("%3d",a[i][j]);
			if(i==n-1)
				printf("\n");
		}
	}
	return 0;
}
