#include<stdio.h>
#define n 9
int main()
{
	int a[n]={1,2,3,4,5,6,7,8,9};
	int i,val,j;//j为i的前一个数
	for(i=1;i<n;i++)
	{
		j=i-1;
		val=a[i];
		while(j>=0&&val>=a[j])
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=val;
	}
	for(i=0;i<n;i++)
		printf("%d",a[i]);
	printf("\n");
	return 0;
}
