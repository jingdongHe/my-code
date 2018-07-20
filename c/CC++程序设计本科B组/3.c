#include<stdio.h>
int k=0;
void louti(int i,int d)
{
	if(d==39)
	{
		if(i%2==0)
			k++;
		return;
	}
	if(d>39)
		return;
	else
	{
	louti(i+1,d+1);
	louti(i+1,d+2);
	}
	return;
}
int main()
{
	louti(0,0);
	printf("%d\n",k);
	return 0;
}