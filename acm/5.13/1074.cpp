#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;
const int maxn=1<<16;
typedef struct node {
	int cost,pre,reduce;
}node;
typedef struct course {
	int dead,cost;
	int number;
}course;
void print(int k,node dp[],string name[])
{
	if(k<=0) return;
	
	int temp=k^dp[k].pre;//printf("%d.......%d\n",k,temp);
	int who=0;
	while(temp!=1)
	{
		who++;
		temp=temp>>1;
		//if(temp|1==1) break;
	}
	print(dp[k].pre,dp,name);
	cout<<name[who]<<endl;
	
	return;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		course homework[20];
		node dp[maxn];
		bool vis[maxn];
		string name[20];
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			cin>>name[i];
			scanf("%d%d",&homework[i].dead,&homework[i].cost);
			homework[i].number=i;
		}
		int upper=1<<n;
		
		/*for(int i=0;i<n;i++)
			printf("%d  %d\n",homework[i].dead,homework[i].cost);
		for(int i=0;i<upper;i++)
			printf("%d:%d %d\n",i,dp[i].cost,dp[i].reduce);
		printf("====================\n");*/
		for(int i=0;i<upper;i++)
			dp[i].cost=dp[i].reduce=0;
		dp[0].reduce=dp[0].cost=0;
		dp[0].pre=-1;
		/*for(int i=0;i<upper;i++)
			printf("%d:%d %d\n",i,dp[i].cost,dp[i].reduce);
		printf("--------------------\n");*/
		memset(vis,false,sizeof(vis));
		
		for(int i=0;i<upper;i++)
		{
			for(int j=0;j<n;j++)
			{
				int cur=1<<j;
				if((i&cur)==0)
				{
					int temp=i|cur;
					int cost=homework[j].cost+dp[i].cost;
					int reduce=cost-homework[j].dead;
					reduce=reduce>0?reduce:0;
					reduce+=dp[i].reduce;
					if(vis[temp])
					{
						if(reduce<dp[temp].reduce)
						{
							dp[temp].reduce=reduce;
							dp[temp].cost=cost;
							dp[temp].pre=i;
						}
					}
					else
					{
						dp[temp].reduce=reduce;
						dp[temp].cost=cost;
						dp[temp].pre=i;
						vis[temp]=1;
					}
					//printf("%d  %d  %d\n",temp,dp[temp].cost,dp[temp].reduce);
				}
			}
		}
		printf("%d\n",dp[upper-1].reduce);
		/*for(int i=0;i<upper;i++)
			printf("%d........%d\n",i,dp[i].pre);*/
		print(upper-1,dp,name);
	}
	return 0;
}
