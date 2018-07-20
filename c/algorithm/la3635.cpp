#include<stdio.h>
#include<math.h>
const double PAI=acos(-1);
int r[10000],n,f;
bool ok(double m)
{
	int i,ans=0;
	double s;
	for(i=0;i<n;i++)
	{
		s=PAI*r[i]*r[i];
		ans+=(int)(s/m);
	}
	if(ans>=f+1)
		return true;
	return false;
}
int main()
{
	int i,T;
	double L,R;
	scanf("%d",&T);
	while(T--)
	{
	scanf("%d%d",&n,&f);
	L=0;R=-1;
	for(i=0;i<n;i++)
	{
		scanf("%d",&r[i]);
		R=R>r[i]?R:r[i];
	}
	R=PAI*R*R;
	while(R-L>1e-5)
	{
		double m=(L+R)*1.0/2;
		//printf("%lf.\n",m);
		if(ok(m)) L=m;
		else R=m;
	}
	printf("%.4lf\n",L);
	}
	return 0;
}