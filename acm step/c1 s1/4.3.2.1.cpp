//4.3.2������ 
#include<stdio.h>
#include<math.h>
#include<string.h>
int a[25],ben[25],n;
int prime(int k)
{
    int i;
    for(i=2;i<sqrt(k)+1;++i)
        if(k%i==0)
            return 0;
    return 1;
}
void print(int count)
{
    int i;
    if(count==n&&prime(a[0]+a[n-1]))//����������ʱ�����
    {
        for(i=0;i<n-1;++i)
            printf("%d ",a[i]);
        printf("%d\n",a[i]);
    }
    else
    {
        for(i=2;i<=n;++i)
        {
            if(!ben[i]&&prime(i+a[count-1]))//��ben�����
            {
                a[count]=i;
                ben[i]=1;
                print(count+1);
                ben[i]=0;//�����������
            }
        }
    }
}

int main()
{
    int T=1;
    a[0]=1;
    while(scanf("%d",&n)!=EOF)
    {
        memset(ben,0,sizeof(ben));
        printf("Case %d:\n",T++);
        print(1);
        printf("\n");
    }
    return 0;
}
