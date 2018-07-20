#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
	int i,n;
	int A[10000],c[10000];
	int tot,ave;
	int x;
	while(scanf("%d",&n)!=EOF)
	{
		tot=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&A[i]);
			tot+=A[i];
		}
		ave=tot/n;
		c[0]=0;
		for(i=1;i<n;i++)
			c[i]=c[i-1]+A[i]-ave;
		sort(c,c+n);
		x=c[n/2];
		tot=0;
		for(i=0;i<n;i++)
			tot+=abs(x-c[i]);
		printf("%d\n",tot);
	}
	return 0;
}