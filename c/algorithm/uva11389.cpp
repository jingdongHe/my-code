#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=100+5;
int main()
{
	int n,d,r;
	int day[maxn],night[maxn];
	while(scanf("%d%d%d",&n,&d,&r)&&n&&d&&r)
	{
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&day[i]);
	for(i=0;i<n;i++)
		scanf("%d",&night[i]);
	sort(day,day+n);
	sort(night,night+n);
	int sum=0;
	for(i=0;i<n;i++)
	{
		int k=day[i]+night[n-1-i]-d;
		k=k>0?k:0;
		sum+=k;
	}
	printf("%d\n",sum*r);
	}
	return 0;
}