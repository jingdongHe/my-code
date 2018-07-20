#include<stdio.h>
#include<string.h>
const int Max=5;
int d[Max][Max][2][2];
int f(int i,int j,int k,int p)
{
	int ans=0;
	if(d[i][j][k][p]!=-1)
		return d[i][j][k][p];
	if(i<0||j<0)
		return 0;
	if(i-j>5)
		return 0;
	if(p==0)
		ans=f(i-1,j,k,0)+f(i-1,j,k,1);
	else
		ans=f(i,j-1,k,0);
	printf("%d %d %d %d :%d\n",i,j,k,p,d[i][j][k][p]);
	return d[i][j][k][p]=ans;
}
int main()
{
	int L;
	int i,j,k,p;
	
	int ans[Max];
	memset(d,-1,sizeof(d));
	memset(ans,0,sizeof(ans));
	d[1][0][0][0]=d[0][1][1][1]=1;
	//d[0][0][0][0]=d[0][0][0][1]=1;
	for(p=0;p<2;p++)
	{
		for(k=0;k<2;k++)
		{
			for(i=2;i<Max;i++)
			{
				for(j=0;j<=i;j++)
				{
					if(i-j>5)
						continue;
					k=f(i,j,k,p);
				}
			}
		}
	}
	/*for(i=4;i<Max;i++)
	{
		if(i%2==1) continue;
		int r=(i+4)/2,l=(i-4)/2;
		ans[i]=d[r][l][0][0]+d[r][l][0][1]+d[r][l][1][0];
		printf("%d:  %d\n",i,ans[i]);
	}
	while(scanf("%d",&L))
	{
		printf("%d\n",ans[L]);
	}*/
	return 0;
}
		