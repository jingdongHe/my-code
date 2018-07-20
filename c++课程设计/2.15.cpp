/*　　　15． 通讯录管理 
　　　问题描述
　　　编写一个简单的通讯录管理程序。通讯录记录有姓名，地址(省、市(县)、街道)，电话号码，邮政编码等四项。
　　　基本要求
　　　程序应提供的基本基本管理功能有：
添加：即增加一个人的记录到通信录中
显示：即在屏幕上显示所有通信录中的人员信息，应能分屏显示。
存储：即将通讯录信息保存在一个文件中。
装入：即将文件中的信息读入程序。
查询：可根据姓名查找某人的相关信息，若找到显示其姓名、地址、电话号码和邮政编码。
修改：可修改一个人的除姓名外其它信息。
　　　测试数据
　　　程序应输入不少于10个人员的通讯录信息，应考虑到人员可以同名的情况。
　　　实现提示
　　　程序可用一个单向链表来管理人员信息，每个人员的姓名，地址，电话号码和邮政编码用一个类Cperson来实现，
作为链表的值指针指向这些Cperson类对象，通过链表的遍历可以操作这些数据。*/
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
ofstream fout("2.15.data.txt",ios_base::out|ios_base::app);
ifstream fin("2.15.data.txt");
class Cperson{
private:
	string name,stress,phone,number;
public:
	Cperson *next;
	Cperson()
	{
	}
	Cperson(string name,string stress,string phone,string number)
	{
		this->name=name;
		this->stress=stress;
		this->phone=phone;
		this->number=number;
		this->next=NULL;
	}
	void print()
	{
		cout<<"The name is "<<name<<endl<<name<<" locat in "<<stress<<endl<<"the phone is "<<phone<<endl<<"the stress number is "<<number<<endl;
	}
	void input()
	{
		fout<<"The name is "<<name<<endl<<name<<" locat in "<<stress<<endl<<"the phone is "<<phone<<endl<<"the stress number is "<<number<<endl;
	}
	string getname()
	{
		return name;
	}
};
class person : public Cperson{
private:
	Cperson *star,*end,*p,*pf,*pd;
public:
	person ()
	{
		star=NULL;
	}
	void add(string name,string stress,string phone,string number)
	{
		p=(Cperson *)new Cperson(name,stress,phone,number);
		if(star==NULL)
			star=p;
		else
			end->next=p;
		end=p;
	}
	void Add1()
	{
		printf("Please entry the name,stress,phone and number\n");
		string name,stress,phone,number;
		cin>>name>>stress>>phone>>number;
		add(name,stress,phone,number);
	}
	void Add2()
	{
		string line;
		string s[4];
		int i=0;
		while(getline(fin,line))
		{
			//cout<<line<<endl;
			int d;
			d=line.size()-1;
			while(line[d]!=' ')
				s[i]=line[d--]+s[i];
			i++;
			if(i==4)
			{
				add(s[0],s[1],s[2],s[3]);
				//cout<<s[0]<<endl<<s[1]<<s[2]<<endl<<s[3]<<endl;
				i=0;
				s[0]="";s[1]="";s[2]="";s[3]="";
			}
		}
		
	}
	void show()
	{
		p=star;
		while(p!=end)
		{
			p->print();
			cout<<endl<<endl;
			p=p->next;
		}
		p->print();
	}
	void check()
	{
		cout<<"Who is your change target\n";
		string name;
		cin>>name;
		p=star;
		while(p!=end)
		{
			if(p->getname()==name)
			{
				p->print();
				cout<<endl<<endl;
				return ;
			}
			p=p->next;
		}
		if(p->getname()==name)
		{
			p->print();
				cout<<endl<<endl;
				return ;
		}
		cout<<name<<" not in Contacts"<<endl;
	}
	void change()
	{
		string name;
		cout<<"Who is your change target\n";
		cin>>name;
		p=star;
		while(p!=end)
		{
			if(p->getname()==name)
			{
				cout<<"Please entry the new information\n";
				string stress,phone,number;
				cin>>stress>>phone>>number;
				Cperson *px=(Cperson *)new Cperson(name,stress,phone,number);
			//	px->print();
				if(p==star)
				{
					px->next=star->next;
					star=px;
					delete p;
				}
				else
				{
					px->next=p->next;
					pf->next=px;
					delete p;
				}
				return ;
			}
			
			pf=p;p=p->next;
		}
		if(p->getname()==name)
		{
			cout<<"Please entry the new information\n";
			string stress,phone,number;
			cin>>stress>>phone>>number;
			Cperson *px=(Cperson *)new Cperson(name,stress,phone,number);
			//px->print();pf->print();
			px->next=NULL;
			pf->next=px;
			end=px;
			delete p;
			return ;
		}
		cout<<name<<" not in Contacts"<<endl;
	}
	void Input()
	{
		p=star;
		while(p!=end)
		{
			p->input();
			//fcout<<"The name is "<<name<<endl<<name<<" locat in "<<stress<<endl<<"the phone is "<<phone<<endl<<"the stress number is "<<number<<endl;
			p=p->next;
		}
		p->input();
		//fcout<<"The name is "<<name<<endl<<name<<" locat in "<<stress<<endl<<"the phone is "<<phone<<endl<<"the stress number is "<<number<<endl;
	}
};
int main()
{
	person c;
	
	cout<<"---------------------------------------\n";
	cout<<"|Please entry the operation\n|0: exit\n|1: add some to Contacts\n|2: show all informations of the Contacts\n|3: find some one\n|4:change some information\n|5: input the informations to txt\n|6: get information fron txt\n";
	cout<<"---------------------------------------\n";
	int d;
	while(1)
	{
		scanf("%d",&d);
		if(d==0) break;
		switch(d)
		{
		case 1:c.Add1();break;
		case 2:c.show();break;
		case 3:c.check();break;
		case 4:c.change();break;
		case 5:{ofstream Clear("2.15.data.txt");Clear.close();c.Input();break;}
		case 6:c.Add2();break;
		}
		cout<<"----------------------------------\n";
		cout<<"|Please entry the operation\n|0: exit\n|1: add some to Contacts\n|2: show all informations of the Contacts\n|3: find some one\n|4:change some information\n|5: input the informations to txt\n|6: get information fron txt\n";
		cout<<"----------------------------------\n";
	}
	fin.close();
	fout.close();
	return 0;
}
