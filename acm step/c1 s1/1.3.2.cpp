#include<stdio.h>
#include<algorithm>
using namespace std;
bool big(int a,int b)
{
	return a>b;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		int tian[1010],king[1010];
		for(int i=0;i<n;i++)
			scanf("%d",&tian[i]);
		for(int i=0;i<n;i++)
			scanf("%d",&king[i]);
		sort(tian,tian+n,big);
		sort(king,king+n,big);
		int k=0;
		int tf=0,ts=n-1,kf=0,ks=n-1;
		while(tf<=ts)
		{
			if(tian[ts]>king[ks])
			{k++;ts--;ks--;}
			else if(tian[ts]<king[ks])
			{k--;ts--;kf++;}
			else if(tian[ts]==king[ks])
			{
				if(tian[tf]>king[kf])
				{k++;tf++;kf++;}
				else if(tian[tf]<king[kf])
				{k--;kf++;ts--;}
				else if(tian[tf]==king[kf])
				{
					if(tian[ts]<king[kf])
						k--;
					ts--;kf++;
				}
			}
		}
		printf("%d\n",k*200);
	}
	return 0;
}
