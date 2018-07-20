/*������14. ����������
��������������
��������������һ�����Ի�Ϊһ����������������2/3��533/920��-12/49������������
����Ϊ����������C++�У���û��Ԥ�ȶ�������������Ҫʱ���Զ���һ����������
�����������ķ��Ӻͷ�ĸ�ֱ������������ͱ����С����������ĸ��ֲ����������������������ʵ�֡�
����������Ҫ��
���������岢ʵ��һ���������࣬ͨ�����������+��-��*��/�������������������㣬
ͨ�����������==ʵ���ж������������Ƿ���ȡ�дһ���Ż�����������������ʹ������Լȥ����ĸ��
Ҳ����ʹ��������������Ӻͷ�ĸ֮��û�й�Լ������ȥ1���⣩�����⣬
��Ҫ����һ����������ת��Ϊʵ���ĺ������ټ��Ϲ��캯�������������������
��������������
��������Ӧ�ó����У�������������������ͨ���������Ĺ��캯��ʹ�ø�����������ֵ������ͬ��
Ȼ��ֱ���и������㣬�������������������ȷ�ԡ�
������ʵ����ʾ
��������������������a/b��c/d�����У�
���������  ����=a*d+b*c����ĸ=b*d
���������  ����=a*d-b*c����ĸ=b*d
���������  ����=a*c��    ��ĸ=b*d
���������  ����=a*d��    ��ĸ=b*c
�������Ż������ڴ�������������ʱӦִ�У���ִ��������������֮��Ҳ��ִ�����������ɱ�֤���洢����������ʱ�������ŵġ������ж������������Ƿ���ȣ������ڶ����������и�������󶼶�������Ż��������ж������������Ƿ����ֻ���ж����������ķ��Ӻͷ�ĸ�ֱ���ȼ��ɡ�*/
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