#include<stdio.h>
int main()
{
	int T,n,p1,p2;
	double d[100][100]={0};
	int i,j;
	d[0][0]=1;d[0][1]=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);getchar();
		scanf("%d",&p1);getchar();
		scanf("%d",&p2);getchar();
		for(i=1;i<=n;i++)
		{
			for(j=0;j*p2<=p1*i;j++)
			{
				if(j>0)
					d[i][j]=d[i-1][j]*(p2-p1)/p2+d[i-1][j-1]*p1/p2;
				else
					d[i][j]=d[i-1][j]*(p2-p1)/p2;
			}
		}
		double q=0;
		for(i=0;i*p2<=n*p1;i++)
			q+=d[n][i];
		printf("%d\n",(int)(1/q));
	}
	return 0;
}