#include<stdio.h>
int main()
{
    int a,c;
    for(;scanf("%1d",&a),a>0;printf("%d\n",--a%9u+1))
        while((c=getchar())-48u<10)
            a+=c-48;
    return 0;
}