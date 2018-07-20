#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=100000+10;
const int inf=99999;
int T,w,h;
typedef struct node {
	int x,y;
	int a,b;
	double L,R;
}node;
typedef struct event{
	double loc;
	int type;
}event;
bool cmp(event a,event b)
{
	if(a.loc==b.loc)
		return a.type<b.type;
	return a.loc<b.loc;
}
void findx(double &t1,double &t2,node k)
{
	if(k.x<0)
	{
		if(k.a>0)
		{
			t1=(-1*k.x)/k.a;
			t2=(w-k.x)/k.a;
		}
		else 
			t1=t2=-1;//-1不能进，999出不来
	}
	else if(k.x>w)
	{
		if(k.a<0)
		{
			t1=(k.x-w)/(k.a*-1);
			t2=k.x/(k.a*-1);
		}
		else
			t1=t2=-1;
	}
	else if(k.x==0)
	{
		t1=0;
		if(k.a>0)
			t2=w/k.a;
		else if(k.a<0)
			t2=-1;
		else
			t2=inf;
	}
	else if(k.x==w)
	{
		if(k.a<0)
			t2=w/k.a*-1;
		else if(k.a>0)
			t2=-1;
		else
			t2=inf;
	}
	else
	{
		t1=0;
		if(k.a>0)
			t2=(w-k.x)/k.a;
		else if(k.a<0)
			t2=(-1*k.x)/k.a;
		else
			t2=inf;
	}
}
void findy(double &t1,double &t2,node k)
{
	if(k.y<0)
	{
		if(k.b>0)
		{
			t1=(-1*k.y)/k.b;
			t2=(h-k.y)/k.b;
			
		}
		else 
			t1=t2=-1;//-1不能进，999出不来
	}
	else if(k.y>h)
	{
		if(k.b<0)
		{
			t1=(k.y-h)/(k.b*-1);
			t2=k.y/k.b*-1;
		}
		else
			t1=t2=-1;
	}
	else if(k.y==0)
	{
		t1=0;
		if(k.b>0)
			t2=h/k.b;
		else if(k.b<0)
			t2=-1;
		else
			t2=inf;
	}
	else if(k.y==h)
	{
		if(k.b<0)
			t2=h/k.b*-1;
		else if(k.b>0)
			t2=-1;
		else
			t2=inf;
	}
	else
	{
		t1=0;
		if(k.b>0)
			t2=(h-k.y)/k.b;
		else if(k.b<0)
			t2=(-1*k.y)/k.b;
		else
			t2=inf;
	}
}
void find(node &k)
{
	double t3,t4,t1,t2;//t1为入时间，t2为出时间
	findx(t1,t2,k);
	findy(t3,t4,k);
	//printf("%lf  %lf  %lf  %lf  \n",t1,t2,t3,t4);
	k.L=t1>t3?t1:t3;
	k.R=t2<t4?t2:t4;
}
int main()
{
	int t,n,i,k;
	node star[maxn];
	event s[maxn*2];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&w,&h,&n);k=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d%d",&star[i].x,&star[i].y,&star[i].a,&star[i].b);find(star[i]);
		//	printf("%d:\n",i);
			if(star[i].L<star[i].R)
			{
				//printf("%d...%lf...%lf\n",i,star[i].L,star[i].R);
				s[k].loc=star[i].L;s[k++].type=1;
				s[k].loc=star[i].R;s[k++].type=-1;
			}
		}
		sort(s,s+k,cmp);
		int ans=0,d=0;
		for(i=0;i<k;i++)
		{
			//printf("%lf....%d\n",s[i].loc,s[i].type);
			if(s[i].loc>=0)
			{
				d+=s[i].type;
				ans=ans>d?ans:d;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}