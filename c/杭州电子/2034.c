#include<stdio.h>
int main()
{
	int m,n,a[100],b[100],d=0,i,j,k=0,r;
	scanf("%d%d",&n,&m);
	while(m!=0&&n!=0)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(j=0;j<m;j++)
			scanf("%d",&b[j]);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(a[i]==b[j])
					a[i]='\0';
			}
		}
		for(i=0;i<n;i++)
		{
			if(a[i]!='\0')
				d++;
		}
		if(d==0)
			printf("NULL\n");
		else
		{
			for(i=0;i<n;i++)
			{
				if(a[i]!='\0')
				{
					a[k]=a[i];
					k++;
				}
			}
			for(i=0;i<k;i++)
			{
				for(j=i+1;j<=k;j++)
				{
					if(a[i]>a[j])
					{r=a[i];a[i]=a[j];a[j]=r;}
				}
			}
			for(i=0;i<k;i++)
			{
				
				if(i!=0)
					printf(" ");
				printf("%d",a[i]);
			}
			printf("\n");
		}
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			a[i]='\0';
		for(i=0;i<m;i++)
			b[j]='\0';
		d=0;k=0;
	}
	return 0;
}
