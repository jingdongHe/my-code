#include<stdio.h>
#include<math.h>
int main()
{
    int m,n,i,d=0,k,a[20];
    while(scanf("%d%d",&m,&n)!=EOF){
		if(m>n)
		{
			k=m;m=n;n=k;
		}
    for(i=m;i<=n;i++)
    {if(i==pow(i/100,3)+pow((i%100)/10,3)+pow(i%10,3))
    {a[d]=i;d++;}}
	for(i=0;i<d;i++)
	{
		printf("%d",a[i]);
		if(i!=d-1)
			printf(" ");
	}
    if(d==0)printf("no\n");else printf("\n");d=0;
	}
    return 0;
}
