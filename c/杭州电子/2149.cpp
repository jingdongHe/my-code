#include<stdio.h>
int main()
{
	int n,m,i;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		if(m%(n+1)==0)
		{printf("none\n");continue;}
		if(n>m)
		{
			for(i=m;i<n;i++)
				printf("%d ",i);
			printf("%d\n",i);
		}
		else
			printf("%d\n",m%(n+1));
	}
	return 0;
}