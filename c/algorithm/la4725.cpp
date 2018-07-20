#include<stdio.h>
#include<string.h>
const int maxn=5000+10;
int air[maxn][2],air2[maxn][2],n;
bool ok(int num)
{
	num++;
	int l,r,i;
	memcpy(air2,air,sizeof(air));
	for(i=0;i<n;i++)
	{
		l=air2[i][0]+air2[i+1][0];
		r=air2[i][0]+air2[i+1][0];
		if(l>num||r>num)
			return false;
		if(l<r) air2[i+1][1]=r-1;
		else air2[i+1][0]=l-1;
	}
	return true;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int i,Max=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&air[i][0],&air[i][1]);
			Max+=air[i][0]+air[i][1];
		}
		int left=0,right=Max-1,mid;
		//printf("<%d,%d>\n",left,right);
		int ans=9999999;
		while(left<=right)
		{
			mid=left+(right-left)/2;
			//printf("%d<%d,%d>\n",mid,left,right);
			if(ok(mid))
			{
				right=mid-1;
				if(mid<ans) ans=mid;
			}
			else
				left=mid+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}