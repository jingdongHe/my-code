#include<stdio.h>
int search(int n);
int isprime(int r);
int main ()
{
	int i;
	scanf("%d",&i);
	search(i);
	return 0;
}
int isprime(int k)
{
	if(k==2||k==3||k==5||k==7||k==11||k==13||k==17||k==19||k==23||k==29||k==31||k==37)
		return 1;
	else
		return 0;
}
int search(int n)
{
	int i=1,j,k,a[20],d;
	a[0]=1;
	while(i++<n)
	{
		for(j=i+1;j<n;j++)
		{
			a[i]=j;
			search(n);
			if(i==n)
			{
				for(k=0;k<n;k++)
				{
					if(isprime(a[k]+a[k-1]))
						d++;
					if(isprime(a[0]+a[n-1]))
						d++;
				}
				if(d==n)
				{
					for(k=0;k<n;k++)
						printf("%d",a[k]);
				}
			}
		}
	}
	return 1;
}

