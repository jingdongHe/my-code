/*　　　5、工资管理
	这是一个员工工资管理程序。工资管理的数据文件中存储有员工姓名和工资，该程序可以录入、显示、修改、删除、查找员工的姓名和工资。
	改进要求：
	1、用类的形式改写程序，将程序中的工资数据用链表的形式存放，定义一个链表类，封闭主要的操作函数。
	2、显示、修改、删除数据项是大小写通用。
	3、工资数据按工资值的大小进行排序存放。
	4、修改、删除数据前增加提示信息，用户确认后才能进一步操作，否则操作取消。
	5、增加程序的文件输出输入功能，在执行程序中首先将工资数据从文件中读出再进行管理，在程序结束时能将工资数据保存在原文件中。*/
#include <stdio.h>
#include <conio.h>//此处的输入输出等头文件改用c++标准
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
	EMP(int i)//构造函数，输入员工信息
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
		ofstream fout;//创建文件指针
		fout.open("emp.txt",ios_base::out|ios_base::app); //打开文件为追加写入
		//cout<<sizeof(this)<<endl;
		while(p!=NULL)
		{
			fout.write((char *) &p,sizeof(p));
			p=p->next;
		}
		fout.close();//关闭文件
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
	