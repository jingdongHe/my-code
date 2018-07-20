/*������18. ������������
��������������
�������������������ͳ�˫ѭ�����ƣ�ʤһ����3�֣�ƽ�ָ���1�֣�
��һ����0�֣����������Ի��ֶ�����ǰ�������ӣ����ӣ�������ͬʱ��
��ʤ�򣨼���������ʧ����֮�������ǰ������ʤ����ͬ���������������ǰ��
������ͬ�����ǩ���߸������������Σ�����������������У�����δ�������������β��У�
���������ⷽ��Ҫ�󣩡��Ա�һ����ͳ�����һ�ֱ����󣬸��ӻ��ּ�������
����������Ҫ��
����������ֱ�ṹ���£�������������15���ַ������ѱ����ĳ�����Ӯ�ĳ�����ƽ�ĳ�����
���ĳ�������������ʧ���������֡����ֱ���������ļ��С����һ�ֵĽ���Ӽ�������
������ʽΪ�������������ô��룩���Ͷ��������ô��룩�����ӵ÷֣��������������Ͷӵ÷֣�������������
����Ӧ���ݴ��ֽ���޸ĸ��ӵĻ��ֺ����Σ����õ����¼Ƿֱ�����ԭ�����ļ��в�ͬʱ����Ļ����ʾ��
��������������
��������ѡ���ҹ�����ļ�A���B�������������룬������뱨�¹����������Ƿ�һ�¡�
������ʵ����ʾ
����������һ������࣬ÿ������Ǿ��Ǵ���Ķ������������в����Ķ������ǹ̶��ģ�
��˿��ö���������ʵ�֣���ȻҲ����������ṹ����ÿ���������ӵı����ɼ���
����Ӧ�Ķӵ��й����ݣ�����������Ӯ�ĳ�����ƽ�ĳ��������ĳ�������������ʧ���������ֵȣ����ɽ����޸ģ�
�����ɼ�¼����ɣ������������򷽷�������������Ϊ�������ų����β������*/
#include<iostream>
#include<queue>
#include<string>
#include<vector>
using namespace std;
class team {
private:
	string name;
	int changshu,win,equ,lose,goal,funble,integrat;
public:
	team()
	{
		changshu=0;
		win=equ=lose=0;
		goal=funble=0;
		integrat=0;
		name="";
	}
	int getintegrat()
	{
		return integrat;
	}
	int getgoal()
	{
		return goal;
	}
	int getfunble()
	{
		return funble;
	}
	team(string name):name(name)
	{
		changshu=0;
		win=equ=lose=0;
		goal=funble=0;
		integrat=0;
	}
	void setname(string name)
	{
		this->name=name;
	}
	void updata(int in,int res,int out)
	{
		changshu++;
		goal+=in;
		funble+=out;
		if(res==0)
		{integrat+=1;equ++;}
		else if(res==1)
		{integrat+=3;win++;}
		else
			lose++;
	}
	string getname()
	{
		return name;
	}
	void show()
	{	
		cout<<"----------------------\n";
		cout<<"�����:"<<name;
		cout<<"  "<<"����:"<<integrat<<"  "<<"����:"<<changshu<<endl;
		cout<<"ʤ��:"<<win<<"  "<<"ƽ��:"<<equ<<"  "<<"�ܳ�:"<<lose<<endl;
		cout<<"������:"<<goal<<"  "<<"ʧ����:"<<funble<<endl;
		cout<<"----------------------\n\n";
	}
	
};
class football_team {
private:
	team football[32];
public:
	void setname1()
	{
		for(int i=0;i<32;i++)
		{
			string a="";
			a+=i+'a';
			football[i].setname(a);
		}
	}
	void setname2()
	{
		for(int i=0;i<32;i++)
		{
			string a;
			cin>>a;
			football[i].setname(a);
		}
	}
	void information()
	{
		printf("\n-----------------------------------------------------\n");
		for(int i=0;i<32;i++)
		{
			printf("%2d",i);cout<<":"<<football[i].getname()<<"  ";
			if((i+1)%8==0)
				cout<<endl;
		}
		printf("\n-----------------------------------------------------\n");
	}
	void sorce(int team_a,int team_b,int goal_a,int goal_b)
	{
		int i,j;
		if(goal_a>goal_b)
		{i=1;j=-1;}
		else if(goal_a<goal_b)
		{i=-1;j=1;}
		else
			i=j=0;
		football[team_a].updata(goal_a,i,goal_b);
		football[team_b].updata(goal_b,j,goal_a);
	}
	struct cmp{
		//���������Ի��ֶ�����ǰ�������ӣ����ӣ�������ͬʱ��
		//��ʤ�򣨼���������ʧ����֮�������ǰ������ʤ����ͬ���������������ǰ��
		bool operator () (team &a,team &b)
		{
			if(a.getintegrat()==b.getintegrat())
			{
				int a1=a.getgoal()-a.getfunble(),b1=b.getgoal()-b.getfunble();
				if(a1==b1)
				{
					return a.getgoal()<b.getgoal();
				}
				return a1<b1;
			}
			return a.getintegrat()<b.getintegrat();
		}
	};
	void Show()
	{
		priority_queue<team,vector<team>,cmp> Q;
		for(int i=0;i<32;i++)
			Q.push(football[i]);
		while(!Q.empty())
		{
			team q;
			q=Q.top();
			Q.pop();
			q.show();
		}
	}
};
int main()
{
	football_team a;
	a.setname1();
	a.information();
	int team_a,team_b,goal_a,goal_b;
	while(1)
	{
		printf("�����������(��0 0 0 0����)\n");
		scanf("%d%d%d%d",&team_a,&team_b,&goal_a,&goal_b);
		if(team_a==team_b&&team_a==0&&goal_a==team_a&&goal_b==team_a)
			break;
		a.sorce(team_a,team_b,goal_a,goal_b);
		system("cls");
		a.information();
		a.Show();
	}
	return 0;
}
