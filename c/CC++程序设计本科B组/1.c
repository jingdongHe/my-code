#include<stdio.h>
int main()
{
/*1777年4月30日。此处需注意，该天是第1天，不是第0天*/
	int i,n;
	int y,m,d;
	
	while(scanf("%d",&n)==1)
	{
	y=1777;m=4;d=30;
	for(i=1;i<n;i++)
	{
		d++;
		if(m==2)
		{
			if(y==1780||y==1784||y==1788||y==1792||y==1796)
			{
				if(d>=30)
				{
					d=d-29;
					m++;
				}
			}
			else
			{
				if(d>=29)
				{
					d=d-28;
					m++;
				}
			}
		}
		if(m==4||m==6||m==9||m==11)
		{
			if(d>=31)
			{
				d=d-30;
				m++;
			}
		}
		if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		{
			if(d>=32)
			{
				d=d-31;
				m++;
			}
		}
		if(m>=13)
		{
			m=m-12;
			y++;
		}
	}
	printf("%d-%d-%d\n",y,m,d);
	}
	return 0;
}