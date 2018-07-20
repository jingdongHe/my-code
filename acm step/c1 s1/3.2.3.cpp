#include<stdio.h>
#include<string.h>
const int maxn=1000+5;
int a[maxn];
int f[maxn][maxn];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		memset(f,0,sizeof(f));
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			f[i][i]=a[i];
		}
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(a[i]<a[j])
					f[i][j]=f[i][i]+a[j];
				else f[i][j]=0;
				f[j][j]=f[j][j]>f[i][j]?f[j][j]:f[i][j];
			}
		}
		/*for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				printf("%d ",f[i][j]);
			printf("\n");
		}*/
		int max=0;
		for(int i=0;i<n;i++)
			if(max<f[i][i]) max=f[i][i];
		printf("%d\n",max);
	}
	return 0;
}
