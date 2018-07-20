#include<stdio.h>
#include<string.h>
const int maxn=110000;int arr[maxn][11],res[maxn][11];
int main()
{
	
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		memset(arr,0,sizeof(arr));
		memset(res,0,sizeof(res));
		int time_max=0;int a,b;
		res[0][5]=maxn;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			arr[b][a]++;
			if(b==0) res[0][a]+=1;
			if(b>time_max) time_max=b;
		}
		
		for(int i=1;i<=time_max;i++)
		{
			for(int j=0;j<=10;j++)
			{
				res[i][j]=res[i-1][j];
				if(j>0&&res[i][j]<res[i-1][j-1])
					res[i][j]=res[i-1][j-1];
				if(j<10&&res[i][j]<res[i-1][j+1])
					res[i][j]=res[i-1][j+1];
				res[i][j]+=arr[i][j];
			}
		}
		/*for(int i=1;i<=time_max;i++)
		{
			for(int j=0;j<=10;j++)
				printf("%d ",res[i][j]);
			printf("\n");
		}*/
		int max=0;
		for(int i=0;i<=10;i++)
			if(res[time_max][i]>max) max=res[time_max][i];
		printf("%d\n",max%maxn);
	}
	return 0;
}
