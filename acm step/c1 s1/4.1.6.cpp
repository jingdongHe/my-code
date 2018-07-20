#include<stdio.h>
const int maxn=10000+5;
bool is_ok(double arr[],double length,int n,int k)
{
	int s=0;
	for(int i=0;i<n;i++)
		s+=arr[i]/length;
	if(s>=k) return true;
	else return false;
}
int main()
{
	int n,k;
	double arr[maxn];
	while(scanf("%d%d",&n,&k)!=EOF&&n!=0&&k!=0)
	{
		double s=0;
		for(int i=0;i<n;i++)
		{scanf("%lf",&arr[i]);if(s<arr[i])s=arr[i];}
		double min=0,max=s;
		double mid;
		while(max-min>1e-4)
		{
			mid=(max+min)/2.0;
			//printf("%lf:%d\n",mid,is_ok(arr,mid,n,k));
			if(is_ok(arr,mid,n,k))
				min=mid;
			else max=mid;
		}
		printf("%.2lf\n",min);
	}
	return 0;
}
