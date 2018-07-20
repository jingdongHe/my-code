#include<iostream>
#include<list>
using namespace std;
void print(list<char> a)
{
	for(list<char> ::iterator i=a.begin();i!=a.end();i++)
		cout<<*i;
	cout<<endl;
}
bool pm(list<char> a)
{
	if(*a.begin()=='-')
		return false;
	return true;
}
int no_sign_big(list<char> a,list<char> b)
{
	if(a.size()>b.size()) return 1;
	else if(a.size()<b.size()) return -1;
	else if(a.size()==b.size())
	{
		list<char> ::iterator i,j;
		for(i=a.begin(),j=b.begin();i!=a.end()&&j!=b.end();i++,j++)
		{
			if(*i>*j) return 1;
			else if(*i<*j) return -1;
		}
		return 0;
	}
}
int big(list<char> a,list<char> b)
{
	if(pm(a)==false&&pm(b)==true) return -1;
	else if(pm(a)==true&&pm(b)==false) return 1;
	else if(pm(a)==true&&pm(b)==true)
		return no_sign_big(a,b);
	else if(pm(a)==false&&pm(b)==false)
		return -1*no_sign_big(a,b);
}
/*list<char> add(list<char> a,list<char> b);
list<char> dec(list<char> a,list<char> b)//a-b
{
	if(pm(a)==true&&pm(b)==false)
		add(a,b);
	if(pm(a)==true&&pm(b)==true)
	{
		
	}
}*/
list<char> no_sign_dec(list<char> a,list<char> b)
{
	int Big=big(a,b);
	if(Big==1)
	{
		list<char> c;
		int s=0;
		list<char> ::iterator i,j;
		list<char> ::iterator A=a.begin(),B=b.begin();
		A--;B--;
		for(i=a.end(),j=b.end(),i--,j--;i!=A&&j!=B;i--,j--)
		{
			int k=*i-*j-'0'+'0'-s;
			s=0;
			while(k<0){s++;k+=10;}
			c.push_front(k+'0');
		}
		while(i!=A)
		{
			int k=*i-'0'-s;
			s=0;
			while(k<0){s++;k+=10;}
			c.push_front(k+'0');
			i--;
		}
		while(*c.begin()=='0') c.erase(c.begin());
		return c;
	}
	else if(Big==0){list<char> c;c.push_front('0');return c;}
	else if(Big==-1){list<char> c=no_sign_dec(b,a);c.push_front('-');return c;}
}
list<char> no_sign_add(list<char> a,list<char> b)
{
	list<char> c;
	int s=0;
	list<char> ::iterator i,j,Ab,Bb;
	Ab=a.begin();Bb=b.begin();Ab--;Bb--;	
	for(i=a.end(),j=b.end(),i--,j--;i!=Ab&&j!=Bb;i--,j--)
	{
		int k=*i+*j-2*'0'+s;
		c.push_front(k%10+'0');
		s=k/10;
	}
	while(i!=Ab)
	{
		int k=*i-'0'+s;
		c.push_front(k%10+'0');
		s=k/10;
		i--;
	}
	while(j!=Bb)
	{
		int k=*j-'0'+s;
		c.push_front(k%10+'0');
		s=k/10;
		j--;
	}
	if(s) c.push_front(s+'0');
	return c;
}
list<char> add(list<char> a,list<char> b)
{
	list<char> c;
	int s=0;
	list<char> ::iterator i,j,Ab,Bb;
	if(pm(a)==true&&pm(b)==true)
		return no_sign_add(a,b);
	else if(pm(a)==false&&pm(b)==false)
	{
		a.erase(a.begin());b.erase(b.begin());
		list<char> c=no_sign_add(a,b);
		c.push_front('-');
		return c;
	}
	else if(pm(a)==true&&pm(b)==false)
	{
		b.erase(b.begin());
		return no_sign_dec(a,b);
	}
	else if(pm(a)==false&&pm(b)==true)
	{
		a.erase(a.begin());
		return no_sign_dec(b,a);
	}
}
list<char> dec(list<char> a,list<char> b)//a-b
{
	if(pm(a)==true&&pm(b)==true)
	{
		int Big=big(a,b);
		if(Big==1)
			return no_sign_dec(a,b);
		else if(Big==0) {list<char> c;c.push_front('0');return c;}
		else if(Big==-1) {list<char> c=no_sign_dec(b,a);c.push_front('-');return c;}
	}
	else if(pm(a)==true&&pm(b)==false)
	{
		b.erase(b.begin());
		return no_sign_add(a,b);
	}
	else if(pm(a)==false&&pm(b)==true)
	{
		a.erase(a.begin());
		list<char> c=no_sign_add(a,b);
		c.push_front('-');
		return c;
	}
	else if(pm(a)==false&&pm(b)==false)
	{
		a.erase(a.begin());
		b.erase(b.begin());
		return dec(b,a);
	}
}
int main()
{
	string A,B;
	
	while(cin>>A>>B)
	{
	list<char> a,b;
	for(int i=0;i<A.size();i++)
		a.push_back(A[i]);
	for(int i=0;i<B.size();i++)
		b.push_back(B[i]);
	/*if(pm(a)==false)
		a.erase(a.begin());
	list<char>:: iterator i,j;
	for(i=a.begin();i!=a.end();i++)
		cout<<*i;
	cout<<endl;
	for(i=b.begin();i!=b.end();i++)
		cout<<*i;*/
	list<char> c=add(a,b);
	list<char>:: iterator i;
	for(i=c.begin();i!=c.end();i++)
		cout<<*i;
	cout<<endl;
	c=dec(a,b);
	for(i=c.begin();i!=c.end();i++)
		cout<<*i;
	cout<<"\n---------------------------------\n";
	}
	/*list<char> c=add(a,b);
	list<char>:: iterator i;
	for(i=c.begin();i!=c.end();i++)
		cout<<*i;*/
	return 0;
}
