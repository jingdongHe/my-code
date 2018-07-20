#include<stdio.h>
int main()
{
	int m,n,i,j;
	float a[50][5],sum1,average,sum2;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				scanf("%f",&a[i][j]);
		}
		sum1=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				sum1+=a[i][j];
		    average=sum1/m;//学生平均成绩
			printf("%f.......",sum1);
	    	printf("%.2f",average);
			if(i!=n-1)
				printf(" ");
		}
		printf("\n");
		sum2=0;
		for(j=0;j<m;j++)
		{
			for(i=0;i<n;i++)
				sum2+=a[i][j];	
			sum2-=sum1;printf("%f........",sum2);
			average=sum2/n;//科目平均成绩
			
			printf("%.2f",average);
			if(j!=m-1)
				printf(" ");
		}
		printf("\n");
		sum2=0;
	}
	return 0;
}
