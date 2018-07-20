#include<stdio.h>
int main()
{
	int n,i,k,d=0,j;
	char a[50];
	scanf("%d",&n);
	getchar();
	for(j=0;j<n;j++)
	{
	    gets(a);
	    k=strlen(a);
        for(i=0;i<k;i++)
			{
			if(a[i]&0x80)
				d++;
			}
		d=d/2;
		printf("%d",d);
		if(j!=n-1)
			printf("\n");
		d=0;
	}
	return 0;
}
