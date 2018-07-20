/*　　　18. 足球联赛积分
　　　问题描述
　　足球联赛采用主客场双循环赛制，胜一场得3分，平局各得1分，
负一场得0分，联赛排名以积分多者在前，当两队（或多队）积分相同时，
则净胜球（即进球数与失球数之差）多者在前，若净胜球相同，则进球数多者在前，
若仍相同，则抽签或踢附加赛决定名次（这在联赛结束后进行，联赛未结束则两队名次并列，
本程序不做这方面要求）。试编一程序统计最近一轮比赛后，各队积分及排名。
　　　基本要求
　　　设积分表结构如下：队名（不超过15个字符），已比赛的场数，赢的场数，平的场数，
负的场数，进球数，失球数，积分。积分表放在正文文件中。最近一轮的结果从键盘输入
，其形式为：主队名（可用代码），客队名（可用代码），主队得分（即进球数），客队得分（即进球数）。
程序应根据此轮结果修改各队的积分和名次，所得的最新记分表仍在原积分文件中并同时在屏幕上显示。
　　　测试数据
　　　可选择我国当年的甲A或甲B联赛的数据输入，并检查与报章公布的数据是否一致。
　　　实现提示
　　　定义一个球队类，每个球队是均是此类的对象。由于联赛中参赛的队伍数是固定的，
因此可用对象数组来实现（当然也可以用链表结构）。每输入两个队的比赛成绩，
则相应的队的有关数据（比赛场数，赢的场数，平的场数，负的场数，进球数，失球数，积分等）即可进行修改，
比赛成绩录入完成，调用联赛排序方法（对象数组作为参数）排出名次并输出。*/
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
		cout<<"球队名:"<<name;
		cout<<"  "<<"积分:"<<integrat<<"  "<<"场数:"<<changshu<<endl;
		cout<<"胜场:"<<win<<"  "<<"平局:"<<equ<<"  "<<"败场:"<<lose<<endl;
		cout<<"进球数:"<<goal<<"  "<<"失球数:"<<funble<<endl;
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
		//联赛排名以积分多者在前，当两队（或多队）积分相同时，
		//则净胜球（即进球数与失球数之差）多者在前，若净胜球相同，则进球数多者在前，
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
		printf("请输入对阵结果(以0 0 0 0结束)\n");
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
