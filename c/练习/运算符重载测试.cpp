#include<iostream>
#include<stdio.h>
using namespace std;
struct point {
	int x,y;
};
point operator + (point a,point b)
{
	point c;
	c.x=a.x+b.x;
	c.y=a.y+b.y;
	return c;
}
int main()
{
	point a,b,c;
	scanf("%d%d%d%d",&a.x,&a.y,&b.x,&b.y);
	c=a+b;
	printf("%d  %d\n",c.x,c.y);
	int x,y;
	scanf("%d%d",&x,&y);
	printf("%d\n",x+y);
	return 0;
}