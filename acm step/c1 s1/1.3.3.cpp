#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct arrow {
	int a,b;
}arrow;
bool cmp(arrow a,arrow b)
{
	return a.a<b.a;
}
void print(int k)
{
	k-=2;
	printf(">+");
	for(int i=0;i<k;i++)
		printf("-");
	printf("+>\n");
	return;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		arrow ar[55];
		for(int i=0;i<n;i++)
			scanf("%d%d",&ar[i].a,&ar[i].b);
		sort(ar,ar+n,cmp);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<ar[i].b;j++)
				print(ar[i].a);
			printf("\n");
		}
	}
	return 0;
}
