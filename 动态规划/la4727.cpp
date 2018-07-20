#include<stdio.h>
const int maxn=50000+5;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a1,a2,a3;
		int n,k;
		scanf("%d%d",&n,&k);
		a1=0;
		for(int i=2;i<=n;i++)
		{
			a1=(a1+k)%i;
			if(i==2)
			{
				for(int k=0;k<=1;k++)
				{
					if(k!=a1)
					{
						a2=k;break;
					}
				}
			}
			else if(i==3)
			{
				a2=(a2+k)%i;
				for(int k=0;k<=2;k++)
				{
					if(k!=a1&&k!=a2)
					{
						a3=k;break;
					}
				}
				//printf("%d  %d  %d\n",a1,a2,a3);
			}
			else
			{
				a2=(a2+k)%i;
				a3=(a3+k)%i;
			}
		}
		printf("%d %d %d",a3+1,a2+1,a1+1);
		printf("\n");
	}
	return 0;
} 
