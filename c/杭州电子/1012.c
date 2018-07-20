#include<stdio.h>
int main()
{
	double e=0;
	long n;
	int i,j,k;
	printf("n e\n- -----------\n");
	for(k=0;k<10;k++)
	{
		e=0;
		for(i=0;i<=k;i++)
		{
			n=1;
			if(i==0)
				n=1;
			else{
			for(j=1;j<=i;j++)
				n*=j;}
			//printf("%ld.........\n",n);
			e+=1.0/n;
		}
		if(i<=2)
			printf("%d %.0lf\n",i-1,e);
		if(i==3)
			printf("%d %.1lf\n",i-1,e);
		if(i>3)
			printf("%d %.9lf\n",i-1,e);
	}
	return 0;
}
