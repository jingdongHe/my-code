#include <iostream> 
#include <string.h>
#include <string>
#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
#define MAXN 10002
int main() 
{ 
	int tian[MAXN],king[MAXN];
	int n;
	while(scanf("%d",&n),n!=0)
	{
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&tian[i]);
		}
		sort(tian,tian+n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&king[i]);
		}
		sort(king,king+n);
		int t=0,k=0;
		int tn=n-1,kn=n-1;
		int cost=0;
		while(t<=tn&&k<=kn)
		{
			if(tian[t]>king[k])
			{cost+=200;tian[t++]=0;king[k++]=0;}
			else if(tian[t]<king[k])
			{if(tian[t]<king[kn])cost-=200;tian[t++]=0;king[kn--]=0;}
			else if(tian[t]==king[k])
			{
				if(tian[tn]>king[kn])
				{cost+=200;tian[tn--]=0;king[kn--]=0;}
				else if(tian[tn]<king[kn])
				{if(tian[t]<king[kn])cost-=200;tian[t++]=0;king[kn--]=0;}
				else if(tian[tn]==king[kn])
				{if(tian[t]<king[kn])cost-=200;tian[t++]=0;king[kn--]=0;}
			}
		}
		printf("%d\n",cost);
	}
	return 0;
}