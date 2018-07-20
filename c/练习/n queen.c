#include<stdio.h>
#define n 8
int row_used[n],ru[2*n+1],ld[2*n+1],row[n],r=0;
void cleara(int row[])
{
	int i;
	for(i=0;i<=n;i++)
		row[i]=0;
}
void clearb(int ru[])
{
	int i;
	for(i=0;i<=2*n+1;i++)
		ru[i]=0;
}
void queen(int k)
{
	for(row[k]=1;row[k]<=n;row[k]++)//row表示k在第row【k】行，k列已写入,row_used将第row【k】行标记，
	{
		if(row_used[row[k]]==0&&ru[n-k+row[k]]==0&&ld[k+row[k]-1]==0)//如果行，上斜线，下斜线没有被占用
		{
			row_used[row[k]]=1;ru[n-k+row[k]]=1;ld[k+row[k]-1]=1;
			if(k==n)
			{
				int i;
				for(i=1;i<=n;i++)
					printf("%d ",row[i]);
				printf("\n");
				r++;
			}
			else
				queen(k+1);
			row_used[row[k]]=0;ru[n-k+row[k]]=0;ld[k+row[k]-1]=0;
		}
	}
}
int main()
{
	//int i;
	cleara(row_used);
	clearb(ru);
	clearb(ld);
	/*for(i=0;i<n;i++)
		printf("%d",row[i]);
	printf("\n");
	for(i=0;i<2*n+1;i++)
		printf("%d",ru[i]);
	printf("\n");
	for(i=0;i<2*n+1;i++)
		printf("%d",ld[i]);
	printf("\n");*/
	queen(1);
	printf("%d\n",r);
	return 0;
}
