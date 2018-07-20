#include<stdio.h>
int take_y(int x,int n);
int take_x(int n);
int d=0;
int take_x(int t)
{
	int i,d,x;

	for(i=0;i<4;i++)
		{	
			if(t<0)
				break;
			switch(i)
			{
			case 0:x=1;d=take_y(x,t);return d;
			case 1:x=3;d=take_y(x,t);return d;
			case 2:x=7;d=take_y(x,t);return d;
			case 3:x=8;d=take_y(x,t);return d;
			}
		}
	return 0;
}
int take_y(int x,int t)//可取的值
{
	int i,y;
	for(i=0;i<4;i++)
	{
		switch(i)
		{
		case 0:y=1;t=t-y-x;printf("%d  1\n",t);if(t+y!=0&&t==0)d++;if(t>0) take_x(t);break;
		case 1:y=3;t=t-y-x;printf("%d  2\n",t);if(t+y!=0&&t==0)d++;if(t>0) take_x(t);break;
		case 2:y=7;t=t-y-x;printf("%d  3\n",t);if(t+y!=0&&t==0)d++;if(t>0) take_x(t);break;
		case 3:y=8;t=t-y-x;printf("%d  4\n",t);if(t+y!=0&&t==0)d++;if(t>0) take_x(t);break;
		}
	}
	return d;
	
}//t是总数，x是a拿的球，y是b拿的球
int main()
{
	int n,N,d;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d",&n);
		d=take_x(n);
		if(d==0)
			printf("0\n");
		else
			printf("1\n");
		d=0;
	}
	return 0;
}