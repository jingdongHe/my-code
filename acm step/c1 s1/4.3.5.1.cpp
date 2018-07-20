//����4.3.5 
#include <iostream>
#include <algorithm>
using namespace std;

//total����ɵ�ľ��������,l:��ɵ�ľ���ĳ���
int total,l;
//num:�����������sum���ܳ���
int num,sum;
typedef struct
{
    int length;//ľ���ĳ���
    bool mark;//ľ���Ƿ�ʹ�ù�
}Sticks;
Sticks sticks[70];

bool cmp(Sticks a,Sticks b)
{
    return a.length>b.length;
}
//s ����ɵ�ľ����Ŀ,len�Ѿ���ɵĳ��ȣ�pos������ľ�����±��λ��
int dfs(int s,int len,int pos)
{
    if(s==total)return 1;
    for(int i=pos+1;i<num;i++)
    {
        //������ľ���Ѿ��ù����������һ��
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
            //��֦�������ǰ����ʱ��ǰ�ߵĳ���Ϊ0������һ��û�гɹ���ʹ�ã�
            //˵����һ��ʼ��Ҫ������������������ϱض�����ɹ�
            //�˴��ļ�֦�����У���Ϊ����ļ�֦���ʡ�ܶ������������
            //������һ�£��˴���֦ʡȥ�ͻᳬʱ�ġ�������
            if(len==0)return false;
            //��֦�������ǰ����һ���ѵ���ľ����һ��������û��Ҫ����һ����
            while(sticks[i].length==sticks[i+1].length)i++;
        }
    }
    return false;
}

int main()
{

    while(cin>>num&&num!=0)
    {
        sum = 0;//���Ϊ0
        for(int i = 0; i < num; i++)
        {
            cin>>sticks[i].length;
            sum += sticks[i].length;
            sticks[i].mark = false;
        }
        //��ľ�����ճ��ȴӳ����̵�˳������
        sort(sticks,sticks+num,cmp);
        //��ľ��������Ǹ���ʼ��������Ϊ��С�����Ҳ����ڵ�������Ǹ�
        for(l = sticks[0].length; l <= sum; l++)
        {
            //��֦һ��������ܱ�����˵���������������ľ��������һ��
            if(sum%l!=0)continue;
            total = sum / l;//�õ�ľ������Ŀ
            if(dfs(1,0,-1))
            {
                cout<<l<<endl;
                break;
            }
        }
    }
    return 0;
}
