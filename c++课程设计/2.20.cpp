/*　　　20. 模拟计算器程序
　　　问题描述
　　　设计一个程序来模拟一个简单的手持计算器。程序支持算术运算+、-、*、/、=、以及Ｃ（清除）、A（全清除）操作。
基本要求
　　　程序运行时，显示一个窗口，等待用户输入，用户可以从键盘输入要计算的表达式，
输入的表达式显示在窗口中，用户键入’=’ 符号后，窗口显示出结果。
测试数据
程序输入不少于5种不同的表达式进行测试。
实现提示
　　　可定义一个计算器类，该类包括两个组件对象，一个计算引擎和一个用户接口，
用户接口对象处理接受的键盘输入信息，并显示答案，计算引擎对象对给出的数据执行相应操作，并存储操作的结果。
选作内容
　　　如果用户输入的表达式不合法，可以判别出来并给出相应的错误提示。*/
#include <conio.h>//用于非回显输入
#include<stdio.h>
#include<stack>
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
class cal {
private:
	string f;
	stack<string> s;
public :
	void input_output();//输入输出接口
	void math();//计算引擎

	string int_to_string(int k)
	{
		if(k==0)
			return "0";
		char temp[20]={'\0'};int j=0;
		string res="";
		while(k!=0)
		{
			temp[j++]=k%10+'0';
			k/=10;
		}
		for(int i=j-1;i>=0;i--)
			{res+=temp[i];}
		return res;
	}
	int string_to_int(string s)
	{
		int d=0;
		for(int i=0;i<s.length();i++)
			d=d*10+s[i]-'0';
		return d;
	}
	int pri(string s)
	{
		if(s=="+"||s=="-")
			return 1;
		else if(s=="*"||s=="/")
			return 2;
		else if(s=="(")
			return -2;
		else if(s=="#")
			return -2;
		else
			return -1;
	}
};

void cal::input_output()//用于用户的输入输出
{
	char ch;
	ch=getch();
	while(ch!='=')
	{
		if(ch=='A')
			f="";
		else if(ch=='C')
		{
			string f1;
			for(int i=0;i<f.length()-1;i++)
				f1+=f[i];
			f=f1;
		}
		else
			f+=ch;
		system("cls");
		cout<<f;
		ch=getch();
	}
	if(ch=='=')
	{math() ;return;}
	return;
}
void cal::math()//核心部分，一个栈的就算器
//注意一下，该栈为字符串栈，拿出数据时需将字符串转化为数字
{
	string sign="",shuzi="";
	s.push("#");int k=-2;int q=0;
	for(int i=0;i<=f.length();i++)
	{
		if(f[i]>='0'&&f[i]<='9')
			shuzi+=f[i];
		else
		{
			if(shuzi!="")
				s.push(shuzi);
			shuzi="";
			sign+=f[i];
			int k1=pri(sign);
			//cout<<"k:"<<k<<" k1:"<<k1<<endl;
			if(sign=="(")
			{
				q=0;
				k=pri(sign);
				s.push(sign);
				sign="";
				continue;
			}
			if(sign==")")
			{
				sign="";
				while(1)
				{
					string a,b,c;
					int c1;
					a=s.top();s.pop();
					b=s.top();s.pop();
					c=s.top();s.pop();
					if(s.top()=="(")
					{s.pop();q=1;k=pri(s.top());}
					//k=pri(s.top());
					if(b=="+")
						c1=string_to_int(a)+string_to_int(c);
					else if(b=="-")
						c1=string_to_int(c)-string_to_int(a);
					else if(b=="*")
						c1=string_to_int(a)*string_to_int(c);
					else if(b=="/")
						c1=string_to_int(c)/string_to_int(a);
					
					c=int_to_string(c1);
					s.push(c);
					if(q==1)
						break;
				}
				continue;
			}
			while(k1<=k)
			{
				string a,b,c;
				int c1;
				a=s.top();s.pop();
				b=s.top();s.pop();
				c=s.top();s.pop();
				k=pri(s.top());
				if(b=="+")
					c1=string_to_int(a)+string_to_int(c);
				else if(b=="-")
					c1=string_to_int(c)-string_to_int(a);
				else if(b=="*")
					c1=string_to_int(a)*string_to_int(c);
				else if(b=="/")
					c1=string_to_int(c)/string_to_int(a);
				//cout<<"c:"<<c1<<"........."<<a<<"..........."<<b<<".........."<<c<<endl;
				c=int_to_string(c1);
				s.push(c);
			}
			s.push(sign);
			k=k1;
			sign="";
		}
	}
	/*int q=0;
	while(!s.empty())
	{
		cout<<s.top()<<endl;
		cout<<q++<<"11111111111"<<endl;
		s.pop();
	}*/
	s.pop();
	cout<<"="<<s.top()<<endl;
	return;
}
int main()
{
	cal c;
	c.input_output();
//	c.math();
	/*cout<<c.int_to_string(159)<<endl;
	cout<<c.string_to_int("987");*/
	return 0;
}
