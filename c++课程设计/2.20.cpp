/*������20. ģ�����������
��������������
���������һ��������ģ��һ���򵥵��ֳּ�����������֧����������+��-��*��/��=���Լ��ã��������A��ȫ�����������
����Ҫ��
��������������ʱ����ʾһ�����ڣ��ȴ��û����룬�û����ԴӼ�������Ҫ����ı��ʽ��
����ı��ʽ��ʾ�ڴ����У��û����롯=�� ���ź󣬴�����ʾ�������
��������
�������벻����5�ֲ�ͬ�ı��ʽ���в��ԡ�
ʵ����ʾ
�������ɶ���һ���������࣬������������������һ�����������һ���û��ӿڣ�
�û��ӿڶ�������ܵļ���������Ϣ������ʾ�𰸣������������Ը���������ִ����Ӧ���������洢�����Ľ����
ѡ������
����������û�����ı��ʽ���Ϸ��������б������������Ӧ�Ĵ�����ʾ��*/
#include <conio.h>//���ڷǻ�������
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
	void input_output();//��������ӿ�
	void math();//��������

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

void cal::input_output()//�����û����������
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
void cal::math()//���Ĳ��֣�һ��ջ�ľ�����
//ע��һ�£���ջΪ�ַ���ջ���ó�����ʱ�轫�ַ���ת��Ϊ����
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
