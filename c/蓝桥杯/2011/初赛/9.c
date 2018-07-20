#include<stdio.h>
int m,k=0,j;//mÖÖ·½°¸
int a[1000],b[1000][1000],c[1000]={0};
void search(int j, int n)
{
	int i;
      if(n == 1000) 
      {
          for(i=0; i<m;i++)
              b[k][i] = c[i];
          k++;
          return;
      }
      if(n >1000|| j >= m)
          return;
      n += a[j];
     ++c[j];
     search(j, n);
      n -= a[j];
      --c[j];
      search(j+1,n);
 }
void main()
{
	int i,j;
	printf("Please entry the number\n");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
	}
	search(0,0);
	printf("%d.....\n",k);
	for(i=0;i<k;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%5d",b[i][j]);
		}
		printf("\n");
	}
	return ;
}