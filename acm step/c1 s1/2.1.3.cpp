#include<stdio.h>
int gcd(int a,int b)
{
	if(a<b)
	{int temp=a;a=b;b=temp;}
	if(a%b==0) return b;
	return gcd(b,a%b);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,c,d,temp;
		char ch;
		scanf("%d%c%d",&a,&ch,&b);getchar();
		scanf("%d%c%d",&c,&ch,&d);getchar();
		
		temp=gcd(a,b);
		a/=temp;b/=temp;
		temp=gcd(c,d);
		c/=temp;d/=temp;
		
		int x=gcd(b,d);
		int y=b*d/x;
		a=a*d/x;c=c*b/x;
		b=d=y;

		x=a*(c/gcd(a,c));
		y=b;
		

		int f=gcd(x,y);
		x=x/f;y=y/f;
		//printf("%d  %d  %d  %d\n",a,b,c,d);
		printf("%d",x);
		if(y!=1) printf("/%d\n",y);
	}
	return 0;
}
