#include <iostream>  
#include <cmath>  
#include <algorithm>  
#include <cstring>  
using namespace std;  
double t1,t2,s1,s2,w;  
double area(double b) // 求y=x+b下方在矩形中截取的面积  
{  
    double s=(t2-t1)*(s2-s1);  
    double x1=t1,y1=t1+b;  
    double x2=t2,y2=t2+b;  
    if(y2<=s1) // 直线交于矩形右下顶点或者以下  
        return 0;  
    if(y1<=s1) // 直线交于矩形下面边  
    {  
        if(y2<=s2) // 直线交于矩形右面边  
            return 0.5*(y2-s1)*(t2-(s1-b));  
        else  // 直线交于矩形上面边  
            return 0.5*(t2-s1+b+t2-s2+b)*(s2-s1);  
    }  
    else if(y1<s2) // 直线交于矩形左面边  
    {  
        if(y2<=s2) //直线交于矩形右面边  
            return 0.5*(t1+b-s1+t2+b-s1)*(t2-t1);  
        else // 直线交于矩形上面边  
            return s-0.5*(s2-t1-b)*(s2-t1-b);  
    }  
    else  
        return s;  
}  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    for(int cas=1;cas<=t;cas++)  
    {  
        scanf("%lf%lf%lf%lf%lf",&t1,&t2,&s1,&s2,&w);  
        double ans=area(w)-area(-w);  
        ans/=(s2-s1)*(t2-t1);  
        printf("Case #%d: %.8lf\n",cas,ans);  
    }  
    return 0;  
}  