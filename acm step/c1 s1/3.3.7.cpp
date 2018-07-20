#include<stdio.h>
const int maxn=100+5;
typedef struct node {
	float probability;
	int money;
}node;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		float P;
		int N,M=0;
		scanf("%f%d",&P,&N);P=1-P;
		node bank[maxn];
		for(int i=1;i<=N;i++)
		{float b;scanf("%d%f",&bank[i].money,&b);bank[i].probability=1.0-b;M+=bank[i].money;}
		float f[maxn*maxn]={0};
		f[0]=1;
		for(int i=1;i<=N;i++)
		{
			for(int j=M;j>=0;j--)
			{
				if(f[j-bank[i].money]*bank[i].probability>f[j])
					f[j]=f[j-bank[i].money]*bank[i].probability;
			}
		}
		for(int i=M;i>=0;i--)
			if(f[i]>=P) {printf("%d\n",i);break;}
	}
	return 0;
}
