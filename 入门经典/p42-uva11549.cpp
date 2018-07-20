#include<stdio.h>
int cal(int n,int k)
{
	long long res=k*k;
	int number[20];
	int i=0;
	while(res)
	{
		number[i++]=res%10;
		res/=10;
	}
	int d=i;int ans=0;
	n=n>d?d:n;
	for(i=0;i<n;i++)
		ans=ans*10+number[--d];
	return ans;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int res=0;
	int k1=k,k2=k;
	do
	{
		k1=cal(n,k1);
		res=res>k1?res:k1;
		k2=cal(n,k2);
		k2=cal(n,k2);
	}
	while(k1!=k2);
	printf("%d\n",res);
	return 0;
}
