#include<stdio.h>
#include<string.h>
#include<iostream>
#include<list>
using namespace std;
typedef struct node {
	int price,value;
}sneak;
const int maxm=10000+5;
int main()
{
	int n,m,k;
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		int f[11][maxm];
		list<sneak> brand[11];
		for(int i=0;i<n;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			sneak temp;
			temp.price=b;temp.value=c;
			brand[a].push_back(temp);
		}
		memset(f,-1,sizeof(f));
		for(int i=0;i<=m;i++)
			f[0][i]=0;
		for(int i=1;i<=k;i++)
		{
			for(list<sneak> ::iterator s=brand[i].begin();s!=brand[i].end();s++)
			{
				for(int j=m;j>=(*s).price;j--)
				{
					if(f[i][j-(*s).price]!=-1&&f[i][j-(*s).price]+(*s).value>f[i][j])
						f[i][j]=f[i][j-(*s).price]+(*s).value;
					if(f[i-1][j-(*s).price]!=-1&&f[i-1][j-(*s).price]+(*s).value>f[i][j])
						f[i][j]=f[i-1][j-(*s).price]+(*s).value;
				}
			}
		}
		if(f[k][m]==-1)
			printf("Impossible\n");
		else
			printf("%d\n",f[k][m]);
	}
	return 0;
}
