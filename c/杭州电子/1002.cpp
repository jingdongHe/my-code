#include<stdio.h>
#include<string.h>
int main()
{
	char a[1001],b[1001],c[1002];
	int n,sa,sb,d,i,k=0;
	scanf("%d",&n);
	while(n>20||n<0)
		scanf("%d",&n);
	getchar();
	while(n--)
	{
		scanf("%s",&a);scanf("%s",&b);
		k++;
		sa=strlen(a);sb=strlen(b);
		printf("Case %d:\n",k);printf("%s+%s =",a,b);
		for(i=0;i<sa;i++)
			a[i]-=48;
		for(i=0;i<sb;i++)
			b[i]-=48;
		d=sa>sb?sa:sb;
		for(i=0;i<d+1;i++)
			c[i]=0;
		for(i=d-1;i>=0;i--)
		{
			c[i+1]+=a[i]+b[i];
			if(c[i+1]>9)
			{
				c[i]=c[i+1]/10;
				c[i+1]%=10;
			}
		}
		
		if(c[0]==0)
			for(i=1;i<d+1;i++)
				printf("%d",c[i]);
		else
			for(i=0;i<d+1;i++)
				printf("%d",c[i]);
		printf("\n");
		if(n!=0)
			printf("\n");
		for(i=0;i<d+1;i++)
		{
			a[i]='\0';
			b[i]='\0';
			c[i]='\0';
		}
	}
    return 0;
}
