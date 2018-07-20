#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
	int i,n;
	_int64 money[10000000];
	while(scanf("%d",&n)!=EOF)
	{
		_int64 tot=0;
		_int64 c[1000000];
		for(i=0;i<n;i++)
		{scanf("%I64d",&money[i]);tot+=money[i];}
		_int64 m=tot/n;
		c[0]=0;
		for(i=1;i<n;i++)
			c[i]=c[i-1]+money[i]-m;
		sort(c,c+n);
		_int64 data=c[n/2],ans=0;
		for(i=0;i<n;i++)
			ans+=abs(data-c[i]);
		printf("%I64d\n",ans);
	}
	return 0;
}
