#include<stdio.h>
#include<string.h>
const int maxn=100+5;
const int maxm=20+5;
const int maxs=10;
const int INF=0x3f3f3f3f;
int main()
{
	int s,m,n;
	int M[maxm][maxs],N[maxn][maxs];
	int cost_m[maxm],cost_n[maxn];
	int teach_m[maxm],teach_n[maxn];
	
	
	memset(teach_m,0,sizeof(teach_m));
	memset(teach_n,0,sizeof(teach_n));
	
	
	scanf("%d%d%d",&s,&m,&n);getchar();
	for(int i=0;i<m;i++)
	{
		scanf("%d",&cost_m[i]);
		M[i][0]=1;
		char ch=getchar();
		while(ch!='\n')
		{
			int d;
			scanf("%d",&d);
			M[i][M[i][0]++]=d;
			teach_m[i]|=(1<<d-1);
			ch=getchar();
		}
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&cost_n[i]);
		N[i][0]=1;
		char ch=getchar();
		while(ch!='\n')
		{
			int d;
			scanf("%d",&d);
			N[i][N[i][0]++]=d;
			teach_n[i]|=(1<<d-1);
			ch=getchar();
		}
	}
	
	/*for(int i=0;i<m;i++)
	{
		printf("%d :%2d-",cost_m[i],teach_m[i]);
		for(int j=1;j<M[i][0];j++)
			printf("%d ",M[i][j]);
		printf("\n");
	}
	for(int i=0;i<n;i++)
	{
		printf("%d :%2d-",cost_n[i],teach_n[i]);
		for(int j=1;j<N[i][0];j++)
			printf("%d ",N[i][j]);
		printf("\n");
	}*/
	int a=0,b=0,sum=0;
	int MAXS=(1<<s)-1;
	
	for(int i=0;i<m;i++)
	{
		b|=(a&teach_m[i]);
		a|=teach_m[i];
		sum+=cost_m[i];
	}
	//printf("%d   %d   %d\n",a,b,MAXS);
	
	int f[MAXS+5][MAXS+5];
	memset(f,INF,sizeof(f));
	f[a][b]=sum;
	for(int i=0;i<n;i++)
	{
		for(int s1=0;s1<=MAXS;s1++)
		{
			for(int s2=0;s2<=MAXS;s2++)
			{
				if(f[s1][s2]>=INF) continue;
				int st2=(teach_n[i]&s1)|s2;int st1=teach_n[i]|s1;
				
				f[st1][st2]=f[st1][st2]<f[s1][s2]+cost_n[i]?f[st1][st2]:f[s1][s2]+cost_n[i];
				//printf("%d:(%d,%d) %d   %d.......\n",i,s1,s2,f[s1][s2],f[st1][st2]);
			}
		}
	}
	printf("%d\n",f[MAXS][MAXS]);
	return 0;
}
