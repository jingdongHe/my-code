#include<stdio.h>
int main()
{
	int k=0,n;
	int a,b;
	int w=0,e=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		w+=a;e+=b;
		if(i!=0)
		{
			if(w>e) w--;
			else e--;
			k=w>e?w:e;
		}
	}
	printf("%d\n",k-1);
}
