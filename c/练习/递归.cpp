#include<stdio.h>
long factor(int n)
{
     long f;
     if(n<0) printf("n<0,input error");
     else if(n==0||n==1) f=1;
     else f=factor(n-1)*n;
     return(f);
     }
     main()
     {
           int n;
           long y;
           printf("\niput a inteager number:\n");
           scanf("%d",&n);
           y=factor(n);
           printf("%d!=%ld",n,y);
           return 0;
           }
