/*　　　17. 研究生初试录取
　　　问题描述
　　　研究生考试课程为4门，其中数学、外语、政治为统一命题，而专业基础课则根据不同的专业由招生学校自行命题。
国家对初试录取分数有总分要求（如某一年要求4门课总分应达到310分），
另外还有对每门课的最低分数要求（如总分为100的试卷最低应达到40分，总分为150的试卷最低应达到65分）。
编程统计初试合格的人数，并按总分由高到低的顺序输出合格考生的信息。
　　　基本要求
　　　程序运行时首先要求输入：考生姓名，准考证号，报考专业，是否应届生，
4门课程（政治、数学、外语、专业基础课）成绩。这些原始数据应保存到一个文件中。
然后输入：录取的总分要求，各课程的最低分数要求。输出要求：过线考生的姓名，准考证号，
报考专业，是否应届生，4门课程（政治、数学、外语、专业基础课）成绩及总分，这些信息应存放到另一个文件中。
　　　测试数据
　　　程序应输入不少于10名考生的信息，其中应届生和历届生分别有若干名，
并且都有合格和不合格的情况。
　　　实现提示
　　　可定义一个考生类存放有关信息和实现相应的操作。
分数线数据（总分要求和各门课程的要求）可定义另外的类来存放，但应能被考生类及其派生类直接访问。*/
#include<stdio.h>
#include<math.h>
#include<string>
#include<fstream>
#include<iostream>
#include<queue>
using namespace std;
ofstream fout("2.17.output.txt");
class sorce{//成绩类，用来保存成绩
private:
	double math,english,political;
	double other;
	double total;
public:
	//初始化
	sorce(double political,double math,double english,double other,double total):political(political),math(math),english(english),other(other),total(total)
	{
	}
	double get_political()
	{return political;}
	double get_math()
	{return math;}
	double get_english()
	{return english;}
	double get_other()
	{return other;}
	double get_total()
	{return total;}
	sorce()
	{
	}
};
class student : sorce {//学生类，用于保存该生的信息和成绩
private:
	double math,english,political;
	double other,total2;
	string name,number,major,graduate;
//	bool ;
public:
	student()
	{
	}
	//将字符串转化为浮点数
	double change(string a)
	{
		double d=0;
		int i,k;
		for(i=0;i<a.size();i++)
		{
			if(a[i]=='.')
				break;
			d=d*10+(a[i]-'0');
		}
		k=i;i++;
		for(i;i<a.size();i++)	
			d+=(a[i]-'0')*pow(10,k-i);
		return d;
	}
	student(string information,double total1,double political1,double math1,double english1,double other1):sorce(political1,math1,english1,other1,total1)
	{	
		string name="",number="",major="",graduate="",political="",math="",english="",other="";
		int i=0,f=0;;
		//在文件中以这种形式保存数据
		//a 04120801 软工 是 80.1 80.2 80.0 80.3
		//当遇到一个空格，则表示一个数据的结束，case 3 则表示第三个数据，也就是专业。
		//将其字符添加到一个空的字符串中，直到遇到空格，则字符串的出的最后的结果即是其专业
		//当一行信息都被遍历完之后，则得出其所有的数据项
		while(i<information.size())
		{
			switch(f)
			{
			case 0:name+=information[i++];if(information[i]==' ') {f++;i++;break;}break;
			case 1:number+=information[i++];if(information[i]==' ') {f++;i++;break;}break;
			case 2:major+=information[i++];if(information[i]==' ') {f++;i++;break;}break;
			case 3:graduate+=information[i++];if(information[i]==' ') {f++;i++;break;}break;
			case 4:political+=information[i++];if(information[i]==' ') {f++;i++;break;}break;
			case 5:math+=information[i++];if(information[i]==' ') {f++;i++;break;}break;
			case 6:english+=information[i++];if(information[i]==' ') {f++;i++;break;}break;
			case 7:other+=information[i++];if(information[i]==' '||information[i]=='\n') {f++;i++;break;}break;
			}
		}
		//对成员的初始化
		this->name=name;
		this->number=number;
		this->major=major;
		this->graduate=graduate;
		this->political=change(political);
		this->math=change(math);
		this->english=change(english);
		this->other=change(other);
	}
	double total()
	{
		return total2=math+english+political+other;
	}
	double get_total2()
	{
		return total2;
	}
	bool is_ok()//根据题意判断该生是否符合条件
	{
		if(sorce::get_total()>this->total())
			return false;
		if(sorce::get_political()>this->political||sorce::get_math()>this->math||sorce::get_english()>this->english||sorce::get_other()>this->other)
			return false;
		return true;
	}
	void show()
	{
		cout<<name<<" 的学号是 "<<number<<"\n报考专业是 "<<major<<"\n是否是毕业生 "<<graduate<<"\n政治成绩是 "<<political<<" 数学成绩是 "<<math<<" 英语成绩是 "<<english<<" 专业课成绩是 "<<other<<endl;
	}
	void fshow()//打印到文件中
	{
		fout<<name<<" 的学号是 "<<number<<"\n报考专业是 "<<major<<"\n是否是毕业生 "<<graduate<<"\n政治成绩是 "<<political<<" 数学成绩是 "<<math<<" 英语成绩是 "<<english<<" 专业课成绩是 "<<other<<endl;
	}
};
struct cmp{//用于优先队列的排序
	bool operator () (student &a,student &b)
	{
		return a.get_total2()<b.get_total2();
	}
};
int main()
{
	ifstream fin("2.17.input.txt");
	string info;
	double total,political,math,english,other;
	printf("请输入最低总分，最低政治分数，最低数学分数，最低外语分数，最低专业分数\n");
	scanf("%lf%lf%lf%lf%lf",&total,&political,&math,&english,&other);
	priority_queue<student,vector<student>,cmp> Q;
	while(getline(fin,info))
	{
		student s(info,total,political,math,english,other);
		if(s.is_ok())
		{
			Q.push(s);
			//s.show();
		}
	}
	
	while(!Q.empty())
	{
		student s;
		s=Q.top();
		s.show();
		s.fshow();
		Q.pop();
	}
	fin.close();
	fout.close();
	return 0;
}