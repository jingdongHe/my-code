#include<stdio.h>
#include<algorithm>
using namespace std;
#define Max 100000
int i,n,r[Max];
int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}
int min(int a,int b)
{
	if(a<b)
		return a;
	return b;
}
int ok(int d)
{
	int left[Max],right[Max];
	int i;
	int x,y;
	x=r[0];y=d-r[0];//x,y分别代表礼物的两份，把礼物分成x，y两份之后，递推，若最后一人取得礼物里面没有左边的，则成立
	left[0]=r[0];right[0]=0;
	for(i=1;i<n;i++)
	{
		if(i%2==0)
		{
			right[i]=min(y-right[i-1],r[i]);
			left[i]=r[i]-right[i];
		}
		else
		{
			left[i]=min(x-left[i-1],r[i]);
			right[i]=r[i]-left[i];
		}
	}
	//for(i=0;i<n;i++)
	//	printf("%d.....%d\n",left[i],right[i]);
	return left[n-1]==0;
}
int main()
{

	int L=0,R=0,m;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&r[i]);
	r[n]=r[1];
	if(n%2==0)
	{
		for(i=0;i<n;i++)
		{
			if(r[i]+r[i+1]>L)
				L=r[i]+r[i+1];
		}
	}
	else
	{
		for(i=0;i<n;i++)
		{
			if(r[i]+r[i+1]>L)
				L=r[i]+r[i+1];
		}
		for(i=0;i<n;i++)
			R=max(R,r[i]*3);
	//	printf("%d.....%d\n",L,R);
		while(L<R)
		{
			m=(L+R)/2;//printf("%d....\n",m);
			if(ok(m))
				R=m;
			else
				L=m+1;
		}
	}
	printf("%d\n",L);
	/*for(i=0;i<15;i++)
	{
		if(ok(i))
			printf("%d Y\n",i);
		else
			printf("%d N\n",i);
	}*/
	return 0;
}
