#include<stdio.h>
int main()
{
	int A,B,C;
	int i,j,k;
	int map[20][20][20];
	int s[20][20][20]={0};
	int S,a,b,c,sx=0;
	scanf("%d%d%d",&A,&B,&C);
	for(i=0;i<A;i++)
	{
		for(j=0;j<B;j++)
		{
			for(k=0;k<C;k++)
			{
				s[i][j][k]=0;
				scanf("%d",&map[i][j][k]);
			}
		}
	}
	for(i=0;i<A;i++)
	{
		for(j=0;j<B;j++)
		{
			for(k=0;k<C;k++)
			{
				s[i][j][k]+=map[i][j][k];
				//二维
				if(j>0)
				{
					s[i][j][k]+=s[i][j-1][k];
					if(i>0)
						s[i][j][k]-=s[i-1][j-1][k];
				}
				if(k>0)
				{
					s[i][j][k]+=s[i][j][k-1];
					if(i>0)
						s[i][j][k]-=s[i-1][j][k-1];
				}
				if(j>0&&k>0)
				{
					s[i][j][k]-=s[i][j-1][k-1];
					if(i>0)
						s[i][j][k]+=s[i-1][j-1][k-1];
				}
				if(i>0)
					s[i][j][k]+=s[i-1][j][k];
			}
		}
	}
	for(i=0;i<A;i++)
	{
		for(j=0;j<B;j++)
		{
			for(k=0;k<C;k++)
			{
				//确定i,j,k的起始位置
				for(a=0;a<A;a++)
				{
					if(a<i) continue;
					for(b=0;b<B;b++)
					{
						if(b<j) continue;
						for(c=0;c<C;c++)
							//确认末尾位置
						{
							S=0;
							if(c<k)continue;
							//printf("%d  %d  %d  %d  %d  %d  %d\n",i,j,k,a,b,c,s[a][b][c]);
							S+=s[a][b][c];//printf("%d\n",S);
							if(k>0)
								S-=s[a][b][k-1];
							if(j>0)
								S-=s[a][j-1][c];
							if(i>0)
								S-=s[i-1][b][c];
							if(i>0&&j>0&&k>0)
							{S+=s[i-1][j-1][k-1];S+=s[a][j-1][k-1];if(S>sx) sx=S;continue;}
							if(j>0&&k>0)
							{S+=s[a][j-1][k-1];if(S>sx) sx=S;continue;}
							if(S>sx) sx=S;
							//printf("%d\n",S);
						}
					}
				}
			}
		}
	}
	printf("%d\n",sx);
	return 0;
}
