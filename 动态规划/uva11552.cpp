#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn=1000+5;

int f[maxn][maxn];
char s[maxn];
bool vis[maxn];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int k,len;
		scanf("%d",&k);
		scanf("%s",&s);
		len=strlen(s);
		memset(f,9999,sizeof(f));
		for(int i=1;i<=len;i++)
		{
			memset(vis,false,sizeof(vis));
			for(int j=1;j<=k;j++)
				vis[s[(i-1)*k+j-1]]=true;
			int chunk=0;
			for(int j='a';j<='z';j++)
				if(vis[j])
					chunk++;
			if(i==1)
			{
				for(int j=1;j<=k;j++)
					f[1][j]=chunk;
				continue;
			}
			
			for(int j=1;j<=k;j++)
			{
				int rear=(i-1)*k+j-1;
				for(int l=1;l<=k;l++)
				{
					int pre=(i-2)*k+l-1;
					if(vis[s[pre]]&&(chunk==1||s[pre]!=s[rear]))
						f[i][j]=min(f[i][j],f[i-1][l]+chunk-1);
					else
						f[i][j]=min(f[i][j],f[i-1][l]+chunk);
				}
			}
		}
		
		int ans=9999;
		for(int i=1;i<=k;i++)
			ans=min(ans,f[len/k][i]);
		printf("%d\n",ans);
		return 0;
	}
}
