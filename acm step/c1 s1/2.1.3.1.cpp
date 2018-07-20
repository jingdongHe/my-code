#include<iostream>
#include<stdio.h>
using namespace std;

int gcd(int a,int b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}

int main()
{
   int t1,r1,t2,r2,t;
    int T;
    cin>>T;
    while(T--)
    {
        cin>>t1;
        getchar();
        cin>>r1;
		int G1=gcd(t1,r1);
        t1=t1/G1;
        r1=r1/G1;
        cin>>t2;
        getchar();
        cin>>r2;
		int G2=gcd(t2,r2);
        t2=t2/G2;
        r2=r2/G2;
        
        
        t=t1/gcd(t1,t2)*t2;
        r1=t/t1*r1;
        r2=t/t2*r2;
        int gcdr=gcd(r1,r2);
        if(t%gcdr==0)
            cout<<t/gcdr<<endl;
        else
            cout<<t/gcd(t,gcdr)<<"/"<<gcdr/gcd(t,gcdr)<<endl;
    }
    return 0;
}
