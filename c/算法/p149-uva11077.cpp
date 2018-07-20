#include<cstdio>
#include<cstring>
const int maxn=25;
int main()
{
	unsigned long long f[maxn][maxn];
	int i,j;
	int n,k;
	memset(f,0,sizeof(f));
	f[1][0]=1;
	for(i=2;i<=21;i++)
	{
		for(j=0;j<i;j++)
		{
			//f[1][j]=0;
			f[i][j]+=f[i-1][j];
			if(j>0)
				f[i][j]+=f[i-1][j-1]*(i-1);
		}
	}
	/*for(i=1;i<=21;i++)
	{
		for(j=0;j<=i;j++)
			printf("%d ",f[i][j]);
		printf("\n");
	}*/
	while(scanf("%d%d",&n,&k)&&n&&k)
	{
		
		printf("%llu\n",f[n][k]);
	}
	return 0;
}