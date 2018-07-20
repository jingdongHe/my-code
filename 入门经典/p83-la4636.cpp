#include<stdio.h>
const int maxn=100+5;
int main()
{
	int f,l;
	int F[maxn],L[maxn];
	int sum=0;
	scanf("%d%d",&f,&l);
	for(int i=0;i<f;i++)
	{
		scanf("%d",&F[i]);
		sum+=F[i];
	}
	for(int i=0;i<l;i++)
	{
		scanf("%d",&L[i]);
		for(int j=0;j<f;j++)
		{
			if(L[i]==F[j]) {F[j]=0;break;}
		}
		sum+=L[i];
	}
	printf("%d\n",sum);
	return 0;
}
