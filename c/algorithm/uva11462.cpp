#include<stdio.h>
#include<string.h>
int main()
{
	int ago[102];
	int i,n,d;
	while(scanf("%d",&n)!=EOF&&n)
	{
		memset(ago,0,sizeof(ago));
		for(i=0;i<n;i++)
		{
			scanf("%d",&d);
			ago[d]++;
		}
		int j,k=1;
		for(i=0;i<101;i++)
		{
			for(j=0;j<ago[i];j++)
			{
				if(!k)
					printf(" ");
				k=0;
				printf("%d",i);
			}
		}
		printf("\n");
	}
	return 0;
}