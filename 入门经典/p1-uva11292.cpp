#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,m;
	int *dragon,*knight;
	//构造数组并输入数据 
	scanf("%d%d",&n,&m);
	while(n!=0&&m!=0)
	{
	dragon=(int *)malloc(sizeof(int)*n);
	knight=(int *)malloc(sizeof(int)*m);
	int i,j;
	for(i=0;i<n;i++)
		scanf("%d",&dragon[i]);
	for(j=0;j<m;j++)
		scanf("%d",&knight[j]);
		
	//排序 
	sort(dragon,dragon+n);
	sort(knight,knight+m);
	
	//开解
	int cost=0;
	i=0;
	for(j=0;j<m;j++) 
	{
		if(i>=n)
			break;
		if(knight[j]>=dragon[i])
		{
			cost+=knight[j];
			i++;
		}
	}
	if(i>=n)
		printf("%d\n",cost);
	else
		printf("Loowater is doomed!\n");
	scanf("%d%d",&n,&m);
	}
	return 0;
}
