#include<stdio.h>
#include<algorithm>
typedef struct node {
	int x,y,z;
}block;
bool cmp(block a,block b)
{
	return a.x*a.y>b.x*b.y;
}
const int maxn=100;
int main()
{
	int n,k=1;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		block arr[maxn];int h[maxn];
		for(int i=0;i<3*n;)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			//printf("%d:%d....%d....%d\n",i,a,b,c);
			if(a>b)
			{arr[i].x=a;arr[i].y=b;arr[i++].z=c;}
			else 
			{arr[i].x=b;arr[i].y=a;arr[i++].z=c;}
			if(b>c)
			{arr[i].x=b;arr[i].y=c;arr[i++].z=a;}
			else 
			{arr[i].x=c;arr[i].y=b;arr[i++].z=a;}
			if(a>c)
			{arr[i].x=a;arr[i].y=c;arr[i++].z=b;}
			else 
			{arr[i].x=c;arr[i].y=a;arr[i++].z=b;}
		}
		std::sort(arr,arr+3*n,cmp);
		
		for(int i=0;i<3*n;i++)
			h[i]=arr[i].z;
		/*printf("==================\n");
		for(int i=0;i<3*n;i++)
			printf("%d:%d  %d  %d  %d\n",i,arr[i].x,arr[i].y,arr[i].z,h[i]);
		printf("==================\n");*/
		int max=0;
		for(int i=1;i<3*n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(arr[i].x<arr[j].x&&arr[i].y<arr[j].y&&h[j]+arr[i].z>h[i])
					h[i]=h[j]+arr[i].z;
			}
			if(max<h[i]) max=h[i];
		}
		printf("Case %d: maximum height = %d\n",k,max);k++;
	}
	return 0;
}
