#include<stdio.h>
int main()
{
	int n,a[55],i;
	scanf("%d",&n);
	a[0]=1;a[1]=2;a[2]=3;a[3]=4;
	while(n!=0)
	{
		if(n<=3)
		printf("%d\n",a[n-1]);
		if(n>3)
		{
			for(i=3;i<n;i++)
			a[i]=a[i-1]+a[i-3];
			printf("%d\n",a[i-1]);
		}
	    scanf("%d",&n);
	}
	return 0;
}


