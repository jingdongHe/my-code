#include<stdio.h>
int Max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}
int max(int i,int j,int p[],int q[])
{
	if(i<0||j<0)
		return 0;
	if(p[i]==q[j])
		return max(i-1,j-1,p,q)+1;
	else
		return Max(max(i-1,j,p,q),max(i,j-1,p,q));
}
int main()
{
	int i,n,q,p;
	int P[250*250],Q[250*250];
	scanf("%d%d%d",&n,&q,&p);
	for(i=0;i<=p;i++)
		scanf("%d",&P[i]);
	for(i=0;i<=q;i++)
		scanf("%d",&Q[i]);
	printf("%d\n",max(q,p,Q,P));
	return 0;
}