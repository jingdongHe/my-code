#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct node {
	int x,y,z,p;
};
struct edge {
	double length;
	int i,j;
	edge(int i=0,int j=0,double length=0):i(i),j(j),length(length){}  
};
double Length(node a,node b)
{
	int x=a.x-b.x,y=a.y-b.y,z=a.z-b.z;
	return sqrt(x*x+y*y+z*z);
}
bool cmp(edge a,edge b)
{
	return a.length<b.length;
}
const int maxn=100+10;
int main()
{
	int n,i,j,m;
	int c[maxn]={0};
	node star[maxn];
	edge e[maxn*maxn];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d%d%d",&star[i].x,&star[i].y,&star[i].z,&star[i].p);
	m=0;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
			e[m++]=edge(i,j,Length(star[i],star[j]));
	}
	int ans=0,cur=0;  
    double len=0;  
    for(i=0;i<m;i++)  
    {  
		int u=e[i].i,v=e[i].j;  
        double l=e[i].length;  
        if(star[u].p!=star[v].p)  
        {  
            c[u]--;  
            c[v]--;  
			if(c[u]==-1) cur++;
			if(c[v]==-1) cur++;
        }  
        else  
        {  
            c[u]++;  
            c[v]++;  
			if(c[u]==0) cur--;
			if(c[v]==0) cur--;
        }  
        //if(i!=m-1&&fabs(l-e[i+1].length)<1e-6) continue;  
        if(cur>ans)  
         {  
             ans=cur;  
             len=l;  
         }  
    }  
    printf("%d\n",ans);  
    printf("%.4f\n",len);
	return 0;
}
