#include<stdio.h>
void main()
{
	int x1,x2,x3,x4,x5;//最后剩下x个
	int a[5];
	int i=0,x;
	while(1)
	{
		i++;
		x=4*i;
		x5=x*5/4+1;//第5只猴子看到这么多桃子
		if(x5%4!=0)
			continue;
		x4=x5*5/4+1;
		if(x4%4!=0)
			continue;
		x3=x4*5/4+1;
		if(x3%4!=0)
			continue;
		x2=x3*5/4+1;
		if(x2%4!=0)
			continue;
		x1=x2*5/4+1;
		break;
	}
	for(i=0;i<5;i++)
	{
		a[i]=(x1-1)/5+1;
		x1-=a[i];
	}
	for(i=0;i<5;i++)
		printf("第%d只猴子拿了%d个桃子\n",i+1,a[i]);
	printf("最后剩下%d只桃子\n",x1);
}
