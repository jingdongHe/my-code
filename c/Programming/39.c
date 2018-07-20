#include<stdio.h>//注意到若x=a2-b2, y=2ab, z=a2+b2, 则x, y, z是一组勾股数。
#include<math.h>
void main()
{
	int x,y,z;
	int a,b;
	for(a=1;a<10;a++)
	{
		for(b=1;b<10;b++)
		{
			x=a*a-b*b;
			if(x>=100)
				continue;
			if(x<=0)
				break;
			y=2*a*b;
			if(y>=100)
				break;
			z=a*a+b*b;
			if(z>=100)
				break;
			printf("%d^2+%d^2=%d^2\n",x,y,z);
		}
	}

}