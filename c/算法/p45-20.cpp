#include<stdio.h>
#include<algorithm>
using namespace std;
#define Max 10000
typedef struct node {
	double data;
	int type;
}node;
void change(int x,int a,double &l,double &r,int w)
{
	if(a>0)
	{
		if(x>0&&x<w)
		{l=0;r=(w-x)/(a*1.0);}
		if(x<=0)
		{l=(0-x)/(a*1.0);r=w/(a*1.0);}
		if(x>=w)
		{l=-1.0;r=0;}
	}
	if(a<0)
	{
		if(x>0&&x<w)
		{l=0;r=x/(a*1.0);}
		if(x<=0)
		{l=-1.0;r=0;}
		if(x>=w)
		{l=(x-w)/(a*1.0);r=w/(a*1.0);}
	}
	if(a==0)
	{l=-1.0;r=9999;}
}
bool com(node x,node y)
{
	if(x.data==y.data)
		return x.type>y.type;
	return x.data<y.data;
}
int main()
{
	int i,n,k=0;
	int w,h;
	int x,y,a,b;
	node A[Max*2];
	scanf("%d%d",&w,&h);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&x,&y,&a,&b);
		double l1,l2,l,r1,r2,r;
		change(x,a,l1,r1,w);
		change(y,b,l2,r2,h);
		//printf("%lf....%lf....%lf....%lf\n",l1,r1,l2,r2);
		l=l1>l2?l1:l2;
		A[k].data=l;A[k++].type=0;
		r=r1<r2?r1:r2;
		A[k].data=r;A[k++].type=1;
	}
	sort(A,A+k,com);
	/*for(i=0;i<k;i++)
		printf("%lf  %d\n",A[i].data,A[i].type);*/
	int con=0,ans=0;
	for(i=0;i<k;i++)
	{
		if(A[i].type==1)
			ans--;
		if(ans>con) con=ans;
		if(A[i].type==0)
			ans++;
		if(ans>con) con=ans;
	}
	printf("%d\n",con);
	return 0;
}
