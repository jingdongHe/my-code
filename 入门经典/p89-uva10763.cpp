#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=5000+5;
int main()
{
	int a[maxn],b[maxn];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d",&a[i],&b[i]);
	sort(a,a+n);
	sort(b,b+n);
	for(int i=0;i<n;i++)
	{
		if(a[i]!=b[i])
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}
