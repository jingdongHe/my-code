#include<stdio.h>
int x[3],use[3]={0};
int hamliton(adj,k,x);
int hamliton(adj,k,x)
{
	for(x[k]=1;x[k]<=3;x[k]++)
	{
		if(x[k])
		{
			use[x[k]]=1;
			if(hamliton(adj,k+1;x))
int main()
{
	int k;
	int adj[3][3]={ {0,1,1},
					{1,0,1},
					{1,1,0}};
	
	int i;
	hamliton(adj,2,x);
	return 0;
}