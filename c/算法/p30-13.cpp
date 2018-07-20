#include<stdio.h>
#include<math.h>
const double Pi=acos(-1.0);
int N,F;//F+1个人分
bool ok(double k,int n[])
{
	int i,sum;
	double s;
	sum=0;
	for(i=0;i<N;i++)
	{
		s=Pi*n[i]*n[i];
		sum+=int(s/(k*1.0));
	}
	if(sum>=F+1)
		return true;
	return false;
}
int main()
{
	int n[10000];//n个派的半径
	int i,min=10001;
	double l,r,m;
	scanf("%d%d",&N,&F);
	for(i=0;i<N;i++)
	{
		scanf("%d",&n[i]);
		if(min>n[i])
			min=n[i];
	}//min为得出的半径的最小值,从而的出每个人可得的最大的派的面积
	l=0;r=Pi*min*min;m=(l+r)/2;
	while(r-l>1e-3)
	{
		if(ok(m,n))
			l=m;
		else
			r=m;
		m=(l+r)/2;
	}
	printf("%.3lf\n",m);
	return 0;
}


	