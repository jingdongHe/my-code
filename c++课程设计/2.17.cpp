/*������17. �о�������¼ȡ
��������������
�������о������Կγ�Ϊ4�ţ�������ѧ���������Ϊͳһ���⣬��רҵ����������ݲ�ͬ��רҵ������ѧУ�������⡣
���ҶԳ���¼ȡ�������ܷ�Ҫ����ĳһ��Ҫ��4�ſ��ܷ�Ӧ�ﵽ310�֣���
���⻹�ж�ÿ�ſε���ͷ���Ҫ�����ܷ�Ϊ100���Ծ����Ӧ�ﵽ40�֣��ܷ�Ϊ150���Ծ����Ӧ�ﵽ65�֣���
���ͳ�Ƴ��Ժϸ�������������ܷ��ɸߵ��͵�˳������ϸ�������Ϣ��
����������Ҫ��
��������������ʱ����Ҫ�����룺����������׼��֤�ţ�����רҵ���Ƿ�Ӧ������
4�ſγ̣����Ρ���ѧ�����רҵ�����Σ��ɼ�����Щԭʼ����Ӧ���浽һ���ļ��С�
Ȼ�����룺¼ȡ���ܷ�Ҫ�󣬸��γ̵���ͷ���Ҫ�����Ҫ�󣺹��߿�����������׼��֤�ţ�
����רҵ���Ƿ�Ӧ������4�ſγ̣����Ρ���ѧ�����רҵ�����Σ��ɼ����ܷ֣���Щ��ϢӦ��ŵ���һ���ļ��С�
��������������
����������Ӧ���벻����10����������Ϣ������Ӧ�������������ֱ�����������
���Ҷ��кϸ�Ͳ��ϸ�������
������ʵ����ʾ
�������ɶ���һ�����������й���Ϣ��ʵ����Ӧ�Ĳ�����
���������ݣ��ܷ�Ҫ��͸��ſγ̵�Ҫ�󣩿ɶ��������������ţ���Ӧ�ܱ������༰��������ֱ�ӷ��ʡ�*/
#include<stdio.h>
#include<math.h>
#include<string>
#include<fstream>
#include<iostream>
#include<queue>
using namespace std;
ofstream fout("2.17.output.txt");
class sorce{//�ɼ��࣬��������ɼ�
private:
	double math,english,political;
	double other;
	double total;
public:
	//��ʼ��
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
class student : sorce {//ѧ���࣬���ڱ����������Ϣ�ͳɼ�
private:
	double math,english,political;
	double other,total2;
	string name,number,major,graduate;
//	bool ;
public:
	student()
	{
	}
	//���ַ���ת��Ϊ������
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
		//���ļ�����������ʽ��������
		//a 04120801 �� �� 80.1 80.2 80.0 80.3
		//������һ���ո����ʾһ�����ݵĽ�����case 3 ���ʾ���������ݣ�Ҳ����רҵ��
		//�����ַ���ӵ�һ���յ��ַ����У�ֱ�������ո����ַ����ĳ������Ľ��������רҵ
		//��һ����Ϣ����������֮����ó������е�������
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
		//�Գ�Ա�ĳ�ʼ��
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
	bool is_ok()//���������жϸ����Ƿ��������
	{
		if(sorce::get_total()>this->total())
			return false;
		if(sorce::get_political()>this->political||sorce::get_math()>this->math||sorce::get_english()>this->english||sorce::get_other()>this->other)
			return false;
		return true;
	}
	void show()
	{
		cout<<name<<" ��ѧ���� "<<number<<"\n����רҵ�� "<<major<<"\n�Ƿ��Ǳ�ҵ�� "<<graduate<<"\n���γɼ��� "<<political<<" ��ѧ�ɼ��� "<<math<<" Ӣ��ɼ��� "<<english<<" רҵ�γɼ��� "<<other<<endl;
	}
	void fshow()//��ӡ���ļ���
	{
		fout<<name<<" ��ѧ���� "<<number<<"\n����רҵ�� "<<major<<"\n�Ƿ��Ǳ�ҵ�� "<<graduate<<"\n���γɼ��� "<<political<<" ��ѧ�ɼ��� "<<math<<" Ӣ��ɼ��� "<<english<<" רҵ�γɼ��� "<<other<<endl;
	}
};
struct cmp{//�������ȶ��е�����
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
	printf("����������ܷ֣�������η����������ѧ���������������������רҵ����\n");
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