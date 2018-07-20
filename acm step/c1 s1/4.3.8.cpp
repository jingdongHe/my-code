#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> a[20000+5];
bool use[20000+5];
bool cmp(int a,int b)
{
	return a<b;
}
int dfs(int root)
{
	if(a[root][0]==0)
		return root;
	vector<int> temp;
	for(int i=1;i<=a[root][0];i++)
		temp.push_back(dfs(a[root][i]));
	sort(temp.begin(),temp.end(),cmp);
	/*printf("%d :\n",root);
	for(vector<int> ::iterator i=temp.begin();i!=temp.end();i++)
		printf("%d ",*i);
	printf("\n");*/
	return temp[(a[root][0]+1)/2-1];
}
int main()
{
	int t,root;
	while(scanf("%d",&t)!=EOF&&t!=0)
	{
		memset(use,false,sizeof(use));
		for(int i=1;i<=t;i++)
		{
			a[i].clear();
			int num;
			scanf("%d",&num);
			a[i].push_back(num);
			int temp;
			for(int j=0;j<num;j++)
			{
				scanf("%d",&temp);
				a[i].push_back(temp);
				use[temp]=true;
			}
		}
		for(int i=1;i<=t;i++)
		{
			if(use[i]==false)
			{root=i;break;}
		}
		/*for(int i=1;i<=t;i++)
		{
			printf("%d->%d:",i,a[i][0]);
			for(int j=1;j<=a[i][0];j++)
				printf("%d ",a[i][j]);
			printf("\n");
		}*/
		printf("%d\n",dfs(root));
	}
	return 0;
}
