#include<stdio.h>
int n;
int min(int d,int a[],int map[][100])
{
	int i;
	int m,k=0,Min=999;
	for(i=0;i<n;i++)
	{
		if(a[i]==1)
			continue;
		k=1;
		a[i]=1;
		m=min(i,a,map)+map[d][i];
		//printf("%d  %d\n",m,map[d][i]);
		a[i]=0;
		if(m<Min)
			Min=m;
	}
	if(k==0)
		return map[0][d];
	return Min;
}
int main()
{
	int i,j;
	int map[100][100];
	int a[]={0};
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		map[i][i]=0;
		for(j=i+1;j<n;j++)
		{
			scanf("%d",&map[i][j]);
			map[j][i]=map[i][j];
		}
	}
	/*for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",map[i][j]);
		printf("\n");
	}*/
	printf("%d\n",min(0,a,map));
	return 0;
}