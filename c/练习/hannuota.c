#include<stdio.h>
int k=0;
int hannuota(int n,char a,char b,char c);
int hannuota(int n,char a,char b,char c)
{	
	if(n==1)
	{
		
		printf("%d form %c to %c\n",n,a,c);
		k++;
		//printf("%d  1\n",k);
	}
	else
	{
		//printf("%d  2\n",k);
		hannuota(n-1,a,c,b);
		k++;
		//printf("%d  3\n",k);
		printf("%d form %c to %c\n",n,a,c);
		hannuota(n-1,b,a,c);
	}
	return k;
}
int main()
{
	int n;
	long k=0;
	char a='a',b='b',c='c';
	while(scanf("%d",&n)!=EOF)
	{
		k=hannuota(n,a,b,c);
		printf("%ld\n",k);
	}
	return 0;
}