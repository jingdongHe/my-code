#include<stdio.h>
int main()
{
	int n,a[100],x,i,sum,r,s,t,y,z,j;
	scanf("%d",&n);
	while(n!=0)
	{sum=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		r=a[i]/100;
	s=(a[i]%100)/50;
	t=((a[i]%100)%50)/10;
	x=(((a[i]%100)%50)%10)/5;
	y=((((a[i]%100)%50)%10)%5)/2;
	z=(((((a[i]%100)%50)%10)%5)%2)/1;
	j=r+s+t+x+y+z;sum+=j;
	}
	printf("%d\n",sum);
	
	for(i=0;i<n;i++)
		a[i]='\0';
	scanf("%d",&n);}
	return 0;
}
