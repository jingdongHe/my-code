/*16����Ʒ����ͳ��
��������
��д��Ʒ����ͳ�Ƴ�����Ʒ����Ϣ�У���Ʒ�����ƣ�������λ����������������ۡ�������Ʒ����Ϣ�����Ѵ���������
��Ļ����ʾ������Ʒ�����ƣ�ѡ����Ʒ����������Ʒ������λ(��������������)�����ݵ�������ܼۡ��ͻ�һ�ι�����ܹ��������Ʒ������Ӧ������ͻ�Ӧ����Ǯ������
����Ҫ��
�����Ϊ�������֣���һ��������������Ʒ����Ϣ�������޸ĺ�ɾ�����ڶ�����ʵ������ͳ�ơ�
��������ʱ���û�ѡ�������һ���ֹ��ܣ�����������ʱ��������֮���л����ڶ���������ʱ��
������ʾ������Ʒ���Ƽ����루��Ʒ��Ŀ�϶�ʱ��Ӧ���Ƿ�����ʾ�����û�������Ʒ���뼰��Ʒ�����������
�û�һ�β���������������Ʒ�Ĺ�����Ϣ��Ȼ������һ������Ĵ��루��-1����ʾ���ι����������ʱ����������Ӧ��Ǯ��������ʾ��
��������
����Ӧ���벻����10����Ʒ����Ϣ��������ģ�����С�
ʵ����ʾ
���������Ʒ��Ϣ����ɲ�����γ������Ŀ�����Ƶ����ݽṹ���ȶ���һ����Ʒ�࣬ÿ����Ʒ��Ϊ��Ʒ���ʵ�������󣩴洢������ڵ��С�
*/
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
class goods {  
private:
	string name;
	int danwei;
	double price;
public:
	goods *next;
	goods(string name,double price,int danwei)
	{
		this->name=name;
		this->price=price;
		this->danwei=danwei;
		next=NULL;
	}
	goods()
	{
	}
	void show()
	{
		cout<<"��Ʒ������ "<<name<<endl<<" ������λ�� "<<price<<endl<<" ������ "<<danwei<<endl;
	}
	double get_price()
	{
		return price;
	}
	string get_name()
	{
		return name;
	}
	int get_danwei()
	{
		return danwei;
	}
};
class all_goods :goods{
private:
	goods *star,*end,*p,*pf;
public:
	all_goods()
	{
		star=NULL;
	}
	void Show()
	{
		bool head_used=false;
		p=star;
		if(star==end)
		{
			p->show();
			return;
		}
		while(p!=end||head_used)
		{
			p->show();
			if(p==end)
				return;
			p=p->next;
			if(p==end)
				head_used=true;
		}
	}
	goods *Find(string name)
	{
		bool head_used=false;
		p=star;
		while(p!=end||head_used)
		{
			if(p->get_name()==name)
				return p;
			if(p==end)
				break;
			p=p->next;
			if(p==end)
				head_used=true;
		}
		return NULL;
	}
	void add()
	{
		printf("��������Ʒ��Ϣ��������Ʒ����������λ�͵���\n");
		string name;double price;int danwei;
		cin>>name>>price>>danwei;
		goods *p=(goods *)new goods(name,price,danwei);
		if(star==NULL)
			star=p;
		else
			end->next=p;
		end=p;
	}
	void del()
	{
		printf("����Ҫɾ��ʲô��Ʒ��\n");
		string name;bool head_used=false;
		cin>>name;
		p=star;pf=p;
		while(p!=end||head_used)
		{
			if(p->get_name()==name)
			{
				p->show();
				if(p==star)
				{
					star=star->next;
					delete(p);
					return;
				}
				if(p==end)
					end=pf;
				pf->next=p->next;
				delete(p);
				return;
			}
			pf=p;
			if(p==end)
				return;
			p=p->next;
			if(p==end)
				head_used=true;
		}
		printf("��Ǹ��û�������Ʒ\n");
	}
	void change()
	{
		printf("����Ҫ�޸�ʲô��Ʒ�����ԣ�\n");
		string name;bool head_used=false;
		cin>>name;goods *px;
		p=star;pf=p;
		while(p!=end||head_used==false)
		{
			if(p->get_name()==name)
			{
				printf("Please entry the new informations(price and danwei)\n");
				double price;int danwei;
				cin>>price>>danwei;
				px=(goods *)new goods(name,price,danwei);
				if(p==star)
				{
					px->next=star->next;
					star=px;
					delete(p);
					return;
				}
				if(p==end)
					end=px;
				pf->next=px;px->next=p->next;
				free(p);
				return;
			}
			pf=p;
			if(p==end)
				return;
			p=p->next;
			if(p==end)
				head_used=true;
		}
	}
};
class buy {
private:
	double money;
	all_goods *all;
public :
	buy()
	{
		money=0;
	}
	void Buy(all_goods a)
	{
		all=&a;
		all->Show();
		goods *p;
		while(1)
		{
			printf("����������Ҫ�����Ʒ(-1:exit)\n");
			string name;cin>>name;
			if(name[0]=='-'&&name[1]=='1')
				return;
			p=all->Find(name);
			double price;int shuliang,danwei;
			price=p->get_price();danwei=p->get_danwei();
			printf("����Ҫ���٣�\n");
			cin>>shuliang;
			money+=price*shuliang*1.0/danwei;
		}
	}
	void How_much()
	{
		printf("%lf\n",money);
	}
};
int main()
{
	int d;
	all_goods operat;
	buy shopping;
	while(1)
	{
		printf("1��goods operation    2��shopping    0��exit\n");
		scanf("%d",&d);
		while(d==1)
		{
			printf("1:add   2:change   3:show   4:delete    0:exit\n");
			int f;
			scanf("%d",&f);
			if(f==1)
				operat.add();
			else if(f==2)
				operat.change();
			else if(f==3)
				operat.Show();
			else if(f==4)
				operat.del();
			else
				break;
		}
		while(d==2)
		{
			//operat.Show();
			//shopping.goin(operat);
			printf("1:buy   2:checkout   0:exit\n");
			int f;
			scanf("%d",&f);
			if(f==1)
				shopping.Buy(operat);
			else if(f==2)
				shopping.How_much();
			else
				break;
		}
		if(d==0)
			break;
	}
	return 0;
}

