#include<stdio.h>
int main()
{
	int a,b,m,n,r,d,k;
	scanf("%d%d",&a,&b);
	m=a;n=b;
	if(m<n)
	{r=m;m=n;n=r;}
	r=m%n;
	if(r==0)
	k=n;
	while(r!=0)
	{m=n;n=r;r=m%n;}
	k=n;
	printf("%d,%d\n",k,(a*b)/k);
}
