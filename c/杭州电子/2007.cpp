#include<stdio.h>
int main()
{
    int a,b,i,k;
    long c=0,d=0;//c2,d3
    while(scanf("%d%d",&a,&b)!=EOF){
		if(a>b)
		{
			k=a;a=b;b=k;
		}
    for(i=a;i<=b;i++){
    if(i%2==0)
    c+=i*i;
    else
    d+=i*i*i;}
    printf("%ld %ld\n",c,d);c=0;d=0;}
    return 0;
}
