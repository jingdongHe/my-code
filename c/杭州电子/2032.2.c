#include<stdio.h>
int main()
{
	int m,n,i,j,k=0,s=0,r=0;//k�ж�ĳ����k�ųɼ�����ƽ���ɼ���r�ж���r��ѧ��k�Ŷ�����ƽ���ɼ�
	float a[50][5],sum,average,d[5];//dΪ5��������ƽ���ɼ�
	while(scanf("%d%d",&n,&m)!=EOF)//a[50][5]Ϊѧ��ÿ�ųɼ�������
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				scanf("%f",&a[i][j]);
		}
		sum=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{sum+=a[i][j];}
			average=sum/j;
			printf("%.2f",average);
			if(i!=n-1)
				printf(" ");
			sum=0;
		}
		printf("\n");
		sum=0;
		for(j=0;j<m;j++)
		{
			for(i=0;i<n;i++)
				sum+=a[i][j];
			average=sum/i;
			d[s]=average;
			s++;
			printf("%.2f",average);
			if(j!=m-1)
				printf(" ");
			sum=0;
		}
		printf("\n");
		r=0;
		for(i=0;i<n;i++)
		{
			k=0;
			for(j=0,s=0;j<m;j++,s++)
			{
				if(a[i][j]>=d[s])
					k++;
				if(k==m-1)
					r++;
			}
		}
		printf("%d\n",r);
		r=0;k=0;sum=0;
	}
	return 0;
}
		