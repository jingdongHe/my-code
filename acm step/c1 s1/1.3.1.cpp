#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef struct node {
	int s,e;
}node;
bool cmp(node a,node b)
{
	if(a.e==b.e)
		return a.s<b.s;
	return a.e<b.e;
}
int main()
{
	
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
	int t=0;node time[110];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&time[t].s);
		scanf("%d",&time[t].e);
		t++;
	}
	sort(time,time+t,cmp);
	int temp=time[0].e,k=1;
	for(int i=1;i<t;i++)
	{
		if(time[i].s>=temp)
		{
			k++;
			temp=time[i].e;
		}
	}
	printf("%d\n",k);
	}
	return 0;
}
