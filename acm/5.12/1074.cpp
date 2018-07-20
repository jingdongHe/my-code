#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef struct node {
	int c,d,number;
}node;
bool cmp(node a,node b)
{
	return a.d<b.d;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		node home[20];
		string name[20];
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			cin>>name[i];
			scanf("%d%d",&home[i].d,&home[i].c);
			home[i].number=i;
		}
		sort(home,home+n,cmp);
		int now=0,red=0;
		for(int i=0;i<n;i++)
		{
			now+=home[i].c;
			if(now>home[i].d)
				red+=now-home[i].d;
		}
		printf("%d\n",red);
		for(int i=0;i<n;i++)
			cout<<name[home[i].number]<<endl;
	}
	return 0;
}
