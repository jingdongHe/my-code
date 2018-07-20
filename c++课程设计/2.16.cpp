/*16．商品销售统计
问题描述
编写商品销售统计程序，商品的信息有：商品的名称，计量单位（重量或件），单价。所有商品的信息事先已存入计算机，
屏幕上显示所有商品的名称，选择商品名，输入商品计量单位(如重量，件数等)，根据单价算出总价。客户一次购物可能购买多种商品，程序应计算出客户应付的钱款数。
基本要求
程序分为两个部分：第一部分用于输入商品的信息并允许修改和删除；第二部分实现销售统计。
程序运行时由用户选择进入哪一部分功能，并能在运行时在两部分之间切换。第二部分运行时，
首先显示所有商品名称及代码（商品数目较多时，应考虑分屏显示），用户输入商品代码及商品重量或件数，
用户一次操作可输入若干商品的购买信息，然后输入一个特殊的代码（如-1）表示本次购物结束。此时。程序计算出应付钱款数并显示。
测试数据
程序应输入不少于10种商品的信息，并进行模拟运行。
实现提示
本程序的商品信息管理可采用与课程设计题目二类似的数据结构，既定义一个商品类，每种商品作为商品类的实例（对象）存储在链表节点中。
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
		cout<<"物品名称是 "<<name<<endl<<" 计量单位是 "<<price<<endl<<" 单价是 "<<danwei<<endl;
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
		printf("请输入物品信息，包括物品名，计量单位和单价\n");
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
		printf("你想要删除什么物品？\n");
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
		printf("抱歉，没有这件物品\n");
	}
	void change()
	{
		printf("你想要修改什么物品的属性？\n");
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
			printf("请输入你想要买的物品(-1:exit)\n");
			string name;cin>>name;
			if(name[0]=='-'&&name[1]=='1')
				return;
			p=all->Find(name);
			double price;int shuliang,danwei;
			price=p->get_price();danwei=p->get_danwei();
			printf("你想要多少？\n");
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
		printf("1、goods operation    2、shopping    0、exit\n");
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

