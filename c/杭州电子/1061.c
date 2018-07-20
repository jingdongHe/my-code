#include<stdio.h>
int main()
{
	int n,i,j,k,m,r=1;//k为输入个数
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		scanf("%d",&m);
		n=m;
		for(j=0;j<m;j++)
		{
			r*=n;
			if(r>=10)
				r=r%10;
		}
		printf("%d\n",r);
		r=1;
	}
	return 0;
}