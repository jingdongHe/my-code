#include<stdio.h>
#include<math.h>
int main()
{
	int f[20];
	double s;int k=3;int n;
	f[0]=0;f[1]=1;f[2]=1;
	
	while(1)
	{
		f[k]=f[k-1]+f[k-2];
		if(f[k]>=1000)
			break;
		k++;
	}
	
	while(scanf("%d",&n)!=EOF)
	{
		if(n<=k)
		{
			printf("%d\n",f[n]);
			continue;
		}
		s=n*log10((1+sqrt(5.0))/2.0)-log10(sqrt(5.0));
		s=s-(int)s;
		s=pow(10.0,s);
		while(s<1000)
			s*=10;
		int q=s;
		printf("%d\n",q);
	}
	return 0;
}
