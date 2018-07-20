#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef struct node {
	int data;
	int sig;
}node;
bool comp(node x,node y)
{
	return x.data<y.data;
}
int main()
{
	int n,i,s,k,t,j;
	node A[500000];
	scanf("%d",&t);
	for(j=0;j<t;j++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&k);
			A[i].data=abs(k);
			if(k<0)
				A[i].sig=-1;
			else
				A[i].sig=1;
		}	
		sort(A,A+n,comp);
		k=0;s=0;
		for(i=0;i<n;i++)
		{
			if(A[i].sig!=s)
			{
				k++;
				s=A[i].sig;
			}
		}
		printf("%d\n",k);
	}
	return 0;
}