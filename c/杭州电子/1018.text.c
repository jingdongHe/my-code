
#include <iostream>
#include<math.h>
using namespace std;

#define M_PI 3.141592657
#define M_E 2.71828182845904523536028747135266250

int main(void)
{
    int num;
    cin>>num;
    int n;
    double sum;
    for(int i=0; i<num; i++)
    {
        cin>>n;
        sum=log10(sqrt(2*M_PI*n))+n*log10(n/M_E);
        cout<<(int)sum+1<<endl;
    }
    return 0;
}