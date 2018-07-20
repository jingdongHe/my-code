#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct node {
	int locat;
	char dis;
}node;
int comp(node x,node y)
{
	return x.locat<y.locat;
}
int main()
{
	int number;
	scanf("%d",&number);
	while(number--)
	{
		int L,T,n;
		int i;
		node A[10000];
		scanf("%d%d%d",&L,&T,&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&A[i].locat);
			getchar();
			A[i].dis=getchar();
			getchar();
		}
		sort(A,A+n,comp);
		/*for(i=0;i<n;i++)
			printf("%d %c\n",A[i].locat,A[i].dis);*/
		for(i=0;i<n;i++)
		{
			if(A[i].dis=='R')
				A[i].locat+=T;
			else
				A[i].locat-=T;
			if(A[i].locat>L||A[i].locat<0)
				A[i].dis='F';
		}
		sort(A,A+n,comp);
		for(i=0;i<n-1;i++)
		{
			if(A[i].locat==A[i+1].locat)
			{
				A[i].dis='t';
				A[i+1].dis='t';
			}
		}
		for(i=0;i<n;i++)
		{
			if(A[i].dis=='t')
				printf("%d Turning\n",A[i].locat);
			else 
			{
				if(A[i].dis=='F')
					printf("Fell off\n");
				else
					printf("%d %c\n",A[i].locat,A[i].dis);
			}
		}
	}
	return 0;
}