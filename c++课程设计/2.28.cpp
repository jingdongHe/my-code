/*28.班级人事管理系统
功能要求：
（1） 设计一个人事管理的People（人员）类。
考虑到通用性，这里只抽象出所有类型人员都具有的属性：name（姓名），number（编号），birthday（出生日期），id（身份证号）等等。
其中"出生日期"定义为一个"日期"类（具有属性）：year（年），month（月），date（日）内嵌子对象。
用成员函数实现对人员信息的录入和显示等必要的功能操作（自己独立思考设计）。要求包括：构造函数和析构函数，拷贝构造函数，内联成员函数。 
（2） 从people（人员）类派生出student（学生）类，
添加属性：班号 char chassNO；从people（人员）类派生出student（学生）类，添加属性：职务 char principalship，部门 char department；.
从 student类中派生出graduate（研究生）类，添加属性：专业 char subject，导师 teacher adviser（为（教师类内嵌子对象））;从graduate类和 
teacher类派生出TA（助教生）类，注意虚基类的使用，重载相应的成员函数。 
（3） 对people类重载"= ="运算符和"="运算符，"= ="运算符判断两个people类对象的id属性是否相等；"="运算符实现people类对象的赋值操作。 
（4） 定义一个对people类对象数组按编号排序的函数，一个按编号查找people对象的函数。
*/
#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
class Day {
private :
	int year,month,day;
public:
	Day(int year,int month,int day):year(year),month(month),day(day)
	{
		//printf("日期.......\n");
	}
	void show()
	{
		cout<<"出生日期为:";
		cout<<year<<"."<<month<<"."<<day<<" ";
	}
};
class people {
private:
	string name,number,id;
	Day *birthday;
public:
	people ()
	{
		//printf("人.......\n");
		printf("请输入用户信息，包括姓名，编号，身份证号\n");
		cin>>name>>number>>id;
		int year,month,day;
		printf("请输入该用户的出生日期\n");
		cin>>year>>month>>day;
		birthday=(Day *)new Day(year,month,day);
		printf("用户信息录入完毕\n");
	}
	people (string name)
	{
		//printf("人.......\n");
		this->name=name;
		printf("请输入用户信息，包括编号，身份证号\n");
		cin>>number>>id;
		int year,month,day;
		printf("请输入该用户的出生日期\n");
		cin>>year>>month>>day;
		birthday=(Day *)new Day(year,month,day);
		printf("用户信息录入完毕\n");
	}
	void set(string name,string number,string id,Day *birthday)
	{
		this->name=name;this->number=number;this->id=id;
		this->birthday=birthday;
	}
	string getname()
	{
		return name;
	}
	string getid()
	{
		return id;
	}
	Day *getday()
	{
		return birthday;
	}
	string getnumber()
	{
		return number;
	}
	virtual void show()
	{
		cout<<"姓名:"<<name<<" "<<"编号:"<<number<<" ";
		birthday->show();
		cout<<" "<<"身份证号:"<<id<<endl;
	}
	bool operator == (people a)
	{
		//cout<<a.getnumber()<<" "<<getnumber()<<endl;
		if(number==a.getnumber())
			return true;
		return false;
	}
	operator = (people b)
	{
		set(b.getname(),b.getnumber(),b.getid(),b.getday());
	}
};
class teacher :virtual public people{
private:
	string major;
public:
	teacher()
	{
	//	printf("教师.......\n");
		printf("教授专业为\n");
		cin>>major;
		printf("教师信息录入完毕\n");
	}
	teacher(string name):people(name)
	{
	//	printf("教师.......\n");
		printf("教授专业为\n");
		cin>>major;
		printf("教师信息录入完毕\n");
	}
	virtual void show()
	{
		people::show();
		cout<<"教授专业为:"<<major<<endl;
	}
	void teacher_show()
	{
		cout<<"教授专业为:"<<major<<endl;
	}
};
class student : virtual public people{
private:
	string classNO,principalship,department;
public:
	student()
	{
		//printf("学生.........\n");
		printf("请输入学生所在教室，职位以及部门\n");
		cin>>classNO>>principalship>>department;
		printf("学生信息录入完毕\n");
	}
	virtual void show()
	{
		people::show();
		cout<<"教室编号:"<<classNO<<" "<<"职位:"<<principalship<<" "<<"部门:"<<department<<endl;
	}
};
class graduate :virtual public student {
private:
	string subject;
	teacher *teacher_adviser;
public:
	graduate()
	{
		//printf("研究生.........\n");
		printf("请输入专业以及导师姓名\n");
		string name;
		cin>>subject>>name;
		teacher_adviser=(teacher *)new teacher(name);
		printf("研究生信息录入完毕\n");
	}
	virtual void show()
	{
		student::show();
		cout<<"专业:"<<subject<<endl;
		printf("该生导师为\n");
		teacher_adviser->show();
	}
};
class TA :public graduate,public teacher {
private:
	double money;
public:
	TA()
	{
		//printf("助教.........\n");
		printf("请输入助教的工资\n");
		cin>>money;
		printf("助教信息录入完毕\n");
	}
	virtual void show()
	{
		teacher::teacher_show();graduate::show();
		cout<<"助教工资:"<<money<<endl;
	}
};
bool cmp(people *a,people *b)
{
	return a->getnumber()<b->getnumber();
}
people *find(people *p[],int n,string number)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(p[i]->getnumber()==number)
			return p[i];
	}
	return NULL;
}
int main()
{
	people *p[10];
	student b;
	teacher c;
	p[0]=&b;p[1]=&c;
	/**p=*p1;
	p->show();*/
	/*if(*p==*p1)
		printf("YES\n");
	else
		printf("NO\n");*/
	/*sort(p,p+10,cmp);*/
	/*string number;
	printf("请输入查询编号\n");
	cin>>number;
	people *k=find(p,10,number);
	k->show();*/
	return 0;
}
