#include<stdio.h>
int main()
{
	int a,b,m,n,sum=0,i,j,d=1,r;
	//float k;
	while(scanf("%d",&r)!=EOF)
	{
	while(r)
	{
		d=1;sum=0;
		scanf("%d%d",&n,&m);
		while(n!=0&&m!=0)
		{
			for(i=2;i<n;i++)
			{
				b=i;
				for(j=1;j<i;j++)
				{
					a=j;
					if((float)(a*a+b*b+m)/(a*b)-(int)(a*a+b*b+m)/(a*b)==0)
						sum++;
				}
			}
			printf("Case %d:",d);
			printf(" %d\n",sum);
			sum=0;
			scanf("%d%d",&n,&m);
			d++;
		}
		if(r!=1)
			printf("\n");
		r--;
		}
	}
	return 0;
}

