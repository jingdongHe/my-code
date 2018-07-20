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
list<char> mul(list<char> a,list<char> b);
list<char> no_sign_mul(list<char> a,list<char> b)
{
	/*print(a);print(b);
	cout<<"\n----------------\n";*/
	if(*a.begin()=='0'||*b.begin()=='0')
	{
		list<char> c;
		c.push_back('0');
		return c;
	}
	else if(a.size()==1&&b.size()==1)
	{
		list<char> c;
		int A=*a.begin()-'0',B=*b.begin()-'0';
		int C=A*B;
		while(C)
		{
			c.push_front(C%10+'0');
			C/=10;
		}
		return c;
	}
	else if(a.size()==1&&b.size()>1)
	{
		list<char> b1,b2;
		list<char> ::iterator q;
		int i;
		for(i=0,q=b.begin();i<b.size()/2;i++,q++)
			b1.push_back(*q);
		while(q!=b.end())
		{
			b2.push_back(*q);
			q++;
		}
		list<char> r1=no_sign_mul(a,b1),r2=no_sign_mul(a,b2);
		for(int i=0;i<b2.size();i++)
			r1.push_back('0');
		return add(r1,r2);
	}
	else if(a.size()>1&&b.size()==1)
		return no_sign_mul(b,a);
	else if(a.size()>1&&b.size()>1)
	{
		if(a.size()==b.size())
		{
			list<char> a1,a2,b1,b2;
			list<char> ::iterator q;
			int i;
			for(i=0,q=a.begin();i<a.size()/2;i++,q++)
				a1.push_back(*q);
			while(*q=='0') q++;
			if(q==a.end()) a2.push_back('0');
			while(q!=a.end())
			{
				a2.push_back(*q);
				q++;
			}
			for(i=0,q=b.begin();i<b.size()/2;i++,q++)
				b1.push_back(*q);
			while(*q=='0') q++;
			if(q==b.end()) b2.push_back('0');
			while(q!=b.end())
			{
				b2.push_back(*q);
				q++;
			}
			list<char> r1=no_sign_mul(a1,b1),r2=no_sign_mul(a2,b2);
			list<char> r3=mul(dec(a1,a2),dec(b2,b1));
			list<char> r4=add(add(r3,r1),r2);
			/*cout<<"r1:";print(r1);
			cout<<"r2:";print(r2);
			cout<<"r3:";print(r3);
			cout<<"r4:";print(r4);*/
			for(int i=0;i<a.size()-a.size()/2;i++)
				r4.push_back('0');
			for(int i=0;i<2*(int)(a.size()-a.size()/2);i++)
				r1.push_back('0');
			return add(add(r1,r4),r2);
		}
		else
		{
			if(a.size()>b.size())
			{
				list<char> a1,a2;
				list<char> ::iterator j;
				int i;
				for(i=0,j=a.begin();i<b.size();i++,j++)
					a1.push_back(*j);
				while(j!=a.end())
				{
					a2.push_back(*j);
					j++;
				}
				list<char> c1=no_sign_mul(a1,b),c2=no_sign_mul(a2,b);
				for(int i=0;i<a2.size();i++)
					c1.push_back('0');
				return add(c1,c2);
			}
			else
				return no_sign_mul(b,a);
		}
	}
}
list<char> mul(list<char> a,list<char> b)
{
	if(pm(a)&&pm(b))
		return no_sign_mul(a,b);
	else if(pm(a)==true&&pm(b)==false)
	{
		b.erase(b.begin());
		list<char> c=no_sign_mul(a,b);
		c.push_front('-');
		return c;
	}
	else if(pm(a)==false&&pm(b)==true)
		return mul(b,a);
	else if(pm(a)==false&&pm(b)==false)
	{
		a.erase(a.begin());
		b.erase(b.begin());
		return no_sign_mul(a,b);
	}
}
list<char> no_sign_div(list<char> a,list<char> b)//   a/b
{
	if(a.size()<b.size()){list<char> c;c.push_back('1');return c;}
	else if(a.size()==b.size())
	{
		if(big(a,b)<=0)  {list<char> c;c.push_back('1');return c;}
		else 
		{
			int k=0;
			while(big(a,b)>=0)
			{
				a=dec(a,b);k++;
			}
			list<char> c;c.push_back(k+'0');return c;
		}
	}
	else 
	{
		list<char> c,d;
		list<char> ::iterator i;
		
		for(i=a.begin();i!=a.end();i++)
		{
			int k=0;
			c.push_back(*i);
			if(*c.begin()=='0') c.erase(c.begin());
			while(big(c,b)>=0)
			{
				c=dec(c,b);k++;
			}
			if(k>9)
			{
				list<char> e;
				e.push_back(k/10+'0');
				d=add(d,e);
				k/=10;
			}
			d.push_back(k+'0');
		}
		while(*d.begin()=='0') d.erase(d.begin());
		return d;
	}
}
list<char> div(list<char> a,list<char> b)
{
	if(pm(a)==true&&pm(b)==true) return no_sign_div(a,b);
	else if(pm(a)==true&&pm(b)==false)
	{
		b.erase(b.begin());
		list<char> c=no_sign_div(a,b);
		c.push_front('-');
	}
	else if(pm(a)==false&&pm(b)==true)
		return div(b,a);
	else if(pm(a)==false&&pm(b)==false)
	{
		a.erase(a.begin());
		b.erase(b.begin());
		return no_sign_div(a,b);
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
	list<char> c=mul(a,b);
	list<char> ::iterator i;
	for(i=c.begin();i!=c.end();i++)
		cout<<*i;
	cout<<"\n";
	}
}
