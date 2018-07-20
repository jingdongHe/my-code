#include<stdio.h>
int main()
{
	int n,ah,am,as,bh,bm,bs,h=0,m=0,s=0,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d%d%d",&ah,&am,&as,&bh,&bm,&bs);
		s=as+bs;
		if(s>=60)
		{
			m++;
			s-=60;
			if(s>=60)
				continue;
		}
		m+=am;m+=bm;
		if(m>=60)
		{
			m-=60;
			h++;
			if(m>=60)
				continue;
		}
		h+=ah;h+=bh;
		printf("%d %d %d\n",h,m,s);
		h=0;m=0;s=0;
		/*if(i!=n-1)
			printf("\n");*/
	}
	return 0;
}

