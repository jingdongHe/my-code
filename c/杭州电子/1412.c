#include<stdio.h>
int a[20000]={'\0'};
int main()
{
	int n,m,i,d=0,k,j;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		d=0;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(;i<m+n;i++)
			scanf("%d",&a[i]);//����֤����
		for(i=0;i<m+n;i++)//ȥ����ͬԪ�أ�����֤
		{
			for(j=i+1;j<m+n+1;j++)
			{
				if(a[i]==a[j])
				{a[j]='\0';}
			}
		}
		for(i=0;i<m+n;i++)
		{
			for(j=i+1;j<m+n+1;j++)
			{
				if(a[i]>a[j])
				{k=a[i];a[i]=a[j];a[j]=k;}
			}
		}
		for(i=0;i<=m+n;i++)
		{
			if(a[i]==0)
				d++;
			if(a[i]!='\0')
			{
				if(i==d)
				{printf("%d",a[i]);
				a[i]='\0';}
				else
				{printf(" %d",a[i]);
				a[i]='\0';}
			}
		}
		printf("\n");
	}
	return 0;
}
