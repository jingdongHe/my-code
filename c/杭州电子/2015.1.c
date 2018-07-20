#include<stdio.h>
int main()
{
	int a[100],m,n,i,j,sum=0,k;
	while(scanf("%d%d",&n,&m)!=EOF){
	a[0]=2;sum=0;k=0;
	for(i=1;i<n;i++)
	{
		a[i]=a[i-1]+2;
	}
	j=n%m;
	for(i=1;i<=n-j;i++)
	{
		sum+=a[i-1];
		if(i%m==0)
		{
			k=sum/m;
			printf("%d",k);sum=0;
			if(i!=n-j) printf(" ");
		}
	}
	sum=0;
	if(j!=0)
	{
		while(n>j+1)
		{
		    sum+=a[n-1];
			n--;
		}
		k=sum/j;
		printf(" %d",k);
	}
	printf("\n");
	for(i=1;i<n;i++)
	{
		a[i-1]='\0';
	}}
	return 0;
}
