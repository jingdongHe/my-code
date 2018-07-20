#include<stdio.h>
#include<string.h>
int main()
{
	int t,m,n;//m数量，n长度
	int i,j,k,max,maxn=0,h;
	char link[50][100];
	char result[100];
	int series[4];
	scanf("%d",&t);getchar();
	for(i=0;i<t;i++)
	{
		scanf("%d%d",&m,&n);getchar();
		h=0;memset(result,'\0',sizeof(result));
		for(j=0;j<m;j++)
		{
			for(k=0;k<n;k++)
				scanf("%c",&link[j][k]);
			getchar();
		}
		/*for(j=0;j<m;j++)
		{
			for(k=0;k<n;k++)
				printf("%c",link[j][k]);
			printf("\n");
		}*/
		for(j=0;j<n;j++)
		{
			memset(series,0,sizeof(series));max=0;
			for(k=0;k<m;k++)
			{
				if(link[k][j]=='A')
					series[0]++;
				if(link[k][j]=='C')
					series[1]++;
				if(link[k][j]=='G')
					series[2]++;
				if(link[k][j]=='T')
					series[3]++;
			}
			for(k=0;k<4;k++)
			{
				if(series[k]>max)
				{
					max=series[k];
					maxn=k;
				}
				//printf("%d ",series[k]);
			}
		//	printf("\n");
			h+=(m-max);//printf("%d:%d   %d   %d\n",j,max,maxn,h);
			
			if(maxn==0)
				result[j]='A';
			if(maxn==1)
				result[j]='C';
			if(maxn==2)
				result[j]='G';
			if(maxn==3)
				result[j]='T';
		}
		for(j=0;j<n;j++)
			printf("%c",result[j]);
		printf("\n%d\n",h);
	}
	return 0;
}

				