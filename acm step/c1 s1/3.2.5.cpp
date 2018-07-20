#include<stdio.h>
const int maxn=6000;
int min(int a,int b)
{
	if(a>b)
		return b;
	return a;
}
int main()
{
	int a[maxn];
	a[1]=1;
	int c1=1,c2=1,c3=1,c4=1;
	int i=2;
	while(i<=5842)
	{
		int b1=a[c1]*2;
		int b2=a[c2]*3;
		int b3=a[c3]*5;
		int b4=a[c4]*7;
		int k=min(min(min(b1,b2),b3),b4);
		if(k==b1)
			c1++;
		else if (k==b2)
			c2++;
		else if(k==b3)
			c3++;
		else if(k==b4)
			c4++;
		if(a[i-1]!=k)
			a[i++]=k;
	}
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		if(n%100==11||n%100==12||n%100==13)
			printf("The %dth humble number is %d.\n",n,a[n]);
		else if(n%10==1)
			printf("The %dst humble number is %d.\n",n,a[n]);
		else if(n%10==2)
			printf("The %dnd humble number is %d.\n",n,a[n]);
		else if(n%10==3)
			printf("The %drd humble number is %d.\n",n,a[n]);
		else 
			printf("The %dth humble number is %d.\n",n,a[n]);
	}
		
	return 0;
}
