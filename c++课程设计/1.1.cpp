/*1�����������������
    ����Ļ����'*'������ʾ0��360�ȵ�cos(x)���ߡ�����ؼ���������������0��360�ȵķ�Χ�ڣ�
	һ��Ҫ��ʾ�����㡣���ǵ�cos�ĶԳ��ԣ�����Ļ���з�����Ϊx���з�����Ϊy��
	��0��180�ȵ�ͼ�������ҶԳƵġ�����ͼ�ε��ܿ�ȶ���Ϊ62�У������x��0��180��ʱy�������m��
	��ô��ͬһ����֮�ԳƵ�180��360�ȵ�y��������ӦΪ62��m�����������÷����Һ���acos��������(x��y)�Ķ�Ӧ��ϵ��
*/
#include<stdio.h>
#include<math.h>
#include<string.h>
const double PI=acos(-1);
const int maxw=78;
const int maxh=22;
class Cos{
private:
	char map[maxh][maxw];
public:
	double RadToAngle(double a)
	{
		return a/180*PI;
	}
	void insit()
	{
		memset(map,'\0',sizeof(map));
	}
	void Print()
	{
		int i,j;
		for(i=0;i<maxh;i++)
		{
			for(j=0;j<maxw;j++)
				printf("%c",map[i][j]);
			printf("\n");
		}
	}
	void Drow()
	{
		double y;int y1;
		int i;
		insit();
		for(i=0;i<maxw;i++)
			map[maxh/2][i]='-';
		for(i=0;i<maxh;i++)
			map[i][maxw/2]='|';
		for(i=0;i<=15;i++)
		{
			y=cos(RadToAngle(i*12))*maxh/2;
			printf("%d  %lf\n",i*12,y);
				y1=(int) y;
			map[maxh/2-y1][i*2+maxw/2]='*';
			map[maxh/2-y1][maxw/2-i*2]='*';
		}
	}
};
int main()
{
	Cos c=Cos();
	c.Drow();
	c.Print();
	return 0;
}