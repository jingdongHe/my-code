/*������19. �����˻��������
��������
���һ�������˻���������˻�����Ϣ���˺ţ�Ψһ���������������֤���롢��λ���绰���롢��ַ�ȣ�
�����û��������²�������������������ȡ�ת�ˡ���ѯ��һ���û������ж����ͷ���˻�����ֵû�����ޡ�
����Ҫ��
��������ʱ���������û�ѡ����к��ֲ�������������Ҫ�������û���Ϣ���Զ���ȡ�˺ţ��û��������˺ű����գ�
���Ҹ��˺ſ��Լ�������������˻����������û�͸֧�������������˺ſ��Խ����û�����Ϣ��ѯ��
���е��˻���ϢӦ��ŵ�һ���ļ��У�������ʱ�ķ��ʺ͸��¡�
��������
����Ӧ���벻����10�˵��˻���Ϣ��Ӧ���ǵ���Աͬ���������
ʵ����ʾ
�ɶ���һ���˻������˻���Ϣ�Լ�ִ����Ӧ�Ĳ�����������һ���������������˻���*/
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
			printf("����\n");
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
		
		printf("��������û������������֤�ţ��绰���룬��ַ\n");
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
			printf("��������Ҫ�������˺�\n");
			int number;
			cin>>number;k=number;
			p=head->next;pf=head;
			while(p!=NULL)
			{
				if(p->getnumber()==number)
					return;
				pf=p;p=p->next;
			}
			printf("���ʺŲ�����,����������\n");
		}
	}
	void del()
	{
		pf->next=p->next;delete(p);	p=NULL;
	}
	void deposit()
	{
		printf("����������\n");
		double money;
		cin>>money;
		p->deposit(money);
	}
	void draw()
	{
		printf("������ȡ����\n");
		double money;
		cin>>money;
		p->draw(money);
	}
	void check()
	{
		printf("�������Ϊ%lf\n",p->check());
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
		printf("�������������\n");
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
		printf("���û�������\n");
	}
	account * find(int number)
	{
		if(number>d||number<0)
		{
			printf("���ʺŲ�����\n");
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
					printf("���ʺŲ�����\n");
					return NULL;
				}
				else 
					return p_account[m];
			}
		}
	}
	void transfer()
	{
		printf("������ת�˵��˻�\n");
		int number;
		cin>>number;
		account *ip,*op;
		ip=find(number);
		if(ip==NULL)
			return;
		printf("������ת����˻�\n");
		cin>>number;
		op=find(number);
		if(op==NULL)
			return;
		printf("������ת�˽��\n");
		double money;
		cin>>money;
		if(!ip->draw(money))
		{printf("ȡ��ɹ�\n");return;}
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
		printf("1�����û�    2��ѡ���û�����     3��ת��    0���˳�\n");
		ch=getch();
		if(ch=='1') a.new_preson();
		if(ch=='2')
		{
			a.chose();
			
			char ch1;
			while(1)
			{
				printf("���������:  1������    2��ѡ���˻�����      3����ʾ��Ϣ    0���˳�\n");
				ch1=getch();
				if(ch1=='1')
					a.p->open();
				if(ch1=='2')
				{
					a.p->chose();
					
					char ch2;
					while(1)
					{
						printf("���������: 1��ȡ��   2�����   3��ɾ�����˻�   0���˳�\n");
						ch2=getch();
						if(ch2=='1')
						{
							printf("������ȡ����Ŀ\n");
							int money;
							cin>>money;
							a.p->p->draw(money);
						}
						if(ch2=='2')
						{
							printf("����������Ŀ\n");
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
