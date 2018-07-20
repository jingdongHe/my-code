#include<stdio.h>
int p[1000];
int find(int x)
{
	return p[x]!=x?find(p[x]):x;
}
int main()
{
	
	int i,x,y;
	for(i=0;i<1000;i++)
		p[i]=i;
	int refusals=0;
	while(scanf("%d%d",&x,&y)&&x!=-1)
	{
		x=find(x);y=find(y);
		if(x==y)
			refusals++;
		else
			p[x]=y;
	}
	printf("%d\n",refusals);
	return 0;
}