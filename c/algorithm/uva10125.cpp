#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1000+10;
bool find(int s[],int data,int front,int end)
{
	while(front<=end)
	{
		int mid=(front+end)/2;
		if(s[mid]<data)
			front=mid+1;
		if(s[mid]>data)
			end=mid-1;
		if(s[mid]==data)
			return true;
	}
	return false;
}
int main()
{
	int s[maxn];
	vector<int> v;
	int i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&s[i]);
	}
	sort(s,s+n);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			v.push_back(s[i]+s[j]);
		}
	}
	/*while(1)
	{
		int d;
		scanf("%d",&d);
		if(find(s,d,0,n))
		{
			printf("%d\n",d);
		}
		else
		printf("no\n");
	}*/
	/*for(i=0;i<n;i++)
		printf("%d ",s[i]);
	printf("\n");
	for(i=0;i<v.size();i++)
		printf("%d ",v[i]);
	printf("\n");*/
	int k=-1;
	for(i=n-1;i>=0;i--)
	{
		for(j=0;j<v.size();j++)
		{
			//printf("%d   %d",i,j);
			int d=s[i]-v[j];
			if(find(s,d,0,n))
			{
				k=i;break;
			}
		}
		if(k!=-1)
			break;
	}
	if(k!=-1)
		printf("%d\n",s[k]);
	else
		printf("no solution\n");
	/*while(!v.empty())
	{
		int d=v.back();
		printf("%d ",d);
		v.pop_back();
	}
	for(i=0;i<n;i++){
		printf("%d",s[i]);
	}*/
	return 0;
}
