#include<stdio.h>
#include<string.h>
const int maxn=300+10;
int m,n;
int C[maxn][maxn];
int min(int a,int b)
{
	if(a>b)
		return b;
	return a;
}
int cut(int m,int n)
{
	if(C[m][n]!=-1)
		return C[m][n];
	int i;
	int Min=9999999;
	if(m==0||n==0)
	{C[m][n]=C[n][m]=0;}
	else if(m==1)
	{C[m][n]=C[n][m]=n-1;}
	else if(n==1)
	{C[m][n]=C[n][m]=m-1;}
	else{
	for(i=1;i<m;i++)
		Min=min(Min,cut(i,n)+cut(m-i,n)+1);//¶ÔºáÅÅÇĞ
	for(i=1;i<n;i++)
		Min=min(Min,cut(m,i)+cut(m,n-i)+1);//¶ÔÊúÌõÇĞ
	C[m][n]=C[n][m]=Min;
	}
	//printf("%d %d:%d\n",m,n,C[m][n]);
	return C[m][n];
}
int main()
{
	memset(C,-1,sizeof(C));
	C[1][1]=0;C[2][1]=C[1][2]=1;
	C[2][2]=3;
	int k=cut(300,300);
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		printf("%d\n",C[m][n]);
	}
	return 0;
}
