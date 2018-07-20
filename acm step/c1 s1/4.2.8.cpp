#include<iostream>
#include<queue>
using namespace std;
char map[10][10];
int n,m,T,ans,dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool vis[10][10][2];//��ά���飬����ά��ʾ�õ��Ƿ����õ�����ʯ
struct node
{
    int x,y,num,step;
    int rox[64],roy[64];
    //x��y��ʾ���꣬num��ʾ�Ƿ��õ���ʯ��step��ʾ��������ʱ�䣬rox[]��roy[]�ֱ𱣴浽��õ��·��
};
node f; //��ʼ��
queue<node> Q;
void dfs(int deep)
{
    if(deep>ans) return ;//�ܹ����ֻ������ĸ����򣬼���ڻ���ڵ��ĸ�����
    node t;
    while(!Q.empty())//��ն���
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
            }//����·��
            vis[i][j][temp.num]=1;
            temp.x=i;temp.y=j;
            temp.step=t.step+1;
            temp.rox[temp.step]=i;
            temp.roy[temp.step]=j;
            Q.push(temp);
        }
    }
    if(minstep==-1) //minstep==-1��ʾ�÷����������óɹ���kid�޷��������
    {
            if(deep<ans)
                ans=deep;
            return ;
    }
    for(int i=1;i<t.step;i++)
    {
        char cc=map[t.rox[i]][t.roy[i]];//����ԭ�ȵĵ�ͼ
        if(cc=='E'||cc=='S')//��ڻ���ڲ��ܷ���
            continue;
        map[t.rox[i]][t.roy[i]]='#';
        dfs(deep+1);//����һ����������󣬼�������
        map[t.rox[i]][t.roy[i]]=cc;//����ͼ��ԭ
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
