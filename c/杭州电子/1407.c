#include<stdio.h>
#include<math.h>
int main()
{
	int num,x,y,z,d;
	while(scanf("%d",&num)!=EOF&&num>0&&num<=10000){d=0;
	for(x=1;x<sqrt(num);x++)
	{
		if(d==1)
			break;
		for(y=x;y<sqrt(num);y++)
		{
			if(d==1)
				break;
			for(z=y;z<sqrt(num);z++)
			{
				if(x*x+y*y+z*z==num)
				{
					printf("%d %d %d\n",x,y,z);
					d=1;
					break;
				}
			}
		}
	}}
	return 0;
}