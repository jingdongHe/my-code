#include<stdio.h>
//因式分解，不解释
 void main()
{
	 int n,i;
	 printf("Please entry the number\n");
	 scanf("%d",&n);
     for(i=2; i<=n/2; i++)
     {
		if(n%i==0)
        {
           printf("%d ", i);
           n = n / i;
        }
     }
     if(n>1) 
		 printf("%d\n", n);
}
