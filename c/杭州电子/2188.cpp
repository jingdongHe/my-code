#include<stdio.h>
int n,m;
int main()
{
	int c,i;
	scanf("%d",&c);
	for(i=0;i<c;i++)
	{
		scanf("%d%d",&n,&m);
		if(n%(m+1)==0)
			printf("Rabbit\n");
		else
			printf("Grass\n");
	}
	return 0;
}