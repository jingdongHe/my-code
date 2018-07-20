#include<stdio.h>
#include<string.h>
#define M 100000000
int ans[8000][255];
int main()
{
	memset(ans,0,sizeof(ans));
	for(int i=1;i<5;i++)
		ans[i][0]=1;
	for(int i=5;i<8000;i++)
	{
		for(int j=0;j<255;j++)
		{
			ans[i][j]+=ans[i-1][j]+ans[i-2][j]+ans[i-3][j]+ans[i-4][j];
			ans[i][j+1]+=ans[i][j]/M;
			ans[i][j]=ans[i][j]%M;
		}
	}
	int n; 
	while(scanf("%d",&n)!=EOF)
	{
		int i;
		for(i=254;i>=0;i--)
		{
			if(ans[n][i]) break;
		}
		printf("%d",ans[n][i--]);
		while(i>=0)
			printf("%.8d",ans[n][i--]);
		printf("\n");
	}
	return 0;
}
