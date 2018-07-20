#include<stdio.h>
int main()
{
    int a;
    while(scanf("%d",&a)!=EOF){
    if(a>=90&&a<=100)
    printf("A\n");
    if(a<90&&a>=80)
    printf("B\n");
    if(a<80&&a>=70)
    printf("C\n");
    if(a<70&&a>=60)
    printf("D\n");
    if(a>=0&&a<60)
    printf("E\n");
    if(a<0||a>100)
    printf("Score is error!\n");}
    return 0;
}
