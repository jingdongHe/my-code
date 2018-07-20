/*　　13. 编写程序，从键盘读入一个文本文件名字（可带路径），
为该文件中的所有单词建立一个词汇索引。按字母顺序显示所有单词（仅一次），
后面紧跟着它们所在的行号。大写与小写字母被认为是相同的。例如，对于下列的输入文件：*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;
typedef struct word {
	string s;
	vector<int>line;
}word;
void print(vector<word> Q)
{
	int i,j;
	for(i=0;i<Q.size();i++)
	{
		cout<<Q[i].s<<":";
		for(j=0;j<Q[i].line.size();j++)
			cout<<Q[i].line[j]<<" ";
		cout<<endl;
	}
}
bool operator == (string a,string b)
{
	if(a.size()!=b.size())
		return false;
	int i;
	for(i=0;i<a.size();i++)
	{
		if(a[i]==b[i]||abs(a[i]-b[i])==32)
			continue;
		else
			return false;
	}
	return true;
}
int find(vector<word> Q,string s)
{
	int b=0,e=Q.size();
	for(b;b<e;b++)
	{
		if(Q[b].s==s)
			return b;
	}
	return -1;
}
int main()
{
	vector<word> Q;
	Q.clear();
	string s;
	char s1[20];
	int f=0;
	ifstream fin;
	fin.open("fly me to the moon.txt");
	while(getline(fin,s))
	{
		f++;
		int d=0,i=0;;
		while(s[i]!='\0')
		{
			d=0;
			while((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
			{
				s1[d++]=s[i++];
			}
			if(d==0) {i++;continue;}
			string s2="";
			for(int j=0;j<d;j++)
				s2+=s1[j];
			int k=find(Q,s2);
			if(k!=-1)
			{
				Q[k].line.push_back(f);
			}
			else
			{
				word c;
				c.s="";
				c.line.clear();
				c.line.push_back(f);
				c.s+=s2;
				Q.push_back(c);
			}
			if(s[i]!='\0')
				i++;
		}
	}
	print(Q);
	fin.close();
	return 0;
}