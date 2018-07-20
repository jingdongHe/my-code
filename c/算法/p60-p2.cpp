#include<stdio.h>
typedef struct rec {
	int x,y;
}rec;
rec r[100];
int n;
int link(int d)
{
	int i,k=0;
	int max=0;
	for(i=0;i<n;i++)
	{
		if((r[i].x<r[d].x&&r[i].y<r[d].y)||(r[i].x<r[d].y&&r[i].y<r[d].x))
		{
			k=1;
			if(max<link(i))
				max=link(i);
		}
	}
	if(k==0)
		return 1;
	return max+1;
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d",&r[i].x,&r[i].y);
	for(i=0;i<n;i++)
		printf("%d\n",link(i));
	return 0;
}
