#include<stdio.h>
int main()
{
	int a,b,c,d,e,i,x,y,z;//x为该数字，y倒置，z数字
	for(x=10000;x<100000;x++)
	{
		a=x/10000%10;
		b=x/1000%10;
		c=x/100%10;
		d=x/10%10;
		e=x%10;
		if(a==b||a==c||a==d||a==e||b==c||b==d||b==e||c==d||c==e||d==e)
			continue;
		if(e==0)
			continue;
		y=e*10000+d*1000+c*100+b*10+a;
		for(z=2;z<10;z++)
		{
		if(x*z==y)
			printf("%d*%d=%d\n",x,z,y);
		}
	}
	return 0;
}
