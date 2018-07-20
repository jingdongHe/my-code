#include<stdio.h>
#include <memory.h> 
int a[1000005];
int main()
{
	int m,n,r,s,i;
	int t;
	scanf("%d%d",&m,&n);
	
		//if(n>m)
		//	break;
		for(i=0;i<m;i++)
			scanf("%d",&a[i]);
		for(r=0;r<n+1;r++)
		{
			for(s=r+1;s<m;s++)
			{
				if(a[r]<a[s])
				{t=a[r];a[r]=a[s];a[s]=t;}
			}
		}

		for(i=0;i<n-1;i++)
			printf("%d ",a[i]);
		printf("%d\n",a[i]);
		//memset (a,0,m*sizeof(a[0]));
	
	return 0;
}
