#include<stdio.h>
#define N 10
int main()
{
	char map[N][N],ch;
	int j,i,n,k;
	scanf("%d",&n);getchar();
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%c",&map[i][j]);
		}
		getchar();
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(map[i][j]=='.')
			{
				
				for(ch='A';ch<='Z';ch++)
				{
					k=1;
					if(i>0&&ch==map[i-1][j]) k=0;
					if(i<n-1&&map[i+1][j]==ch) k=0;
					if(j>0&&map[i][j-1]==ch) k=0;
					if(j<n-1&&map[i][j+1]==ch) k=0;
					if(k==1){map[i][j]=ch;break;}
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
	return 0;
}