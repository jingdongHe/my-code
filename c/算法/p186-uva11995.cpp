#include<stack>
#include<queue>
#include<iostream>
using namespace std;
int main()
{
	int n,i;
	int k,x,d;
	int f[3];
	stack<int> s;
	queue<int> q;
	priority_queue<int> p;
	cin>>n;
	for(i=0;i<3;i++)
		f[i]=1;
	while(n--)
	{
		cin>>k>>x;
		if(k==1)
		{
			if(f[0]==1)
				s.push(x);
			if(f[1]==1)
				q.push(x);
			if(f[2]==1)
				p.push(x);
		}
		if(k==2)
		{
			if(f[0]==1)
			{
				if(!s.empty())
				{
					d=s.top();
					s.pop();
				}
				if(d!=x)
					f[0]=0;
			}
			if(f[1]==1)
			{
				if(!q.empty())
				{
					d=q.front();
					q.pop();
				}
				if(d!=x)
					f[1]=0;
			}
			if(f[2]==1)
			{
				if(!p.empty())
				{
					d=p.top();
					p.pop();
				}
				if(d!=x)
					f[2]=0;
			}
		}
	}
	k=0;
	for(i=0;i<3;i++)
	{
		cout<<f[i]<<" ";
	}
	cout<<endl;
	return 0;
}
			