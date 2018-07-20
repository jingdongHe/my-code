#include<stdio.h>
void main()
{
		int n,m,m1;
        int a=1,b=1;
		scanf("%d%d",&n,&m);
        m1=m;
		while(m1>1)
			a *= m1--;
        while(n>1)
                b *= n--;
        printf("%ld\n",a/b);
}
