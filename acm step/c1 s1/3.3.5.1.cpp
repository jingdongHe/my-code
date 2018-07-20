#include<stdio.h>
#include<string.h>
const int maxn=10000+5;
int f[maxn];int word[12][12];
int n,c;
void zore_one_pack(int cost,int value)
{
	for(int i=c;i>=cost;i--)
		if(f[i]<f[i-cost]+value) f[i]=f[i-cost]+value;
}
void complete_pack(int cost,int value)
{
	for(int i=cost;i<=c;i++)
		if(f[i]<f[i-cost]+value) f[i]=f[i-cost]+value;
}
void multiple_pack(int cost,int value,int amount)
{
	if(value*amount>=c)
		complete_pack(cost,value);
	for(int k=1;k<=amount;k*=2)
	{
		zore_one_pack(k*cost,k*value);
		amount-=k;
	}
	if(amount)
		zore_one_pack(amount*cost,amount*value);
}
int main()
{
	while(scanf("%d%d",&n,&c)==2)
	{
		memset(f,0,sizeof(f));
		memset(word,0,sizeof(word));
		char s[15];
		int a,b;
		for(int i=0;i<n;i++)
		{
			scanf("%s%d%d",&s,&b,&a);
			word[a][b]++;
		}
		for(int i=0;i<11;i++)
		{
			for(int j=0;j<11;j++)
				if(word[i][j]) multiple_pack(i,j,word[i][j]);
		}
		/*for(int i=0;i<=c;i++)
			printf("%d ",f[i]);
		printf("\n");*/
		printf("%d\n",f[c]);
	}
	return 0;
}
