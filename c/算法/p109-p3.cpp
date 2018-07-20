#include<stdio.h>
#define N 40
int main()
{
	int use[10];
	use[0]=use[6]=use[9]=6;
	use[1]=2;
	use[2]=use[3]=use[5]=5;
	use[4]=4;use[7]=3;use[8]=7;
	int d[100]={0},s[100]={0};
	int i,j;
	d[0]=1;
	for(i=0;i<N;i++)
	{
		for(j=0;j<10;j++)
		{
			if(!(i==0&&j==0)&&i+use[j]<N)
				d[i+use[j]]+=d[i];
		}
	}
	for(i=1;i<N;i++)
		s[i]=s[i-1]+d[i];
	for(i=1;i<N;i++)
	{
		if(N>=6)
			printf("%d:%d\n",i,s[i]+1);
		else
			printf("%d:%d\n",i,s[i]);
	return 0;
}
