#include<stdio.h>
typedef struct node {
	int a,b;
}node;
int min(int a,int b)
{
	if(a>b)
		return b;
	return a;
}
int Min(node A[],int i,int j)
{
	int k;
	int m=999,d;
	if(i==j)
		return 0;
	for(k=i;k<j;k++)
	{
		d=Min(A,i,k)+Min(A,k+1,j)+A[i].a*A[k].b*A[j].b;
		if(d<m)
			m=d;
	}
	return m;
}
int main()
{
	node A[100];
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d",&A[i].a,&A[i].b);
	printf("%d\n",Min(A,0,n-1));
	return 0;
}

