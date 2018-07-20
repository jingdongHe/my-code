#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
bool com(int a,int b)
{
	return a>b;
}
int main()
{
	int ma[26],mb[26];
	string A,B;
	int i,j,k;
	while(cin>>A>>B)
	{
		memset(ma,0,sizeof(ma));
		memset(mb,0,sizeof(mb));
	//	printf("11111111\n");
		//cout<<A<<endl<<B<<endl;
		for(i=0;i<A.size();i++)
		{
			ma[A[i]-'A']++;
		}
		for(i=0;i<B.size();i++)
		{
			mb[B[i]-'A']++;
		}
		//printf("222222222\n");
		sort(ma,ma+26,com);
		sort(mb,mb+26,com);
		/*for(i=0;i<26;i++)
			printf("%d ",ma[i]);
		printf("\n");
		for(i=0;i<26;i++)
			printf("%d ",mb[i]);
		printf("\n");*/
		k=0;
		//printf("3333333333\n");
		for(i=0;i<26;i++)
		{
			if(k==1)
				break;
			for(j=0;j<26;j++)
			{
				if(k==1)
					break;
				if(ma[i]!=mb[i])
				{
					printf("NO\n");
					k=1;
				}
			}
		}
	//	printf("444444444\n");
		if(k==0)
			printf("YES\n");
	}
	return 0;
}