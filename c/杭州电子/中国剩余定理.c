#include<stdio.h>

int GCD(int a,int b)
{
	int t;
	if(a<b)//此题默认b<a
	{t=a;a=b;b=t;}
	if(a%b==0)
		return b;
	else
		return GCD(b,a%b);
}
int LCM(int a,int b)
{
	return a*b/GCD(a,b);
}
int LCM1(int a,int b,int c)
{
	int k,s;
	k=LCM(a,b);
	s=LCM(k,c);
	return s;
}
int NB(int a,int b,int c,int c1)
{
	int i=0;
	int k;
	k=LCM(a,b);
	while(++i)
	{
		if((k*i)%c==c1)
			return k*i;
	}
	return 0;
}
void main()
{
	int a,b,c;
	int x,y,z;
	int a1,b1,c1;
	int r,s;
	printf("输入三个数\n");
	scanf("%d%d%d",&a,&b,&c);
	printf("输入该数与三个数相除的余数\n");
	scanf("%d%d%d",&a1,&b1,&c1);
	//printf("%d %d %d \n%d %d %d\n==================\n",a,b,c,a1,b1,c1);
	x=NB(b,c,a,a1);y=NB(a,c,b,b1);z=NB(a,b,c,c1);
	//printf("%d..%d..%d\n%d\n",x,y,z,x+y+z);
	r=LCM1(a,b,c);s=x+y+z;
	while(s>0)
		s-=r;
	s+=r;
	printf("%d\n",s);
}