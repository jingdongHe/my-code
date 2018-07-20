#include<stdio.h>
typedef struct node {
	int r,d,w;
}node;
int main()
{
	int Max,Min,i,j,n;
	int d;
	double s;
	node A[100];
	while(1)
	{
	scanf("%d",&n);
	Max=0;Min=999;
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&A[i].r,&A[i].d,&A[i].w);
		s=A[i].w*1.0/(A[i].d-A[i].r);d=(int)s;
		
		if(d*1.0!=s)
			d++;
		printf("%lf.....%d\n",s,d);
		if(d>Max)
			Max=d;
		if(d<Min)
			Min=d;
	}
	//for(i=0;i<n;i++)
	//	printf("%d  %d  %d\n",A[i].r,A[i].d,A[i].w);
	printf("\n%d  %d\n",Max,Min);
	int k;
	for(i=Min;i<=Max;i++)
	{
		k=0;
		for(j=0;j<n;j++)
		{
			if(k==1)
				break;
			if((A[j].w*1.0/i)>(A[j].d-A[j].r))
			{printf("%d....\n",i);
			k=1;}
		}
		if(k==0)
		{
			printf("%d\n",i);
			break;
		}
	}
	}
	return 0;
}