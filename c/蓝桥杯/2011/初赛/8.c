#include<stdio.h>
void main()
{
	int q[20][20]={0};
	int n;//n为输入的数
	int a,b,c,d;//a上边，b下边，c左边，d右边
	int i,r,k;
	scanf("%d",&n);
	a=0;b=n;c=0;d=n;k=1;
	while(a<b&&c<d)
	{
		for(i=c;i<d;i++)
		{
			q[a][i]=k;
			k=k+1;
		}
		a++;d--;
		if(a>=b||c>=d)
			break;
		r=d;
		for(i=a;i<b;i++)
		{
			if(r-1<c)
				break;
			q[i][--r]=k++;
			//printf("%d   %d........\n",i,r);
		}
		b--;d--;
		if(a>=b||c>=d)
			break;
		printf("%d.....\n",b);
		for(i=b-c-1;i>=a;i--)
		{
			q[i][r]=k;
			k=k+1;
		}
		c++;
		if(a>=b||c>=d)
			break;
		//printf("%d  %d  %d  %d  %d...........\n",a,b,c,d,k);
	}
	for(i=0;i<n;i++)
	{
		for(r=0;r<n;r++)
		{
			if(q[i][r]!=0)
				printf("%4d",q[i][r]);
		}
		printf("\n");
	}
	return ;
}

