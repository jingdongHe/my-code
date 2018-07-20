#include<stdio.h>
int main()
{
	int x0,x1,x2,x3;
	double z;//x为共有多少人，z为船长喝的数量
	for(x0=20;x0>=7;x0--)//刚开始
	{
		for(x1=1;x1<x0;x1++)//第一轮倒下
		{
			for(x2=1;x2<x0-x1;x2++)//第二轮倒下
			{
				for(x3=1;x3<x0-x1-x2;x3++)//第三轮倒下
				{
					z=1.0/x0+1.0/(x0-x1)+1.0/(x0-x1-x2)+1.0/(x0-x1-x2-x3);
					if(z==1)
						printf("%d  %d  %d  %d  %d\n",x0,x0-x1,x0-x1-x2,x0-x1-x2-x3);
				}
			}
		}
	}
	return 0;
}



