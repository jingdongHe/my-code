#include<stdio.h>
int main()
{
	double vul,d;
	int time,k,i;
	while(scanf("%lf%lf",&vul,&d)!=EOF)
	{
		time=0;k=1;
		while(vul>0)
		{
			for(i=0;i<k;i++)
			{
				vul-=d;
				time++;
				if(vul<=0)
					break;
			}
			k++;
			if(vul>0)
				time++;
			//printf("%lf        %lf         %d\n",vul,d*k,time);
		}
		printf("%d\n",time);
	}
	return 0;
}
