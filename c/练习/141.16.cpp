#include<stdio.h>
int main()
{
	int i,j,k,d=0;

	for(j=2;j>=0;j--)
	{
		for(k=j;k>=0;k--)
		{printf(" ");}
		for(i=0;i<5-2*j;i++)
		{printf("*");}
		for(k=j;k>=0;k--)
		{printf(" ");}
		printf("\n");
		if(j==0)
		{for(d=1;d<=2;d++)
			{for(k=d;k>=0;k--)
			{printf(" ");}
			for(i=0;i<5-2*d;i++)
			{printf("*");}
			for(k=d;k>=0;k--)
			{printf(" ");}
			printf("\n");}
		}
}
	return 0;
}
