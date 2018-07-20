#include<stdio.h>
int take_y(int x,int n);
int take_x(int n);
int take_x(int n)
{
	int i,d,x;
	for(i=0;i<4;i++)
		{
			d=0;
			switch(i)
			{
			case 0:x=1;d=take_y(x,n);return d;break;
			case 1:x=3;d=take_y(x,n);return d;break;
			case 2:x=7;d=take_y(x,n);return d;break;
			case 3:x=8;d=take_y(x,n);return d;break;
			}
		}
	return 0;
}
int take_y(int x,int n)//可取的值
{
	int i,y,t,d=0;
	for(i=0;i<4;i++)
	{
		switch(i)
		{
		case 0:y=1;t=n-1-y-x;if(t==0)d++;break;
		case 1:y=3;t=n-1-y-x;if(t==0)d++;break;
		case 2:y=7;t=n-1-y-x;if(t==0)d++;break;
		case 3:y=8;t=n-1-y-x;if(t==0)d++;break;
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
	}
	return 0;
}
