#include<stdio.h>
int search(int i);
int main()
{
	int n;
	scanf("%d",&n);
	search(n);
	return 0;
}
int search(int n)
{
	int i=1,k,j,d,a[20],r;
	a[0]=1;
	while(i<n)
	{
		i++;
		for(r=2;r<n;r++)
		{
			a[i]=r;
		search(n);
		if(i==n-1)
		{
			for(j=0;j<n;j++)
			{
				k=a[j]+a[j+1];
				if(k==2||k==3||k==5||k==7||k==11||k==13||k==17||k==19||k==23||k==29||k==31||k==37)
					d++;
			}
			if(d==n)
			{
				for(j=0;j<n;j++)
					printf("%d",a[j]);
			}
		}
		}
	}
	return 0;
}
