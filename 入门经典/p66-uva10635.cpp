#include<stdio.h>
int main()
{
	int n,p,q;
	int A[250*250+5]={0},B[250*250+5]={0};
	scanf("%d%d%d",&n,&p,&q);
	int number;
	for(int i=1;i<=p+1;i++)
	{
		scanf("%d",&number);
		A[number]=i;
	}
	int k=0;
	for(int i=1;i<=q+1;i++)
	{
		scanf("%d",&number);
		if(A[number]!=0)
			B[k++]=A[number];
	}
	/*for(int i=0;i<k;i++)
		printf("%d ",B[i]);
	printf("\n");*/
	int temp[250*250+5];
	for(int i=0;i<k;i++)
		temp[i]=99999;
	int ans=0;
	for(int i=0;i<k;i++)
	{
		int j=0;
		while(temp[j]<B[i])
			{j++;}
		temp[j]=B[i];
		ans=ans>j?ans:j;
	}
	printf("%d",ans+1);
}
