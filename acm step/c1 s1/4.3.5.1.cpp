//答案在4.3.5 
#include <iostream>
#include <algorithm>
using namespace std;

//total能组成的木棒的组数,l:组成的木棒的长度
int total,l;
//num:输入的整数，sum：总长度
int num,sum;
typedef struct
{
    int length;//木棒的长度
    bool mark;//木棒是否被使用过
}Sticks;
Sticks sticks[70];

bool cmp(Sticks a,Sticks b)
{
    return a.length>b.length;
}
//s 已组成的木棒数目,len已经组成的长度，pos搜索的木棒的下标的位置
int dfs(int s,int len,int pos)
{
    if(s==total)return 1;
    for(int i=pos+1;i<num;i++)
    {
        //如果这个木棒已经用过，则继续下一根
        if(sticks[i].mark)continue;
        if(len+sticks[i].length == l)
        {
            sticks[i].mark = true;
            if(dfs(s+1,0,-1))return true;
            sticks[i].mark = false;
            return false;
        }else if(sticks[i].length+len<l){
            sticks[i].mark = true;
            if(dfs(s,len+sticks[i].length,i))
            return true;
            sticks[i].mark = false;
            //剪枝：如果当前搜索时，前边的长度为0，而第一根没有成功的使用，
            //说明第一根始终要被废弃，所以这种组合必定不会成功
            //此处的剪枝必须有，因为这里的剪枝会节省很多的无用搜索，
            //我试了一下，此处剪枝省去就会超时的。。。。
            if(len==0)return false;
            //剪枝：如果当前和上一次搜到的木棒是一样长的则没必要再搜一次了
            while(sticks[i].length==sticks[i+1].length)i++;
        }
    }
    return false;
}

int main()
{

    while(cin>>num&&num!=0)
    {
        sum = 0;//标记为0
        for(int i = 0; i < num; i++)
        {
            cin>>sticks[i].length;
            sum += sticks[i].length;
            sticks[i].mark = false;
        }
        //将木棒按照长度从长到短的顺序排序
        sort(sticks,sticks+num,cmp);
        //从木棒的最长的那根开始搜索，因为最小的组合也会大于等于最长的那根
        for(l = sticks[0].length; l <= sum; l++)
        {
            //剪枝一：如果不能被整除说明不能组成整数根木棒，搜下一个
            if(sum%l!=0)continue;
            total = sum / l;//得到木棒总数目
            if(dfs(1,0,-1))
            {
                cout<<l<<endl;
                break;
            }
        }
    }
    return 0;
}
