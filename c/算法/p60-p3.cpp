#include<stdio.h>
int coin[100],n;
int min(int s)
{
	int i,m=9999,d;
	if(s==0)
		return 0;
	if(s<0)
		return m;
	for(i=0;i<n;i++)
	{
		d=min(s-coin[i]);
		if(m>d)
			m=d;
	}
	return m+1;
}
int max(int s)
{
	int i,m=-1,d;
	if(s==0)
		return 0;
	if(s<0)
		return -2;
	for(i=0;i<n;i++)
	{
		d=max(s-coin[i]);
		if(m<d)
			m=d;
	}
	return m+1;
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&coin[i]);
	printf("%d\n%d\n",min(5),max(5));
	return 0;
}