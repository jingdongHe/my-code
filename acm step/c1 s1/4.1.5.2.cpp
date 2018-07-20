#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
 struct point
{
    double x,y;
};
int p,q,r,v;
double dis(point a,point b)
{
    return pow(pow(a.y-b.y,2)+pow(a.x-b.x,2),1.0/2);
}
double findy(point c,point d,point y)
{
    point mid,midmid,left,right;
    double t1,t2;
    left = c;
    right = d;
    do
    {
        mid.x = (left.x+right.x)/2;
        mid.y = (left.y+right.y)/2;
        midmid.x = (right.x+mid.x)/2;
        midmid.y = (right.y+mid.y)/2;
        t1 = dis(d,mid)/q+dis(mid,y)/r;
        t2 = dis(d,midmid)/q+dis(midmid,y)/r;
        if(t1>t2)
        left = mid;
        else right = midmid;
    }while(fabs(t1-t2)>0.000001);
    return t1;
}
double find(point a,point b,point c,point d)
{
    point mid,midmid,left,right;
    double t1,t2;
    left = a;
    right = b;
    do
    {
        mid.x = (left.x+right.x)/2;
        mid.y = (left.y+right.y)/2;
        midmid.x = (right.x+mid.x)/2;
        midmid.y = (right.y+mid.y)/2;
        t1 = dis(a,mid)/p+findy(c,d,mid);
        t2 = dis(a,midmid)/p+findy(c,d,midmid);
        if(t1>t2)left = mid;
        else right = midmid;
    }while(fabs(t1-t2)>0.000001);
    return t1;
}
int main()
{
    int t;
    point a,b,c,d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf %lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&d.x,&d.y);
        scanf("%d%d%d",&p,&q,&r);
        printf("%.2f\n",find(a,b,c,d));
    }
    return 0;
}
