#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
void pai1()
{
	double x,y;
	int n=0,i;
	srand((unsigned)time(0));
	for(i=0;i<5000;i++)
	{
		x=(rand()*1.0)/(RAND_MAX*1.0);
		y=(rand()*1.0)/(RAND_MAX*1.0);
		if(sqrt(x*x+y*y)<=1)
			n++;
	}
	x=(n*4*1.0)/5000;
	printf("PAI约等于%lf\n",x);
}
void pai2()
{
	double r,s,a;
	int i;
	r=1.0;
	i=6;
	while(1)
	{
		//printf("%.19lf.......%d\n",r,i);
		s=i*r;
		if(i>1536)
			break;
		a=1.0-sqrt(1-(r/2)*(r/2));
		r=sqrt(a*a+(r/2)*(r/2));
		i*=2;
	}
	printf("%.16lf\n",s/2);
}
/*3）采用级数：
π/2 = 1 + 1/3 + (1*2)/(3*5) +(1*2*3)/(3*5*7) + …… +(1*2*…n)/(3*5*…(2n+1)) =
1+1/3*(1+2/5*(1+……+(n-1)/(2n-1)*(1+n/(2n+1)......)。
说明解法（3）最有利于高精度计算，例如你用这一解法编写的的程序应该能够求出圆周率π精确到小数点后100位，
求出 圆周率π = 3. 1415926535 8979323846 2643383279 5028841971 6939937510 5820974944  
5923078164 0628620899 8628034825 3421170677。*/
void pai3()
{
	double z2=2.0,z1=0,k=2.0,a=1.0,b=3.0;//z1为z2的前一个结果
	int d=0;
	int q[101]={0};
	while(q[100]==0)
	{
		k*=((a*1.0)/b);
		z2+=k*pow(10,d);
		//printf("%.14lf\n",z2);
		if((int)((z1-z2)*10)==0)
		{
			q[d++]=(int)z2;
			z2=(z2-(int)z2)*10;
		}
		a++;b+=2;
		z1=z2;
	}
	//printf("%.14lf",z2);
	printf("%d.",q[0]);
	for(d=1;d<100;d++)
		printf("%d",q[d]);
	/*double x=2.0,z=2.0;
	int a=1,b=3;
	while(z>1e-15)
	{
		z=z*((a*1.0)/b);
		x+=z;
		a++;
		b+=2;
	}
	printf("%.15lf",x);*/
}
void main()
{
	pai3();
	return;
}