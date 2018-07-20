#include<stdio.h>
long long f(int p[],int i,int finish)
{
	if(i==0) return 0;
	if(p[i]==finish) return f(p,i-1,finish);
	return f(p,i-1,6-finish-p[i])+1<<(i-1);
}
int main()
{
	int star[60+5],final[60+5];
	int n;
	int c=0;
	while(scanf("%d",&n)&&n!=0)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&star[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&final[i]);
		int k=n;
		while(k>0&&star[k]==final[k]) k--;
		if(k==0) printf("Case %d: 0\n",++c);
		else
		{
			printf("Case %d: %lld\n",++c,f(star,k-1,6-star[k]-final[k])+f(final,k-1,6-star[k]-final[k])+1);
		}
	}
	return 0;
}
