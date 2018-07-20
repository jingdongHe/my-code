#include<stdio.h>
int main()
{
	int n,r,m=0;
	char b[1000];
	while(scanf("%d%d",&n,&r)!=EOF)
	{
		if(n<0)
		{
			n=-n;
			printf("-");
		}
		while(n%r)
		{
		    b[m]=n%r;
			if(b[m]==10)  b[m]='A';
			if(b[m]==11)  b[m]='B';
			if(b[m]==12)  b[m]='C';
			if(b[m]==13)  b[m]='D';
			if(b[m]==14)  b[m]='E';
			if(b[m]==15)  b[m]='F';
			n=n/r;
			m++;
		}
		for(;m>0;m--)
		{
			if(b[m-1]>=0&&b[m-1]<=9)
			    printf("%d",b[m-1]);
			else
				printf("%c",b[m-1]);
            b[m]='\0';
		}
		printf("\n");
	}
	return 0;
}