#include<stdio.h>
const int maxn=1000*1000;
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	int s[maxn],a[maxn];
	bool falg[maxn];
	int size=1;
	for(int i=1;i<n;i+=2)
	{
		s[size]=i;//�洢���� 
		a[i]=size++;//�洢i��λ�� 
		falg[i]=true;//ȷ��i�������� 
	}
	for(int i=2;i<size;i++)
	{
		int mod=s[i];
		for(int j=mod;j<size;j+=mod,p++)
		{
			falg[s[j]]=false;
			for(int k=1;k<mod&&k+j<size;k++)
			{
				
			}
		}
	}
}
