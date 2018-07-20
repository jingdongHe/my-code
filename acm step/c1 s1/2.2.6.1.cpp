#include<stdio.h>
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		printf("%d %d ",a,b);
		int max=0;
		if(a>b){int temp=a;a=b;b=temp;}
		for(int i=a;i<=b;i++)
		{
			int k=1;
			int s=i;
			while(s!=1)
			{
				//printf("%d...\n",i);
				if(s&1==1) s=s*3+1;
				else s/=2;
				k++;
				
			}
			if(k>max) max=k;
		}
		printf("%d\n",max);
	}
	return 0;
}
