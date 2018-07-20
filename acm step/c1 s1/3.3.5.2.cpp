#include<iostream>
#include<cstring>
#include<cstdio>
#define MAXN 11
#define MAXV 10001
 
using namespace std;
 
int cnt[MAXN][MAXN],d[MAXV],V;
char s[15];
 
void ZeroOnePack(int cost,int weight)
{
     int i;
     for(i=V;i>=cost;i--)
         d[i]=max(d[i],d[i-cost]+weight);
}
 
void CompletPack(int cost,int weight)
{
    int i;
    for(i=cost;i<=V;i++)
        d[i]=max(d[i],d[i-cost]+weight);
}
 
void MultPack(int cost,int weight,int n)
{
    if(cost*n>=V)
        CompletPack(cost,weight);
    int k;
    k=1;
    while(k<=n)
    {
        ZeroOnePack(k*cost,k*weight);
        n=n-k;
        k=k*2;
    }
    if(n)
         ZeroOnePack(n*cost,n*weight);
}
 
int main()
{
    int N,i,a,b;
    while(scanf("%d %d",&N,&V)==2)
    {
        memset(cnt,0,sizeof(cnt));
        memset(d,0,sizeof(d));
        for(i=0;i<N;i++)
        {
            scanf("%s %d %d",s,&b,&a);
            cnt[a][b]++;
        }
        for(a=0;a<MAXN;a++)
            for(b=0;b<MAXN;b++)
                if(cnt[a][b])
                    MultPack(a,b,cnt[a][b]);
        printf("%d\n",d[V]);
    }
    return 0;
}
