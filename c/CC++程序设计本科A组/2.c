#include<stdio.h>
void cheng(int a[],int k)//º∆À„k*k
{
	int b[6],d=5,i,j;
	for(i=0;i<13;i++)
		a[i]=0;
	while(k!=0)
	{
		b[d--]=k%10;
		k=k/10;
	}
	d=6;
	for(i=d-1;i>=0;i--)
	{
		for(j=d-1;j>=0;j--)
		{
			a[j+i+1]+=b[j]*b[i];
			if(a[j+i+1]>=10)
			{
				a[j+i]+=a[j+i+1]/10;
				a[j+i+1]=a[j+i+1]%10;
			}
		}
	}
}
int panduan(int q[],int g[])
{
	int i;
	i=q[0]==0?1:0;
	for(;i<12;i++)
	{
		if(g[q[i]]==1)
			return 0;
	}
	return 1;
}
int main()
{
	int g[10]={0};
	int q[13];
	int a,b,c,d,e,f,k;
	for(a=1;a<=9;a++)
	{
		g[a]=1;
		for(b=0;b<=9;b++)
		{
			if(b==a)
				continue;
			g[b]=1;
			for(c=0;c<=9;c++)
			{
				if(c==b||c==a)
					continue;
				g[c]=1;
				for(d=0;d<=9;d++)
				{
					if(d==c||d==b||d==a)
						continue;
					g[d]=1;
					for(e=0;e<=9;e++)
					{
						if(e==d||e==c||e==b||e==a)
							continue;
						g[e]=1;
						for(f=0;f<=9;f++)
						{
							if(f==e||f==d||f==c||f==b||f==a)
								continue;
							g[f]=1;
							k=a*100000+b*10000+c*1000+d*100+e*10+f;
							cheng(q,k);
							if(panduan(q,g))
							{
								printf("%d\n",k);
							}
							g[f]=0;
						}
						g[e]=0;
					}
					g[d]=0;
				}
				g[c]=0;
			}
			g[b]=0;
		}
		g[a]=0;
	}
	return 0;
}