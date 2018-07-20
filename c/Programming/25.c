#include<stdio.h>
int map[20][20];
int n;
void b_t()
{
	int i,r,j;
	int a[50]={0};
	printf("请输入n\n");
	scanf("%d",&n);getchar();
	a[1]=1;map[1][0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=i-1;j>=1;j--)
		{
			if(i%j==0)
			{
				r=0;
				//printf("%d....%d\n",i,j);
				while(map[a[j]+1][r]!='\0')
					r++;
				map[a[j]+1][r]=i;
				a[i]=a[j]+1;
				break;
			}
		}
	}
}			
void number()
{
	int a[50]={'\0'};
	int i,j,k=1;
	int x,y,z;
	for(i=1;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			if(map[i][j]!='\0')
			{
				a[map[i][j]]=k;
				k++;
			}
			else
				break;
		}
	}
	printf("输入3个不大于n的正整数\n");
	scanf("%d%d%d",&x,&y,&z);getchar();
	/*for(k=1;k<n;k++)
	{
		printf("%d ",a[k]);
	}*/
	printf("\n%d,%d,%d\n",a[x],a[y],a[z]);
}
void main()
{
	//int i,j;
	b_t();
/*	for(i=1;i<=20;i++)
	{
		for(j=0;j<20;j++)
		{
			if(map[i][j]!='\0')
				printf("%3d ",map[i][j]);
			else
				break;
		}
		printf("\n");
	}*/
	number();
}
