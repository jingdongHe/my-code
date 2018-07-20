#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct node {
	int loc,id;
	char dir;
}node;
bool cmp(node a,node b)
{
	return a.loc<b.loc;
}
bool cmp1(node a,node b)
{
	return a.id<b.id;
}
int main()
{
	int r,s;
	int L,T,n;
	scanf("%d",&s);getchar();
	for(r=1;r<=s;r++)
	{
		node a[10000],b[10000];
		scanf("%d%d%d",&L,&T,&n);getchar();
		int i,j;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i].loc);getchar();a[i].dir=getchar();
			getchar();
			a[i].id=i+1;
			int d=a[i].dir=='L'?-1:1;
			b[i].loc=a[i].loc+d*T;
			b[i].dir=a[i].dir;
		}
		/*for(i=0;i<n;i++)
			printf("%d..%c  ",a[i].loc,a[i].dir);
		printf("\n");
		for(i=0;i<n;i++)
			printf("%d..%c  ",b[i].loc,b[i].dir);
		printf("\n");*/
		sort(a,a+n,cmp);
		sort(b,b+n,cmp);
		printf("Case #%d:\n",r);
		for(i=0;i<n;i++)
		{
			b[i].id=a[i].id;
			j=i;
			if(i>0&&b[j].loc==b[j-1].loc&&b[j].dir!='.')
			{
				while(b[j].loc==b[j-1].loc&&j<n)
				{
					b[j-1].dir='.';
					j++;
				}
				b[j-1].dir='.';
			}
		}
		sort(b,b+n,cmp1);
		for(i=0;i<n;i++)
		{
			if(b[i].loc>=0&&b[i].loc<=L)
			{
				printf("%d ",b[i].loc);
				if(b[i].dir=='.')
					printf("Turning\n");
				else
					printf("%c\n",b[i].dir);
			}
			else
				printf("Fell off\n");
		}
		printf("\n");
	}
	return 0;
}