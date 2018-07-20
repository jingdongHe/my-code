#include<stdio.h>
int jie(int n)
{
	int i,k=1;
	if(n==0)
		return 1;
	k=1;
	for(i=1;i<=n;i++)
	{
		k=k*i;
		//printf("%d....%d\n",i,k);
	}
	//printf("\n");
	return k;
}
int main()
{
	int f[100]={0};
	int d,sum;
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&d);
		if(d!=-1)
			f[d]++;
	}
	sum=1;
	for(i=0;i<n;i++)
	{
		sum*=jie(i);}
		//printf("%d......\n",jie(i));
	d=jie(n);printf("%d.....%d\n",sum,d);
	
	sum=d/sum;
	printf("%d\n",sum);
	return 0;
}