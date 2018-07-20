#include<stdio.h>
int main()
{
    int year,month,day,d;
    while(scanf("%d/%d/%d",&year,&month,&day)!=EOF){
    switch(month)
    {case 1:d=0;break;
    case 2:d=31;break;
    case 3:d=59;break;
    case 4:d=90;break;
    case 5:d=120;break;
    case 6:d=151;break;
    case 7:d=181;break;
    case 8:d=212;break;
    case 9:d=243;break;
    case 10:d=273;break;
    case 11:d=304;break;
    case 12:d=334;break;}
    if((year%4==0&&year%100!=0&&month>2)||(year%400==0&&month>2))
    d++;
    d+=day;
    printf("%d\n",d);}
    return 0;
}
    
    
