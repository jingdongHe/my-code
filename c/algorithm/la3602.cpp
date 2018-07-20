#include<stdio.h>
#include<string.h>
const int maxn=1000+10;
const int maxm=50+5;
int main()
{
	int seq[4];
	char D[maxm][maxn];
	//int D1[maxm][maxn];
	char S[maxn];
	int i,j,T,f;
	int n,m;
	scanf("%d",&T);
	while(T--)
	{
	scanf("%d%d",&m,&n);getchar();
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			scanf("%c",&D[i][j]);
		getchar();
	}
	//memset(D1,0,sizeof(D1));
	f=0;
	for(i=0;i<n;i++)
	{
		memset(seq,0,sizeof(seq));
		for(j=0;j<m;j++)
		{
			if(D[j][i]=='A')
				seq[0]++;
			if(D[j][i]=='C')
				seq[1]++;
			if(D[j][i]=='G')
				seq[2]++;
			if(D[j][i]=='T')
				seq[3]++;
		}
		int d=0,k=0;
		for(j=0;j<4;j++)
		{
			if(k<seq[j])
			{k=seq[j];d=j;}
		}
		for(j=0;j<4;j++)
		{
			if(j!=d)
				f+=seq[j];
		}
		if(d==0)
			S[i]='A';
		if(d==1)
			S[i]='C';
		if(d==2)
			S[i]='G';
		if(d==3)
			S[i]='T';
		/*for(j=0;j<m;j++)
		{
			if(D[j][i]==S[i])
				D1[j][i]+=D1[j][i-1]+1;
			else
				D1[j][i]=D1[j][i-1];
		}*/
	}
	for(i=0;i<n;i++)
		printf("%c",S[i]);
	printf("\n%d\n",f);
	}
	return 0;
}