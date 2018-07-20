#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(b-c==a)
			printf("does not matter\n");
		else if(b-c>a)
			printf("advertise\n");
		else
			printf("do not advertise\n");
	}
	return 0;
}
