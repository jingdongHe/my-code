#include<stdio.h>
int main()
{
	int T,n;
	char array[100+2][100+2];
	scanf("%d",&T);getchar();
	for(int t=0;t<T;t++)
	{
		scanf("%d",&n);getchar();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%c",&array[i][j]);
			}
			getchar();
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(array[i][j]=='.')
				{
					for(char c='A';c<='Z';c++)
					{
						if(j>0&&array[i][j-1]==c)
							continue;
						else if(i>0&&array[i-1][j]==c)
							continue;
						else if(i<n-1&&array[i+1][j]==c)
							continue;
						else if(j<n-1&&array[i][j+1]==c)
							continue;
						else 
						{array[i][j]=c;break;}
					}
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				printf("%c",array[i][j]);
			printf("\n");
		}
	}
	return 0;
}
