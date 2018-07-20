#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
const int maxn=500000+10;
bool cmp(int a,int b)
{
	return abs(a)<abs(b);
}
int main()
{
	int seq[maxn];
	int n,i,p;
	scanf("%d",&p);
	while(p--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&seq[i]);
		sort(seq,seq+n,cmp);
		int k=0,d=1;
		for(i=0;i<n;i++)
		{
			if(k==0)
			{
				if(seq[i]>0)
					k=1;
				else
					k=-1;
				continue;
			}
			if(k>0&&seq[i]<0)
			{d++;k=-1;continue;}
			if(k<0&&seq[i]>0)
			{d++;k=1;continue;}
		}
		printf("%d\n",d);
	}
	return 0;
}
