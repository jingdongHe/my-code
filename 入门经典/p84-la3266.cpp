#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=1000+5;
int main()
{
	int n;
	int tian[maxn],king[maxn];
	while(scanf("%d",&n)==1&&n)
	{
	for(int i=0;i<n;i++)
		scanf("%d",&tian[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&king[i]);
	sort(tian,tian+n);
	sort(king,king+n);
	int tb=0,te=n-1,kb=0,ke=n-1;
	int k=0;
	while(tb<=te&&kb<=ke)
	{
		if(king[kb]>tian[tb])
		{if(king[ke]>tian[tb])k--;tb++;ke--;}
		else if(king[kb]<tian[tb])
		{k++;tb++;kb++;}
		else if(king[kb]==tian[tb])
		{
			if(tian[te]>king[ke])
			{k++;te--;ke--;}
			else
			{if(tian[tb]<king[ke])k--;tb++;ke--;}
		}
	}
	printf("%d\n",k*200);
	}
	return 0;
}
