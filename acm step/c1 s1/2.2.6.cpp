#include<stdio.h>
#include<string.h>
#define N 105

int k;
void set(int n,int table[])
{
	if(n%2==1)
	{
		if(table[3*n+1]==0)
			set(3*n+1,table);
		table[n]=table[3*n+1]+1;
		printf("%3d...%3d...%3d\n",n,table[n],table[3*n+1]);
	}
	else
	{
		if(table[n/2]==0)
			set(n/2,table);
		table[n]=table[n/2]+1;
		printf("%3d...%3d...%3d\n",n,table[n],table[n/2]);
	}
	int i=n;
	while(i<N)
	{
		table[i]=table[i/2]+1;//printf("%3d...%3d\n",i,table[i]);
		i*=2;
		
	}
	return;
}
int main()
{
	int table[N];
	memset(table,0,sizeof(table));
	table[1]=1;
	for(int i=2;i<N;i++)
	{
		if(table[i]==0)
			set(i,table);
	}
		
	for(int i=1;i<=20;i++)
		printf("%3d:%3d\n",i,table[1]);
	return 0;
}
