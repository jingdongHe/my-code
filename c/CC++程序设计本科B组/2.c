#include<stdio.h>
//ab * cde = adb * ce
int main()
{
	int a,b,c,d,e;
	int k=0;
	for(a=1;a<=9;a++)
	{
		for(b=1;b<=9;b++)
		{
			if(b==a)
				continue;
			for(c=1;c<=9;c++)
			{
				if(c==a||c==b)
					continue;
				for(d=1;d<=9;d++)
				{
					if(d==a||d==b||d==c)
						continue;
					for(e=1;e<=9;e++)
					{
						if(e==a||e==b||e==c||e==d)
							continue;
						if((a*10+b)*(c*100+d*10+e)==(a*100+d*10+b)*(c*10+e))
						{
							k++;
							printf("%d-%d-%d-%d-%d\n",a,b,c,d,e);
						}
					}
				}
			}
		}
	}
	printf("%d\n",k);
	return 0;
}