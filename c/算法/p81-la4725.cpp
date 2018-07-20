#include<stdio.h>
int main()
{
	int n,i,ans,a,b,t,l,r;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		l=r=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			l+=a;r+=b;
			if(i!=0)
			{
				if(l>r)
					l--;
				else
					r--;
			}
		}
		ans=l>r?l:r;
		printf("%d\n",ans-1);
	}
	return 0;
}