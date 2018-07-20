#include<stdio.h>
int main()
{
	int a[1000]={0},n,i,m,d=0;
	while(scanf("%d",&n)!=EOF&&n>=0)
	{
		d++;
		m=n;
		//printf("%d",n);
		for(i=2;i<=(m/2+1);i++)
		{
			if(n%i==0)
			{
				a[i]++;
				n/=i;
				i=1;
				
			}
		}
		printf("Case %d.\n",d);
		for(i=2;i<=m/2+1;i++)
		{
			if(a[i]!=0)
			{
			printf("%d %d ",i,a[i]);
			a[i]=0;
			}
		}
		printf("\n\n");
	}
	return 0;
}
