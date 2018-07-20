#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct node {
	long x,y;
}node;
long n,w,v;
bool can(int vh,node loc[])
{
	int i;
	double left,right,left1,right1;
	double s,t;
	for(i=n-1;i>0;i--)
	{
		t=(loc[i].y-loc[i-1].y)*1.0/vh;
		s=t*v;
		if(i==n-1)
		{
			left=loc[i].x-s;
			right=loc[i].x+s+w;
		}
		else
		{
			left=left>left1?left:left1;
			right=right<right1?right:right1;
			left-=s;right+=s;
		}
		left1=loc[i-1].x;
		right1=loc[i-1].x+w;
		if(left>right1||right<left1)
			return false;
	}
	return true;
}
int main()
{
	int i,k;
	long J;
	node loc[100000];
	int vec[1000000];
	while(scanf("%ld%ld%ld",&w,&v,&n))
	{
		k=0;
	for(i=0;i<n;i++)
		scanf("%ld%ld",&loc[i].x,&loc[i].y);
	scanf("%ld",&J);
	for(i=0;i<J;i++)
		scanf("%d",&vec[i]);
	sort(vec,vec+J);
	for(i=J-1;i>=0;i--)
	{
		if(can(vec[i],loc))
		{
			k=1;
			break;
		}
	}
	if(k==0)
		printf("IMPOSSIBLE\n");
	else
		printf("%ld\n",vec[i]);
	}
	return 0;
}

