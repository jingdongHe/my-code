/*　　　19. 银行账户管理程序
问题描述
设计一个银行账户管理程序，账户的信息有账号（唯一）、姓名、余额、身份证号码、单位、电话号码、地址等，
允许用户进行如下操作：开户、销户、存款、取款、转账、查询，一个用户可以有多个户头，账户的数值没有上限。
基本要求
程序运行时，可以由用户选择进行何种操作，开户操作要求输入用户信息后自动获取账号，用户销户后账号被回收，
并且该账号可以继续分配给其它账户，不允许用户透支，根据姓名或账号可以进行用户的信息查询，
所有的账户信息应存放到一个文件中，可以随时的访问和更新。
测试数据
程序应输入不少于10人的账户信息，应考虑到人员同名的情况。
实现提示
可定义一个账户类存放账户信息以及执行相应的操作，可以用一个链表类来管理账户。*/
#include<stdio.h>
#include<string>
#include<iostream>
#include<conio.h> 
using namespace std;
int k=0,d=0;
class account {
private:
	double balance;
	int number;
public:
	account *next;
	account()
	{
		balance=0;
		number=-1;
		next=NULL;
	}
	account (int number)
	{
		balance=0;
		this->number=number;
		next=NULL;
	}
	void show()
	{
		cout<<number<<":\n"<<balance<<" ";
	}
	int getnumber()
	{
		return number;
	}
	void deposit(double money)
	{
		balance+=money;
	}
	bool draw(double money)
	{
		if(balance-money<0)
		{
			printf("余额不足\n");
			return false;
		}
		balance-=money;
		return true;
	}
	double check()
	{
		return balance;
	}
};
account *p_account[1000]={NULL};
class preson  {
private:
	
	string name,id,phone,adress;
public:account *head,*p,*pf;
	preson *next;
	preson(int i)
	{
		head=p=pf=NULL;next=NULL;
	}
	preson()
	{
		
		printf("请输入该用户的姓名，身份证号，电话号码，地址\n");
		cin>>this->name>>this->id>>this->phone>>this->adress;
	}
	string getname()
	{
		return name;
	}
	void show()
	{
		cout<<name<<" "<<id<<" "<<phone<<" "<<adress<<":"<<endl;
		account *pd=head->next;
		while(pd!=NULL)
		{
			pd->show();
			pd=pd->next;
		}
	}
	void open()
	{
		cout<<"11111111111"<<endl;
		if(head==NULL)
			head=(account *)new account();
		head->next=NULL;
		while(p_account[k]!=NULL) {k++;printf("%d\n",k);}
		
		p=(account *) new account(k++);
		if(k>d) d=k;
		p->next=head->next;
		head->next=p;
	}
	void chose()
	{
		while(1)
		{
			printf("请输入需要操作的账号\n");
			int number;
			cin>>number;k=number;
			p=head->next;pf=head;
			while(p!=NULL)
			{
				if(p->getnumber()==number)
					return;
				pf=p;p=p->next;
			}
			printf("该帐号不存在,请重新输入\n");
		}
	}
	void del()
	{
		pf->next=p->next;delete(p);	p=NULL;
	}
	void deposit()
	{
		printf("请输入存款金额\n");
		double money;
		cin>>money;
		p->deposit(money);
	}
	void draw()
	{
		printf("请输入取款金额\n");
		double money;
		cin>>money;
		p->draw(money);
	}
	void check()
	{
		printf("存款的余额为%lf\n",p->check());
	}
	
};
class manger {
private:
	
	
public:
	account *pi,*po;
	preson *head,*p;
	manger()
	{
		head=p=NULL;
		//head->next=p->next=NULL;
	}
	void new_preson()
	{
		if(head==NULL)
			head=(preson *) new preson(0);
		head->next=NULL;
		p=(preson *) new preson();
		p->next=head->next;
		head->next=p;
	}
	void chose()
	{
		printf("请输入你的姓名\n");
		string name;
		cin>>name;
		p=head->next;
		while(p!=NULL)
		{
			if(p->getname()==name)
			{
				return;
			}
		}
		printf("该用户不存在\n");
	}
	account * find(int number)
	{
		if(number>d||number<0)
		{
			printf("该帐号不存在\n");
			return NULL;
		}
		int l=0,r=d,m;
		while(l<r)
		{
			m=(l+r)/2;
			if(m>number)
				r=m;
			if(m<number)
				l=m;
			if(m==number)
			{
				if(p_account[m]==NULL)
				{
					printf("该帐号不存在\n");
					return NULL;
				}
				else 
					return p_account[m];
			}
		}
	}
	void transfer()
	{
		printf("请输入转账的账户\n");
		int number;
		cin>>number;
		account *ip,*op;
		ip=find(number);
		if(ip==NULL)
			return;
		printf("请输入转入的账户\n");
		cin>>number;
		op=find(number);
		if(op==NULL)
			return;
		printf("请输入转账金额\n");
		double money;
		cin>>money;
		if(!ip->draw(money))
		{printf("取款不成功\n");return;}
		else
		{
			op->deposit(money);
		}
	}
};
int main()
{
	manger a;
	char ch;
	
	while(1)
	{
		printf("1、新用户    2、选择用户操作     3、转账    0、退出\n");
		ch=getch();
		if(ch=='1') a.new_preson();
		if(ch=='2')
		{
			a.chose();
			
			char ch1;
			while(1)
			{
				printf("请输入操作:  1、开户    2、选择账户操作      3、显示信息    0、退出\n");
				ch1=getch();
				if(ch1=='1')
					a.p->open();
				if(ch1=='2')
				{
					a.p->chose();
					
					char ch2;
					while(1)
					{
						printf("请输入操作: 1、取款   2、存款   3、删除该账户   0、退出\n");
						ch2=getch();
						if(ch2=='1')
						{
							printf("请输入取款数目\n");
							int money;
							cin>>money;
							a.p->p->draw(money);
						}
						if(ch2=='2')
						{
							printf("请输入存款数目\n");
							int money;
							cin>>money;
							a.p->p->deposit(money);
						}
						if(ch2=='3')
							a.p->del();
						if(ch2=='0')
							break;
					}
				}
				if(ch1=='0')
					break;
				if(ch1=='3')
					a.p->show();
			}
		}
		if(ch=='3')
			a.transfer();
		if(ch=='0')return 0;
	}
	return 0;
}
