#include<stdio.h>
int map[10][10],n;
int max(int i,int j)
{
	if(i>=n-1) return map[i][j];
	int a,b;
	a=max(i+1,j)+map[i][j];b=max(i+1,j+1)+map[i][j];
	if(a>b)
		return a;
	return b;
}
int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<i+1;j++)
			scanf("%d",&map[i][j]);
	}
	printf("%d\n",max(0,0));
	return 0;
}
