/*������15�� ͨѶ¼���� 
��������������
��������дһ���򵥵�ͨѶ¼�������ͨѶ¼��¼����������ַ(ʡ����(��)���ֵ�)���绰���룬������������
����������Ҫ��
����������Ӧ�ṩ�Ļ��������������У�
��ӣ�������һ���˵ļ�¼��ͨ��¼��
��ʾ��������Ļ����ʾ����ͨ��¼�е���Ա��Ϣ��Ӧ�ܷ�����ʾ��
�洢������ͨѶ¼��Ϣ������һ���ļ��С�
װ�룺�����ļ��е���Ϣ�������
��ѯ���ɸ�����������ĳ�˵������Ϣ�����ҵ���ʾ����������ַ���绰������������롣
�޸ģ����޸�һ���˵ĳ�������������Ϣ��
��������������
����������Ӧ���벻����10����Ա��ͨѶ¼��Ϣ��Ӧ���ǵ���Ա����ͬ���������
������ʵ����ʾ
�������������һ������������������Ա��Ϣ��ÿ����Ա����������ַ���绰���������������һ����Cperson��ʵ�֣�
��Ϊ�����ֵָ��ָ����ЩCperson�����ͨ������ı������Բ�����Щ���ݡ�*/
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
