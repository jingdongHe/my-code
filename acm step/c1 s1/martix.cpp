#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int l,M;
class martix
{
private:
	int x,y;
	
public:
	int **mar;
	martix(int a,int b)
	{
		x=a;y=b;
		mar=new int *[x];
		for(int i=0;i<x;i++)
			mar[i]=new int[y];
	}
	void display()
	{
		for(int i=0;i<x;i++)
		{
			for(int j=0;j<y;j++)
				cout<<mar[i][j]<<"  ";
			cout<<endl;
		}
	}
	void clear()
	{
		for(int i=0;i<x;i++)
		{
			for(int j=0;j<y;j++)
				mar[i][j]=0;
		}
	}
	int getx()
	{
		return x;
	}
	int gety()
	{
		return y;
	}
};
martix martix_mul(martix a,martix b)
{
	martix c(a.getx(),b.gety());
	c.clear();
	for(int i=0;i<a.getx();i++)
	{
		for(int j=0;j<b.gety();j++)
		{
			for(int k=0;k<a.gety();k++)
			{
				c.mar[i][j]+=a.mar[i][k]*b.mar[k][j];
				c.mar[i][j]%=M;
			}
		}
	}
	return c;
}
string ten2two(int k)
{
	string s="";
	while(k)
	{
		s=(char)(k%2+'0')+s;
		k/=2;
	}
	return s;
}
int main()
{
	/*martix a(4,4),e(4,4),b(4,1);
	a.mar[0][0]=1;a.mar[0][1]=0;a.mar[0][2]=1;a.mar[0][3]=1;
	a.mar[1][0]=1;a.mar[1][1]=0;a.mar[1][2]=1;a.mar[1][3]=1;
	a.mar[2][0]=0;a.mar[2][1]=1;a.mar[2][2]=0;a.mar[2][3]=0;
	a.mar[3][0]=0;a.mar[3][1]=0;a.mar[3][2]=1;a.mar[3][3]=0;
	
	e.mar[0][0]=1;e.mar[0][1]=0;e.mar[0][2]=0;e.mar[0][3]=0;
	e.mar[1][0]=0;e.mar[1][1]=1;e.mar[1][2]=0;e.mar[1][3]=0;
	e.mar[2][0]=0;e.mar[2][1]=0;e.mar[2][2]=1;e.mar[2][3]=0;
	e.mar[3][0]=0;e.mar[3][1]=0;e.mar[3][2]=0;e.mar[3][3]=1;
	
	b.mar[0][0]=2;b.mar[0][1]=4;b.mar[0][2]=6;b.mar[0][3]=9;*/
	
	while(cin>>l>>M)
	{
		martix a(4,4),e(4,4),b(4,1);
		
		a.mar[0][0]=1;a.mar[0][1]=0;a.mar[0][2]=1;a.mar[0][3]=1;
		a.mar[1][0]=1;a.mar[1][1]=0;a.mar[1][2]=1;a.mar[1][3]=1;
		a.mar[2][0]=0;a.mar[2][1]=1;a.mar[2][2]=0;a.mar[2][3]=0;
		a.mar[3][0]=0;a.mar[3][1]=0;a.mar[3][2]=1;a.mar[3][3]=0;
		
		e.mar[0][0]=1;e.mar[0][1]=0;e.mar[0][2]=0;e.mar[0][3]=0;
		e.mar[1][0]=0;e.mar[1][1]=1;e.mar[1][2]=0;e.mar[1][3]=0;
		e.mar[2][0]=0;e.mar[2][1]=0;e.mar[2][2]=1;e.mar[2][3]=0;
		e.mar[3][0]=0;e.mar[3][1]=0;e.mar[3][2]=0;e.mar[3][3]=1;
		
		b.mar[0][0]=2;b.mar[1][0]=4;b.mar[2][0]=6;b.mar[3][0]=9;
	
		string s=ten2two(l);
		a.display();
		b.display();
		e.display();
		cout<<s<<endl;
		for(int i=s.size()-1;i>=0;i--)
		{
			if(s[i]=='1')
			{
				e=martix_mul(e,a);
			}
			a=martix_mul(a,a);
		}
		
		a=martix_mul(a,b);a.display();
		//cout<<a.mar[0][0]<<endl;
	}
	return 0;
}
