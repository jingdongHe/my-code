#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,m;
	int i,j;
	int cost;
	int a[2000],b[2000];//a¡˙£¨b∆Ô ø
	scanf("%d%d",&n,&m);
	while(n!=0&&m!=0)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<m;i++)
			scanf("%d",&b[i]);
		sort(a,a+n);
		sort(b,b+m);
		/*for(i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
		for(i=0;i<m;i++)
			printf("%d ",b[i]);
		printf("\n");*/
		cost=0;j=0;
		for(i=0;i<m;i++)
		{
			if(b[i]>=a[j])
			{
				cost+=b[i];
				j++;
			}
			if(j==n)
				break;
		}
		if(j==n)
			printf("%d\n",cost);
		else
			printf("loowater is doomed!\n");
		scanf("%d%d",&n,&m);

	}
	return 0;
}
		