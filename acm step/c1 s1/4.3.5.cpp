#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn=70;
int n,length,t;
int arr[maxn];
bool use[maxn];
//s ����ɵ�ľ����Ŀ,len�Ѿ���ɵĳ��ȣ�pos������ľ�����±��λ��
bool dfs(int s,int len,int pos)
{
    if(s==t)return true;
    for(int i=pos+1;i<n;i++)
    {
        //������ľ���Ѿ��ù����������һ��
        if(use[i])continue;
        if(len+arr[i] == length)
        {
            use[i] = true;
            if(dfs(s+1,0,-1))return true;
            use[i] = false;
            return false;
        }else if(arr[i]+len<length){
            use[i] = true;
            if(dfs(s,len+arr[i],i))
            return true;
            use[i] = false;
            //��֦�������ǰ����ʱ��ǰ�ߵĳ���Ϊ0������һ��û�гɹ���ʹ�ã�
            //˵����һ��ʼ��Ҫ������������������ϱض�����ɹ�
            //�˴��ļ�֦�����У���Ϊ����ļ�֦���ʡ�ܶ������������
            //������һ�£��˴���֦ʡȥ�ͻᳬʱ�ġ�������
            if(len==0)return false;
            //��֦�������ǰ����һ���ѵ���ľ����һ��������û��Ҫ����һ����
            while(arr[i]==arr[i+1])i++;
        }
    }
    return false;
}
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		int sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			sum+=arr[i];
		}
		sort(arr,arr+n,cmp);
		for(length=arr[0];length<=sum;length++)
		{
			memset(use,false,sizeof(use));
			if(sum%length!=0) continue;
			t=sum/length;
			if(dfs(0,0,-1)) break;
		}
		printf("%d\n",length);
	}
	return 0;
}
