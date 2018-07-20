#include<stdio.h>
#include<math.h>
int zhuan(int a[],int i,int t)
{
	if(i==0)
		return 0;
	if(a[i]==t)
		return zhuan(a,i-1,t);
	return zhuan(a,i-1,6-a[i]-t)+pow(2,i-1);
}
int main()
{
	int i,n;
	int a[60],b[60];
	int ans;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	for(i=n;i>=0;i--)
	{
		if(a[i]!=b[i])
			break;
	}
	ans=zhuan(a,i-1,6-a[i]-b[i])+zhuan(b,i-1,6-a[i]-b[i])+1;
	printf("%d\n",ans);
	return 0;
}