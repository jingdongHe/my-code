#include<stdio.h>
void cheng(int a[],int k)//º∆À„k*k
{
	int b[6],d=5,i,j;
	for(i=0;i<13;i++)
		a[i]=0;
	printf("%d\n",k);
	while(k!=0)
	{
		b[d--]=k%10;
		k=k/10;
	}
	d=6;
	for(i=d-1;i>=0;i--)
	{
		for(j=d-1;j>=0;j--)
		{
			a[j+i+1]+=b[j]*b[i];
			if(a[j+i+1]>=10)
			{
				a[j+i]+=a[j+i+1]/10;
				a[j+i+1]=a[j+i+1]%10;
			}
		}
	}
}
int main()
{
	int q[13];
	int i;
	cheng(q,111111);
	for(i=0;i<12;i++)
		printf("%d",q[i]);
	cheng(q,999999);
	for(i=0;i<12;i++)
		printf("%d",q[i]);
	return 0;
}