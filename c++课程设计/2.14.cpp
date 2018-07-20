/*　　　14. 有理数运算
　　　问题描述
　　　有理数是一个可以化为一个分数的数，例如2/3，533/920，-12/49都是有理数，
而就为无理数。在C++中，并没有预先定义有理数，需要时可以定义一个有理数类
，将有理数的分子和分母分别存放在两个整型变量中。对有理数的各种操作都可以用重载运算符来实现。
　　　基本要求
　　　定义并实现一个有理数类，通过重载运算符+、-、*、/对有理数进行算术运算，
通过重载运算符==实现判定两个有理数是否相等。写一个优化函数，它的作用是使有理数约去公分母，
也即是使保存的有理数分子和分母之间没有公约数（除去1以外）。此外，
还要定义一个将有理数转换为实数的函数，再加上构造函数和有理数输出函数。
　　　测试数据
　　　在应用程序中，创建若干有理数对象，通过带参数的构造函数使得各有理数对象值各不相同，
然后分别进行各类运算，输出运算结果，检验其正确性。
　　　实现提示
　　　设有两个有理数a/b和c/d，则有：
有理数相加  分子=a*d+b*c；分母=b*d
有理数相减  分子=a*d-b*c；分母=b*d
有理数相乘  分子=a*c；    分母=b*d
有理数相除  分子=a*d；    分母=b*c
　　　优化函数在创建有理数对象时应执行，在执行其它各种运算之后也需执行它，这样可保证所存储的有理数随时都是最优的。对于判断两个有理数是否相等，由于在对有理数进行各种运算后都对其进行优化，所以判定两个有理数是否相等只需判定它们两个的分子和分母分别相等即可。*/
#include<stdio.h>
class Rational{
private:
	int a,b;
public:
	int gcd(int a,int b)
	{
		if(a<b) {int temp;temp=a;a=b;b=temp;}
		return b==0?a:gcd(b,a%b);
	}
	void optimize(int &a,int &b)
	{
		int d=gcd(a,b);
		a/=d;b/=d;
	}
	Rational(int a,int b)
	{
		this->a=a;
		this->b=b;
		optimize(this->a,this->b);
	}
	Rational()
	{
	}
	void print()
	{
		printf("%d  %d\n",a,b);
	}
	double Todouble()
	{
		//print();
		return a*1.0/b;
	}
	Rational operator+(const Rational &add) const
	{
		Rational sum;
		sum.a=a*add.b+b*add.a;
		sum.b=b*add.b;
		return sum;
	}
	Rational operator-(const Rational &dif) const
	{
		Rational sum;
		sum.a=a*dif.b-b*dif.a;
		sum.b=b*dif.b;
		return sum;
	}
	Rational operator*(const Rational &mul) const
	{
		Rational sum;
		sum.a=a*mul.a;
		sum.b=b*mul.b;
		return sum;
	}
	Rational operator/(const Rational &div) const
	{
		Rational sum;
		sum.a=a*div.b;
		sum.b=b*div.a;
		return sum;
	}
	bool operator == (const Rational &equ) const
	{
		if(a==equ.a&&b==equ.b)
			return true;
		return false;
	}
};
int main()
{
	printf("Please entry two fractions\n");
	int a,b,c,d;char ch;
	scanf("%d%c%d%c%d%c%d",&a,&ch,&b,&ch,&c,&ch,&d);
	int a1=1,b1=2,c1=10,d1=20;
	Rational f1(a1,b1),f2(c1,d1),f3;
	f3=f2+f1;
	printf("(%d/%d)+(%d/%d)=%lf\n",a,b,c,d,f3.Todouble());
	f3=f1-f2;
	printf("(%d/%d)-(%d/%d)=%lf\n",a,b,c,d,f3.Todouble());
	f3=f1*f2;
	printf("(%d/%d)*(%d/%d)=%lf\n",a,b,c,d,f3.Todouble());
	f3=f1/f2;
	printf("(%d/%d)/(%d/%d)=%lf\n",a,b,c,d,f3.Todouble());
	if(f1==f2) printf("%d/%d==%d/%d\n",a,b,c,d);
	else printf("%d/%d!=%d/%d\n",a,b,c,d);
	return 0;
}