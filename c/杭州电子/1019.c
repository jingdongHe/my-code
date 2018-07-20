#include<stdio.h>
int cgcd(int lcm,int a);
int cgcd(int lcm,int a)//求lcm与a之间的最大公约数
{
	int r,n,m;
	n=lcm;m=a;
	if(lcm<a)
	{r=lcm;lcm=a;a=r;}
	if(a==0)
		return lcm;
	if(lcm==0)
		return a;
	r=lcm%a;
	while(r!=0)
	{
		lcm=a;
		a=r;
		r=lcm%a;
	}
	lcm=n/a*m;
	return lcm;
}
int main()
{
	int m,lcm,a[1000],n,i;
	while(scanf("%d",&n)!=EOF)
	{
		while(n--){
		scanf("%d",&m);
		//printf("%d...........\n",m);
		for(i=0;i<m;i++)
			scanf("%d",&a[i]);
		lcm=a[0];
		for(i=1;i<m;i++)
			lcm=cgcd(lcm,a[i]);
		printf("%d\n",lcm);
		for(i=0;i<m;i++)
			a[i]='\0';}
	}
	return 0;
}
