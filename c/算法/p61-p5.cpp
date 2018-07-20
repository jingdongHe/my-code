#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n;
int min(int s[],int s1[])
{
	int i,j,d,k=0;
	int m=999;
	for(j=0;j<n;j++)
	{
		if(s1[j]==0)
			break;
	}
	s1[j]=1;
	for(i=0;i<n;i++)
	{
		if(s1[i]==1)
			continue;
		k=1;
		s1[i]=1;
		d=min(s,s1)+abs(s[j]-s[i]);
		s1[i]=0;
		if(m>d)
			m=d;
	}
	if(k==0)
		return 0;
	return m;
}
int main()
{
	int s[100],s1[100];
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&s[i]);
		s1[i]=0;
	}
	sort(s,s+n);
	printf("%d\n",min(s,s1));
	return 0;
}
