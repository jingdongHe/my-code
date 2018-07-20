#include<cstdio>   
#include<iostream>   
#include<cstring>   
using namespace std;  
  
const int maxn = 17;  
int attack[maxn];       //��ʾÿ���������ܸɵ���   
int can_attack[1<<16];  //��ʾÿ��״̬�ܸɵ���   
long long dp[1<<16];    //����ͳ��ÿ��״̬������   
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
            can_attack[st] = attack[0];//��ʼ��״̬�������  
            //��ÿ����������˵,���״̬���Ըɵ�i����ôҲ���ǿ��Ըɵ�i���ܸɵ���   
            for(int i=1;i<=n;i++)  
            {  
                int j=i-1;  
                if(st&(1<<j)) //�����������Ƿ��ɱ������ɱ���������п�ɱ�ļ��뼯�� 
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
        //ö��״̬   
        memset(dp,0,sizeof(dp));  
        dp[0]=1;  
        for(int st=1;st<=total;st++)  
        {  
            for(int i=0;i<n;i++)  
            {  
                if(st & (1<<i))//���st������״̬�ܹ�����i��   
                                //��ôҪ�ɲ��ܸɵ�i��״̬ת�ƹ���,��st^(1<<i)   
                                //����st^(1<<i)����״̬Ҫ�ܹ��ɵ�i   
                                //��i���������ɱ��j�ķ�����   
               //  j��i��    st[i^(1<<j)]����i��ɱ����j�����еĻ����˵õ�������   
                //         ����ɱ�Ļ����˵ļ��ϣ���j�����ܲ��ܷŵ����ɱ   
                //          ���ǰ�����ɱ�˵�����ֳ����ɱ˭������ö��   
                //          ���Ǽӷ�ԭ����ȥһ���ط����ɻ���a��·�ߣ�����b��·�ߣ�   
                //          �ͳ���c��·�ߣ���ôȫ���ķ�������a+b+c   
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
