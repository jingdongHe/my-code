#include<iostream>
#include<queue>
using namespace std;
char map[10][10];
int n,m,T,ans,dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool vis[10][10][2];//三维数组，第三维表示该点是否已拿到过宝石
struct node
{
    int x,y,num,step;
    int rox[64],roy[64];
    //x，y表示坐标，num表示是否拿到宝石，step表示步数或者时间，rox[]和roy[]分别保存到达该点的路径
};
node f; //起始点
queue<node> Q;
void dfs(int deep)
{
    if(deep>ans) return ;//总共最多只需封锁四个区域，即入口或出口的四个方向
    node t;
    while(!Q.empty())//清空队列
        Q.pop();
    Q.push(f);
    memset(vis,0,sizeof(vis));
    vis[f.x][f.y][0]=1;
    int minstep=-1;
    while(!Q.empty())
    {
         t=Q.front();
         Q.pop();
         node temp;
        if(map[t.x][t.y]=='E'&&t.num)
            {
                minstep=t.step;
                break;
            }
        for(int k=0;k<4;k++)
        {
            int i=t.x+dir[k][0];
            int j=t.y+dir[k][1];
            if(i>n||i<1||j>m||j<1||map[i][j]=='#'||t.step>=T) continue;
            if(map[i][j]=='J') temp.num=1;
            else temp.num=t.num;
            if(vis[i][j][temp.num]) continue;
            for(int l=1;l<=t.step;l++)
            {
                temp.rox[l]=t.rox[l];
                temp.roy[l]=t.roy[l];
            }//保存路径
            vis[i][j][temp.num]=1;
            temp.x=i;temp.y=j;
            temp.step=t.step+1;
            temp.rox[temp.step]=i;
            temp.roy[temp.step]=j;
            Q.push(temp);
        }
    }
    if(minstep==-1) //minstep==-1表示该封锁区域设置成功，kid无法完成任务
    {
            if(deep<ans)
                ans=deep;
            return ;
    }
    for(int i=1;i<t.step;i++)
    {
        char cc=map[t.rox[i]][t.roy[i]];//保存原先的地图
        if(cc=='E'||cc=='S')//入口或出口不能封锁
            continue;
        map[t.rox[i]][t.roy[i]]='#';
        dfs(deep+1);//设置一个封锁区域后，继续遍历
        map[t.rox[i]][t.roy[i]]=cc;//将地图还原
    }
}
int main()
{
    int cas;
    cin>>cas;
    while(cas--)
    {
        cin>>n>>m>>T;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                cin>>map[i][j];
                if(map[i][j]=='S')
                    f.x=i,f.y=j;
            }
            f.num=0;f.step=0;
            ans=4;
            dfs(0);
            cout<<ans<<endl;
    }
    return 0;
}
