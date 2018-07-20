#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int n;
typedef struct node {
	int name;
	int price;
	int quality;
}node;
int find(vector<string> array,string s)
{
	for(int i=0;i<array.size();i++)
	{
		
		if(array[i]==s)
		{
			return i;
		}
	}
	return -1;
}
bool cmp_quality(node a,node b)
{
	return a.quality>b.quality;
}
bool cmp_price(node a,node b)
{
	return a.price<b.price;
}
bool ok(node a[],int x,int b,int var)//�ж���xΪ���Ʒ�ʵ���������ܷ���װһ̨������bԪ�Ļ���
{
	bool used[1000+5]={false};
	node temp[1000+5];
	int j=0;
	//�ҳ�Ʒ��>=x��������� 
	for(int i=0;i<n;i++)
	{
		if(a[i].quality>=x)
		{
			temp[j++]=a[i];
		}
		else
			break;
	}
	//��Ѱ�ҳ���������۸�����Ȼ���С�����Һ��ʵ���� 
	sort(temp,temp+j,cmp_price);
	int cnt=0,k=0;
	for(int i=0;i<j;i++)
	{
		if(used[temp[i].name]==false)
		{
			used[temp[i].name]=true;
			cnt+=temp[i].price;
			k++;
		}
		if(cnt>b)
			return false;
		if(k>=var&&cnt<=b)
			return true;
	}
	return false;
} 
int main()
{
	vector<string> Name;
	int T,b;
	int max=0,min=999999999;
	node array[1000];
	scanf("%d",&T);
	for(int t=0;t<T;t++)
	{
		//���������� 
		scanf("%d%d",&n,&b);
		for(int i=0;i<n;i++)
		{
			string s;
			cin>>s;
			int k=find(Name,s);
			if(k==-1)
			{
				array[i].name=Name.size();
				Name.push_back(s);
				
			}
			else
				array[i].name=k;
			scanf("%d%d",&array[i].quality,&array[i].price);
			if(array[i].quality>max) max=array[i].quality;
			if(array[i].quality<min) min=array[i].quality;
		}
		
		//��Ʒ�ʽ������� 
		sort(array,array+n,cmp_quality);
		while(max>min)
		{
			int mid=(max+min)/2;
			if(ok(array,mid,b,Name.size()))
			{min=mid;}
			else
			{max=mid-1;}
		}
		printf("%d\n",max);
		 
	}
	return 0;
}
