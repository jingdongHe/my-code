#include<stdio.h>
int main()
{
	int i,n,num1,num2,sum,k,j,d;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&num1,&num2);
		if(num1>num2)
		{d=num1;num1=num2;num2=d;}
		sum=0;d=0;
		for(i=num1;i<=num2;i++)
		{
			k=i;
			//printf("%d\n",i);
			for(j=1;j<i/2+1;j++)
			{
				if(k%j==0)
				{
					sum+=j;
					//printf("%d]]]]\n",j);
				}
			}
			
		//	printf("%d....\n",sum);
			if(sum==i)
				d++;
			sum=0;
		//	printf("%d[[[[\n",d);
		//	printf("--------------------\n");
		}
		printf("%d\n",d);
	}
	return 0;
}
