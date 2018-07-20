#include<stdio.h>
#include<string.h>
const int MOD=10000007;
int main()
{
	int T,m,n,k;int sum=0,R,C;
	int c[500][500];
	c[0][0]=1;
	int i,j;
	for(i=0;i<500;i++)
	{
		c[i][0]=c[i][i]=1;
		for(j=1;j<i;j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
	}
	scanf("%d",&T);
	while(T--)
	{
		//memset(c,0,sizeof(c));
		scanf("%d%d%d",&m,&n,&k);
		sum=0;
		sum=(sum+c[m*n][k])%MOD;
		sum=(sum+c[(n-2)*(m-2)][k])%MOD;
		C=n;R=m;
		sum=(sum-c[(R-1)*C][k]*2+MOD)%MOD;
		sum=(sum-c[(C-1)*R][k]*2+MOD)%MOD;
		sum=(sum+c[(R-2)*C][k])%MOD;sum=(sum+c[(C-2)*R][k])%MOD;
		sum=(sum+c[(R-1)*(C-1)][k]*4)%MOD;
		sum=(sum-c[(R-2)*(C-1)][k]*2+MOD)%MOD;
		sum=(sum-c[(R-1)*(C-2)][k]*2+MOD)%MOD;
		printf("%d\n",sum);
	}
	return 0;
}
		
