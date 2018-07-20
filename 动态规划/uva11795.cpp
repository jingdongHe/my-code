#include<cstdio>   
#include<iostream>   
#include<cstring>   
using namespace std;  
  
const int maxn = 17;  
int attack[maxn];       //表示每个机器人能干掉的   
int can_attack[1<<16];  //表示每个状态能干掉的   
long long dp[1<<16];    //用来统计每种状态的种数   
char s[maxn];  
int n;
void change(int k)
{
	int c[maxn]={0},s=0;
	if(k==0)
	{
		printf("000");
		return;
	}	
	while(k!=0)
	{
		c[s++]=k%2;
		k/=2;
	}
	for(int i=n-1;i>=0;i--)
		printf("%d",c[i]);
	return;
}   
int main()  
{  
    int T;  
    int ca = 1;  
    scanf("%d",&T);  
    while(T--)  
    {  
        scanf("%d",&n);  
        for(int i=0;i<=n;i++)  
        {  
            attack[i] = 0;  
            scanf("%s",s);  
            for(int j=0;j<n;j++)  
            {  
                if(s[j]=='1')  
                    attack[i] |= (1<<j);  
            }  
        }  
  		for(int i=0;i<=n;i++)
  		{
  			change(attack[i]);printf("....");
  		}
  		printf("\n");
        int total = (1<<n)-1;  
        for(int st=0;st<=total;st++)  
        {  
            can_attack[st] = attack[0];//开始的状态必须添加  
            //对每个机器人来说,如果状态可以干掉i，那么也就是可以干掉i所能干掉的   
            for(int i=1;i<=n;i++)  
            {  
                int j=i-1;  
                if(st&(1<<j)) //检查个机器人是否可杀，若可杀，把他所有可杀的加入集合 
                    can_attack[st] |= attack[i];  
            }  
        }  
  		for(int st=0;st<=total;st++)
  		{
  			printf("%d:",st);
  			change(can_attack[st]);
  			printf("..");
  		}
  		printf("\n");
        //枚举状态   
        memset(dp,0,sizeof(dp));  
        dp[0]=1;  
        for(int st=1;st<=total;st++)  
        {  
            for(int i=0;i<n;i++)  
            {  
                if(st & (1<<i))//如果st的这种状态能够攻击i，   
                                //那么要由不能干掉i的状态转移过来,即st^(1<<i)   
                                //而且st^(1<<i)这种状态要能够干掉i   
                                //在i集合中最后杀掉j的方法数   
               //  j在i中    st[i^(1<<j)]是在i中杀掉除j外所有的机器人得到武器后   
                //         所能杀的机器人的集合，看j到底能不能放到最后杀   
                //          这是把所有杀人的情况分成最后杀谁几部分枚举   
                //          这是加法原理，如去一个地方坐飞机有a中路线，火车有b种路线，   
                //          客车有c种路线，那么全部的方法就是a+b+c   
                {  
                    if(can_attack[st^(1<<i)]&(1<<i))  
                    	dp[st] += dp[st^(1<<i)]; 
                }  
            }  
        }  
  
        cout<<"Case "<<ca++<<": "<<dp[total]<<endl;  
  
  
    }  
    return 0;  
}  
