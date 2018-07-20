#include<stdio.h>
#include<string.h>
int main()
{
	char a[1001][15];
	int i,n,b[100],k,max,j,t=0;
	while(scanf("%d",&n)!=EOF&&n>0&&n<=1000)
	{
		for(i=0;i<100;i++)
			b[i]='\0';
		for(i=0;i<n;i++)
		{
			scanf("%s",a[i]);
			getchar();
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(strcmp(a[i],a[j])==0)
				{
					b[i]++;
					memset(a[j],'\0',15);
				}
			}
		}
		for(i=0;i<n;i++)
			printf("%d//////\n",b[i]);
		max=b[0];k=0;t=0;
		for(i=1;i<n;i++)
		{
			if(max<b[i])
			{
				max=b[i];
				k=i;
			}
		}
		printf("%s\n",a[k]);
	}
	return 0;
}
