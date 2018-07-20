#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main(void)
{
        double s=0,l=0,r=PI/2,m=PI/4,L=0,rate=0;
		double ret;
        int a,b;
        scanf("%d:%d",&a,&b);
        if(b==0 || a==0)
            rate=0;
        else
            rate=(double)a/b;
        if(rate>1)
                rate=1/rate;
        ret=rate*PI/(rate+1);
        s=m-sin(m)*cos(m);
        while(abs(s-ret)>0.0001&&(r-l>0.0001))
        {
                if(s<ret)
                {
                        l=m;
                        m=(l+r)/2;
                }
                else if(s>ret)
                {
                        r=m;
                        m=(l+r)/2;
                }
                s=m-sin(m)*cos(m);
        }
        L=2*sin(m);
        printf("%lf\n",L);
        return 0;
}