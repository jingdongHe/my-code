#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct node {
	double time;
	int station;
}node;
const double INF=99999.0;
const int maxn=1000+5;
bool cmp(node a,node b)
{
	if(a.time==b.time)
		return a.station<b.station;//出为-1，入为1 
	return a.time<b.time;
}
void updata(int a,int x,int h,double &in,double &out)
{
	if(a==0)
	{
		if(x<=0||x>=h)
			in=out=INF;
		else
		{in=0;out=INF;}
	}
	else if(a>0)
	{
		if(x>=h)
		{in=out=INF;}
		else if(x>=0)
		{
			in=0;out=(h-x)*1.0/a;
		}
		else
		{
			in=x*-1.0/a;
			out=(h-x)*1.0/a;
		}
	}
	else
	{
		if(x<=0)
		{in=out=INF;}
		else if(x<=h)
		{
			in=0;out=x*-1.0/a;
		}
		else
		{
			in=(x-h)*-1.0/a;
			out=x*-1.0/a;
		}
	}
	return ;
}
int main()
{
	int w,h,n,k=0;
	node star[maxn*2];
	scanf("%d%d",&w,&h);
	scanf("%d",&n);
	int x,y,a,b;
	double in1,in2,out1,out2,in,out;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&x,&y,&a,&b);
		updata(a,x,w,in1,out1);
		updata(b,y,h,in2,out2);
		in=in1>in2?in1:in2;
		out=out1<out2?out1:out2;
		star[k].time=in;
		star[k++].station=1;
		star[k].time=out;
		star[k++].station=-1;
	}sort(star,star+k,cmp);
	/*for(int i=0;i<k;i++)
	{
		printf("%lf    %d\n",star[i].time,star[i].station);
	}
	
	printf("--------------------------------------\n");
	for(int i=0;i<k;i++)
	{
		printf("%lf    %d\n",star[i].time,star[i].station);
	}*/
	int ans=0,cnt=0;
	for(int i=0;i<k;i++)
	{
		cnt+=star[i].station;
		ans=ans>cnt?ans:cnt;
	}
	printf("%d\n",ans);
	return 0;
}
