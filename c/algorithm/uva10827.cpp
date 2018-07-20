#include<stdio.h>
#include<string.h>
const int maxn=75+5;
int main()
{
	int T;
	int max=0;
	scanf("%d",&T);
	while(T--)
	{
		int map[2*maxn][2*maxn];
		int sum[2*maxn][2*maxn];
		int i,j,n;
		scanf("%d",&n);max=0;
		memset(map,0,sizeof(map));
		memset(sum,0,sizeof(sum));
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i==0)
				{map[i][j]=0;continue;}
				if(j==0)
				{map[i][j]=0;continue;}
				scanf("%d",&map[i][j]);
				sum[i][j]=sum[i+n][j]=map[i+n][j]=map[i][j];
				sum[i][j+n]=map[i][j+n]=map[i][j];
				sum[i+n][j+n]=map[i+n][j+n]=map[i][j];
			}
		}
		for(i=1;i<=2*n;i++)
		{
			for(j=1;j<=2*n;j++)
				sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
		}
		/*for(i=0;i<=2*n;i++)
		{
			for(j=0;j<=2*n;j++)
				printf("%4d",sum[i][j]);
			printf("\n");
		}*/
		int y1,y2;
		int a[2*maxn];
		int b[2*maxn]={0};
		int c[2*maxn];
		for(y1=1;y1<=2*n;y1++)
		{
			for(y2=y1;y2<y1+n&&y2<=2*n;y2++)
			{
				for(i=1;i<=2*n;i++)
					a[i]=(sum[y2][i]-sum[y2][i-1])-(sum[y1-1][i]-sum[y1-1][i-1]);
				//b[1]=a[1];c[1]=1;
				/*
				for(i=1;i<=2*n;i++)
					printf("%d  ",a[i]);
				printf("\n");*/
				c[0]=0;
				for(i=1;i<=2*n;i++)
					c[i]=a[i]+c[i-1];
				for(i=1;i<=2*n;i++)
				{
					for(j=i;j<i-1+n&&j<=2*n;j++)
					{
						int d=c[j]-c[i-1];
						if(d>max)
						{max=d;}//printf("%d %d:%d %d  %d\n",y1,y2,i,j,d);
					}
				}
				/*printf("%d  %d:\n",y1,y2);
				for(i=1;i<=2*n;i++)
					printf("%d ",a[i]);
				printf("\n");
				for(i=1;i<=2*n;i++)
					printf("%d ",c[i]);
				printf("\n");*/
				/*while(i<=2*n)
				{
					if(c[i-n])
					{
						if(b[i-1]+a[i]-a[i-n]>a[i])
						{c[i]=1;b[i]=b[i-1]-a[i-n]+a[i];if(b[i]>max) max=b[i];}
						else
						{memset(c,0,sizeof(c));c[i]=1;b[i]=a[i];if(b[i]>max) max=b[i];}
					}
					else
					{
						if(b[i-1]+a[i]>=a[i])
						{c[i]=1;b[i]=b[i-1]+a[i];if(b[i]>max) max=b[i];}
						else
						{memset(c,0,sizeof(c));c[i]=1;b[i]=a[i];if(b[i]>max) max=b[i];}
					}
					//printf("%d    222222222\n",max);
					i++;
				}*/
				/*for(i=1;i<=2*n;i++)
					printf("%d  ",b[i]);
				printf("\n");*/
			}
		}
		printf("%d\n",max);
	}
	return 0;
}