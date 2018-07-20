#include<stdio.h>
int change_10(int k)
{
	int s=0;
	while(k)
	{
		s+=k%10;
		k/=10;
	}
	return s;
}
int change_12(int k)
{
	int s=0;
	while(k)
	{
		s+=k%12;
		k/=12;
	}
	return s;
}
int change_16(int k)
{
	int s=0;
	while(k)
	{
		s+=k%16;
		k/=16;
	}
	return s;
}
int main()
{
	for(int i=2992;i<10000;i++)
	{
		if(change_10(i)==change_12(i)&&change_12(i)==change_16(i))
			printf("%d\n",i);
	}
	return 0;
}
