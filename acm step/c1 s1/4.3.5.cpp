#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn=70;
int n,length,t;
int arr[maxn];
bool use[maxn];
//s 已组成的木棒数目,len已经组成的长度，pos搜索的木棒的下标的位置
bool dfs(int s,int len,int pos)
{
    if(s==t)return true;
    for(int i=pos+1;i<n;i++)
    {
        //如果这个木棒已经用过，则继续下一根
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
            //剪枝：如果当前搜索时，前边的长度为0，而第一根没有成功的使用，
            //说明第一根始终要被废弃，所以这种组合必定不会成功
            //此处的剪枝必须有，因为这里的剪枝会节省很多的无用搜索，
            //我试了一下，此处剪枝省去就会超时的。。。。
            if(len==0)return false;
            //剪枝：如果当前和上一次搜到的木棒是一样长的则没必要再搜一次了
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
