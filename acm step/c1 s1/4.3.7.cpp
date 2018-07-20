#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
struct node {
	int k,step;
	node (){};
	node (int _k,int _step):k(_k),step(_step){};
	node operator + (node temp)
	{
		return node(k+temp.k,step+temp.step);
	}
};
node dfs(string s)
{
	int pos=0,k=0;//²½ÊýºÍÀ¨ºÅ
	if(s[pos]=='M') {pos+=4;k+=1;}
	else
	{
		int a=0,sum=0,f=0;
		while(s[pos]>='0'&&s[pos]<='9')
		{a=a*10+s[pos]-'0';pos++;}
		sum+=a; 
		while(s[pos]=='+')
		{
			pos++;a=0;f++;
			while(s[pos]>='0'&&s[pos]<='9')
			{a=a*10+s[pos]-'0';pos++;}
			sum+=a;
		}
		//printf("%d+++%d\n",sum,f);
		return node(sum,f);
	}
	node k1,k2;
	int mark;
	for(int i=pos;i<s.length();i++)
	{
		if(s[i]=='(')
			k++;
		else if(s[i]==')')
		{
			k--;
			if(k==0)
			{
				string s2=s.substr(mark+1,i-mark-1);
				//cout<<s2<<"......."<<endl;
				k2=dfs(s2);
				int temp_step,temp_k;
				if(k1.k>k2.k)
				{temp_k=k1.k;temp_step=2*k1.step+k2.step;}
				else
				{temp_k=k2.k;temp_step=2*k2.step+k1.step;}
				//printf("%d+++++++++%d\n",temp_k,temp_step);
				return node(temp_k,temp_step);
			}
		}
		else if(s[i]==','&&k==1)
		{
			string s1=s.substr(pos,i-pos);
			//cout<<s1<<"......."<<endl;
			mark=i;
			k1=dfs(s1);
		}
	}
}
int main()
{
	int T;
	string s;
	scanf("%d",&T);
	while(T--)
	{
		cin>>s;
		int f=0,front=0;
		node temp,Max(0,0);
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='(') f++;
			else if(s[i]==')') f--;
			else if(s[i]=='+'&&f==0)
			{
				string s1=s.substr(front,i-front);
				//cout<<s1<<endl;
				temp=dfs(s1);
				Max=Max+temp;
				front=i+1;
				Max.step++;
			} 
		}
		string s1=s.substr(front,s.length()-front);
		//cout<<s1<<endl;
		temp=dfs(s1);
		Max=Max+temp;
		printf("%d %d\n",Max.k,Max.step);
	}
	return 0;
}
