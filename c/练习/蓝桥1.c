#include<stdio.h>
int main()
{
	int i,x1,x2,x,r,y,s;
	//使用i计时,i每增加一次表示半分钟,
	x1=10;
	x=x1;
	r=0;s=1;
	x=10;y=90;
	y=y-x;
	for(i=1;i<=120;i++)
	{
		if(i%2!=0&&i>1)
		{y-=x;printf("%d\n",y);}
		if(i%4==0&&i>3)
		{y*=2;printf("%d\n",y);}
		if(i%6==0&&i>5)
		{x*=2;}
	
	printf("%d\n",y);}
	return 0;
}
	
