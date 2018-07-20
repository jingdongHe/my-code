#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=100+5;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int aftroon[maxn],night[maxn];
	int n,d,r;
	scanf("%d%d%d",&n,&d,&r);
	for(int i=0;i<n;i++)
		scanf("%d",&aftroon[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&night[maxn]);
	sort(aftroon,aftroon+n);
	sort(night,night+n,cmp);
	int k=0;
	for(int i=0;i<n;i++)
	{
		if(aftroon[i]+night[i]>d)
			k+=aftroon[i]+night[i]-d;
	}
	printf("%d\n",r*k);
	return 0;
}
