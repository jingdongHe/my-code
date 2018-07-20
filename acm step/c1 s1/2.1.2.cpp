#include<stdio.h>
#include<math.h>
bool is_prime(int k)
{
	if(k==2||k==3) return true;
	for(int i=2;i<sqrt(k*1.0)+1;i++)
	{
		if(k%i==0) return false;
	}
	return true;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int k=0;
		for(int i=0;i<n;i++)
		{
			int d;
			scanf("%d",&d);
			if(is_prime(d)) k++;
		}
		printf("%d\n",k);
	}
	return 0;
}
