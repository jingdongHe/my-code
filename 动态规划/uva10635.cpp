#include<stdio.h>
#include<string.h>
const int maxn=25*25+5;
int main()
{
	int T;
	int n,p,q;
	int A[maxn],B[maxn];
	scanf("%d",&T);
	for(int t=0;t<T;t++)
	{
		scanf("%d%d%d",&n,&p,&q);
		for(int i=0;i<p+1;i++)
			scanf("%d",&A[i]);
		for(int i=0;i<q+1;i++)
			scanf("%d",&B[i]);
		int d[maxn][maxn];
		for(int i=0;i<=p+1;i++)
			d[0][i]=d[i][0]=0;
		for(int i=1;i<=p+1;i++)
		{
			for(int j=1;j<=q+1;j++)
			{
				if(A[i]==B[j])
					d[i][j]=d[i-1][j-1]+1;
				else
					d[i][j]=d[i-1][j]>d[i][j-1]?d[i-1][j]:d[i][j-1];
			}
		}
		printf("%d\n",d[p+1][q+1]);
	}
	return 0;
}
