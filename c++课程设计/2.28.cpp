/*28.�༶���¹���ϵͳ
����Ҫ��
��1�� ���һ�����¹����People����Ա���ࡣ
���ǵ�ͨ���ԣ�����ֻ���������������Ա�����е����ԣ�name����������number����ţ���birthday���������ڣ���id�����֤�ţ��ȵȡ�
����"��������"����Ϊһ��"����"�ࣨ�������ԣ���year���꣩��month���£���date���գ���Ƕ�Ӷ���
�ó�Ա����ʵ�ֶ���Ա��Ϣ��¼�����ʾ�ȱ�Ҫ�Ĺ��ܲ������Լ�����˼����ƣ���Ҫ����������캯���������������������캯����������Ա������ 
��2�� ��people����Ա����������student��ѧ�����࣬
������ԣ���� char chassNO����people����Ա����������student��ѧ�����࣬������ԣ�ְ�� char principalship������ char department��.
�� student����������graduate���о������࣬������ԣ�רҵ char subject����ʦ teacher adviser��Ϊ����ʦ����Ƕ�Ӷ��󣩣�;��graduate��� 
teacher��������TA�����������࣬ע��������ʹ�ã�������Ӧ�ĳ�Ա������ 
��3�� ��people������"= ="�������"="�������"= ="������ж�����people������id�����Ƿ���ȣ�"="�����ʵ��people�����ĸ�ֵ������ 
��4�� ����һ����people��������鰴�������ĺ�����һ������Ų���people����ĺ�����
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
		//printf("����.......\n");
	}
	void show()
	{
		cout<<"��������Ϊ:";
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
		//printf("��.......\n");
		printf("�������û���Ϣ��������������ţ����֤��\n");
		cin>>name>>number>>id;
		int year,month,day;
		printf("��������û��ĳ�������\n");
		cin>>year>>month>>day;
		birthday=(Day *)new Day(year,month,day);
		printf("�û���Ϣ¼�����\n");
	}
	people (string name)
	{
		//printf("��.......\n");
		this->name=name;
		printf("�������û���Ϣ��������ţ����֤��\n");
		cin>>number>>id;
		int year,month,day;
		printf("��������û��ĳ�������\n");
		cin>>year>>month>>day;
		birthday=(Day *)new Day(year,month,day);
		printf("�û���Ϣ¼�����\n");
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
		cout<<"����:"<<name<<" "<<"���:"<<number<<" ";
		birthday->show();
		cout<<" "<<"���֤��:"<<id<<endl;
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
	//	printf("��ʦ.......\n");
		printf("����רҵΪ\n");
		cin>>major;
		printf("��ʦ��Ϣ¼�����\n");
	}
	teacher(string name):people(name)
	{
	//	printf("��ʦ.......\n");
		printf("����רҵΪ\n");
		cin>>major;
		printf("��ʦ��Ϣ¼�����\n");
	}
	virtual void show()
	{
		people::show();
		cout<<"����רҵΪ:"<<major<<endl;
	}
	void teacher_show()
	{
		cout<<"����רҵΪ:"<<major<<endl;
	}
};
class student : virtual public people{
private:
	string classNO,principalship,department;
public:
	student()
	{
		//printf("ѧ��.........\n");
		printf("������ѧ�����ڽ��ң�ְλ�Լ�����\n");
		cin>>classNO>>principalship>>department;
		printf("ѧ����Ϣ¼�����\n");
	}
	virtual void show()
	{
		people::show();
		cout<<"���ұ��:"<<classNO<<" "<<"ְλ:"<<principalship<<" "<<"����:"<<department<<endl;
	}
};
class graduate :virtual public student {
private:
	string subject;
	teacher *teacher_adviser;
public:
	graduate()
	{
		//printf("�о���.........\n");
		printf("������רҵ�Լ���ʦ����\n");
		string name;
		cin>>subject>>name;
		teacher_adviser=(teacher *)new teacher(name);
		printf("�о�����Ϣ¼�����\n");
	}
	virtual void show()
	{
		student::show();
		cout<<"רҵ:"<<subject<<endl;
		printf("������ʦΪ\n");
		teacher_adviser->show();
	}
};
class TA :public graduate,public teacher {
private:
	double money;
public:
	TA()
	{
		//printf("����.........\n");
		printf("���������̵Ĺ���\n");
		cin>>money;
		printf("������Ϣ¼�����\n");
	}
	virtual void show()
	{
		teacher::teacher_show();graduate::show();
		cout<<"���̹���:"<<money<<endl;
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
	printf("�������ѯ���\n");
	cin>>number;
	people *k=find(p,10,number);
	k->show();*/
	return 0;
}
