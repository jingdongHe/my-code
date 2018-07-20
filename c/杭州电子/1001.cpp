#include<stdio.h>
int main()
{    
     long n;
     while(scanf("%ld",&n)!=EOF)
        printf("%ld\n\n", n%2? (n+1)/2*n: n/2*(n+1));
     return 0;    
}
