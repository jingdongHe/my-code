#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=20000;
bool cmp(int a,int b)
{
	return a<b;
}
int main()
{
	int m,n;
	int i,j;
	int a[maxn],b[maxn];
	while(scanf("%d%d",&n,&m)!=EOF&&m&&n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<m;i++)
			scanf("%d",&b[i]);
		sort(a,a+n,cmp);
		sort(b,b+m,cmp);
		i=j=0;
		int money=0;
		for(i=0;i<n;i++)
		{
			while(b[j]<a[i]) j++;
			if(j>=m) break;
			money+=b[j];
			j++;
		}
		if(i!=n)
			printf("Loowater is doomed!\n");
		else
			printf("%d\n",money);
	}
	return 0;
}