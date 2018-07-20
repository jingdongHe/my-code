#include<stdio.h>
#include<string.h>
typedef struct node {
	int value,complexity;
}node;
const int maxn=100000+5,maxm=10000+5;
node word[maxn];int f[maxm];
int main()
{
	int n,c;
	while(~scanf("%d%d",&n,&c))
	{
		char s[20];
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
			scanf("%s%d%d",&s,&word[i].value,&word[i].complexity);
		for(int i=1;i<=n;i++)
		{
			for(int j=c;j>=word[i].complexity;j--)
			{
				if(f[j]<f[j-word[i].complexity]+word[i].value)
					f[j]=f[j-word[i].complexity]+word[i].value;
			}
		}
		for(int i=0;i<=c;i++)
			printf("%d ",f[i]);
		printf("\n");
		printf("%d\n",f[c]);
	}
	return 0;
}
