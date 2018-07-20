#include <iostream>
#include <string>
#include<string.h>
#include <stdio.h>
using namespace std;
int main()
{
    string a,b;
    while(cin>>a>>b)
    {
        int len=a.length(),i,j;
        int nla[26],nlb[26];
        memset(nla,0,sizeof(nla));
        memset(nlb,0,sizeof(nlb));
        for(i=0;i<len;i++)
        {
            int la=a[i]-'A';
            int lb=b[i]-'A';
            nla[la]++;nlb[lb]++;
        }
        for(i=0;i<26;i++)
        {
            for(j=0;j<26;j++)
            {
                if(nla[i]&&nlb[j]&&nla[i]==nlb[j])
                {
                    len-=nla[i];
                    nla[i]=nlb[j]=0;
                }
            }
        }
        if(len!=0)printf("NO\n");
        else printf("YES\n");
    }

    return 0;
}