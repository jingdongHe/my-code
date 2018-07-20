#include<stdio.h>
int main()
{
	int n,a[99],d,k,i;
	scanf("%d",&n);
	while(n!=0)
	{
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		d=a[0];
		for(i=0;i<n;i++)
		{
			if(a[i]<=d) {d=a[i];k=i;}
		}
		d=a[0];a[0]=a[k];a[k]=d;
		for(i=0;i<n;i++)
		{
		printf("%d",a[i]);
		if(i!=n-1)
			printf(" ");
		}
		printf("\n");
		scanf("%d",&n);
	}
	return 0;
}

