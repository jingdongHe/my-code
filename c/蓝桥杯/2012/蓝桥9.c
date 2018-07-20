#include<stdio.h>//¼×=0ÒÒ=1±û=2¶¡=3
#include<stdlib.h>
double c[4][4]={
{1,0.1,0.3,0.5},
{0.9,1,0.7,0.4},
{0.7,0.3,1,0.2},
{0.5,0.6,0.8,1}};
double lose(int a,int b);//a lose bµÄ¸ÅÂÊ
double lose(int a,int b)
{
	double n;
	n=1-c[a][b];
	return n;
}
int main()
{
	int b;
	long i;
	double d,n=0;
	for(i=0;i<100000;i++)
	{
		//b=2+(int)(2*rand()/(RAND_MAX+1));
		b=rand()%3+1;
		//printf("%d  ",b);
		switch(b)
		{
		case 1:d=1-(lose(0,1)+lose(1,0)*(lose(2,3)*lose(0,3)+lose(3,2)*lose(0,2)));break;
		case 2:d=1-(lose(0,2)+lose(2,0)*(lose(1,3)*lose(0,3)+lose(3,1)*lose(0,1)));break;
		case 3:d=1-(lose(0,3)+lose(3,0)*(lose(1,2)*lose(0,2)+lose(2,1)*lose(0,1)));break;
		}
		n+=d;
	}
	n/=i-1;
	printf("%lf\n",n);
	return 0;
}


