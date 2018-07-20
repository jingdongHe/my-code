/*������5�����ʹ���
	����һ��Ա�����ʹ�����򡣹��ʹ���������ļ��д洢��Ա�������͹��ʣ��ó������¼�롢��ʾ���޸ġ�ɾ��������Ա���������͹��ʡ�
	�Ľ�Ҫ��
	1���������ʽ��д���򣬽������еĹ����������������ʽ��ţ�����һ�������࣬�����Ҫ�Ĳ���������
	2����ʾ���޸ġ�ɾ���������Ǵ�Сдͨ�á�
	3���������ݰ�����ֵ�Ĵ�С���������š�
	4���޸ġ�ɾ������ǰ������ʾ��Ϣ���û�ȷ�Ϻ���ܽ�һ���������������ȡ����
	5�����ӳ�����ļ�������빦�ܣ���ִ�г��������Ƚ��������ݴ��ļ��ж����ٽ��й����ڳ������ʱ�ܽ��������ݱ�����ԭ�ļ��С�*/
#include <stdio.h>
#include <conio.h>//�˴������������ͷ�ļ�����c++��׼
#include <string.h>
#include<string>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;
class EMP {
private:
	string name; 
	float salary;  
public:
	EMP *next;
	EMP()
	{
	}
	EMP(int i)//���캯��������Ա����Ϣ
	{
		printf("\nName: ");		
		cin>>name;
		printf("Salary: ");
		cin>>salary;
		next=NULL;
	}
	string getname()
	{
		return name;
	}
	float getsalary()
	{
		return salary;
	}
	void setname(string name)
	{
		this->name=name;
	}
	void setsalary(float a)
	{
		this->salary=a;
	}
	void print()
	{
		cout<<name<<endl<<salary<<endl;
	}
};
class oper_EMP:EMP
{
private:
	EMP *star,*end,*p;
public:
	oper_EMP()
	{
		star=end=p=NULL;
	}
	void add()
	{
		p=(EMP *)new EMP(0);
		if(star==NULL)
			star=p;
		else
			end->next=p;
		end=p;
	}
	void save()
	{
		p=star;
		if(p==NULL)
		{
			printf("\nEnter employee data before trying to save");
			return;
		}
		ofstream fout;//�����ļ�ָ��
		fout.open("emp.txt",ios_base::out|ios_base::app); //���ļ�Ϊ׷��д��
		//cout<<sizeof(this)<<endl;
		while(p!=NULL)
		{
			fout.write((char *) &p,sizeof(p));
			p=p->next;
		}
		fout.close();//�ر��ļ�
		printf("\nFile saved\n");
	}
	
	void P()
	{
		p=star;
		if(p==NULL)
		{
			printf("\nEnter employee data before trying to save");
			return;
		}
		while(p!=NULL)
		{
			p->print();
			p=p->next;
		}
	}
	void print_help()
	{
		printf("\nn - New\ns - Save\nl - List\nq - Quit");
	}
	void find()
	{
		printf("Enter employee name: ");
		string name;
		cin>>name;
		p=star;
		while(p!=NULL)
		{
			if(p->getname()==name)
			{p->print();return;}
			p=p->next;
		}
		printf("Record not found.");
	}
	void del()
	{
		printf("Enter employee name: ");
		string name;
		cin>>name;
		EMP *pf;
		pf=star;p=star;
		while(p!=NULL)
		{
			if(p->getname()==name)
			{
				printf("Are you sure to delete this employee(Y/N)\n");
				char ch=getch();
				if(ch!='Y'||ch!='y')
					return;
				if(p==star)
				{star=star->next;delete(p);return;}
				if(p==end)
				{end=pf;delete(p);return;}
				pf->next=p->next;save();
				return;
			}
			pf=p;
			p=p->next;
		}
		printf("Record not found.");
	}
	void change()
	{
		printf("Enter employee name: ");
		string name,new_name;
		float new_sal;
		cin>>name;
		p=star;
		while(p!=NULL)
		{
			if(p->getname()==name)
			{
				printf("Are you sure to change this employee(Y/N)\n");
				char ch=getch();
				if(ch!='Y'||ch!='y')
					return;
				printf("Enter new name: ");
				cin>>new_name;
				printf("Enter new salary: ");
				cin>>new_sal;
				p->setname(new_name);
				p->setsalary(new_sal);
			}
			p=p->next;
		}
		printf("Record not found.");
	}
};
int main()
{
	oper_EMP a;
	while(1)
	{
		char c;
		c=getch();
		switch(c)
		{
		case 'n':a.add();break;
		case 's':a.save();break;
		case 'l':a.P();break;
		case 'h':a.print_help();break;
		case 'q':return 0;
		case 'f':a.find();break;
		case 'd':a.del();break;
		case 'e':a.change();break;
		default :printf("press h to ask help\n");break;
		}
	}
	return 0;
}
	