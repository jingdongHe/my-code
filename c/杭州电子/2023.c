#include<stdio.h>
int main()
{
	int m,n,i,j,k=0,p=0;
	double average,sum,b[5],a[50][5];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			scanf("%lf",&a[i][j]);
		}
		sum=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				sum+=a[i][j];
			average=sum/m;//学生平均成绩
			printf("%0.2f",average);
			sum=0;
			if(i!=n-1)
				printf(" ");
		}
		printf("\n");
		sum=0;
		for(j=0;j<m;j++)
		{
			for(i=0;i<m;i++)
				sum+=a[i][j];
			average=sum/n;
			b[k]=average;
			k++;//科目平均成绩
			printf("%0.2f",average);
			sum=0;
			if(j!=m-1)
				printf(" ");
		}
		printf("\n");
		sum=0;
		k=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(a[i][j]<b[j])
				{
					k++;
                    if(k==m)
			        p++;
				}
			}
		k=0;	
		}
		printf("%d\n",p);
		p=0;k=0;sum=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				a[i][j]='\0';
		}
	}
	return 0;
}


