#include<stdio.h>
int k=0,a[10]={0};
int dati(int x,int k);
int dati(int x,int k)
{
	int i;
	//printf("%d   ",k);
	if(k==10&&x==100)
	{
		for(i=1;i<=10;i++)
		{
			printf("%d  ",a[i]);
			a[i]=0;
		}
		printf("\n");
	}
	if(k<10)
	{
		for(i=0;i<2;i++)
		{
			if(i==0)
			{
				
				a[k]=i;
				//printf("%d,,,,\n",x);
				dati(x-k,k+1);
			}
			else
			{
				
				a[k]=i;
				//printf("%d....\n",x);
				dati(x*2,1+k);
			}
		}

	}

	return 0;

}
int main()
{
	int x=10;//x为选手分数
	dati(x,k);
	k=1;
	return 0;
}
