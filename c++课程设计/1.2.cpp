/*��2�������������ߺ�ֱ��
��������Ļ����ʾ0��360�ȵ�cos(x)������ֱ��f(x)=45*(x-1)+31�ĵ���ͼ�Ρ�
����cosͼ�Ρ�*����ʾ��f(x)�á�+����ʾ��������ͼ�ν���㴦����f(x)ͼ�εķ��š�
ͼ�ε��ӵĹؼ���Ҫ�ڷֱ�����ͬһ��������ͼ�ε��з���������
��ȷ�ж��໥��λ�ù�ϵ��Ϊ�ˣ��������ж�ͼ�εĽ��㣬�ٷֱ���ƴ�ӡ��ͬ��ͼ�Ρ�*/
#include<stdio.h>
#include<math.h>
#include<string.h>
const double PI=acos(-1);
const int maxw=78;
const int maxh=22;
char map[maxh][maxw];
class Cos{
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
class CosAndStraight : Cos
{
public:
	void CS_Drow()
	{
		Drow();
		for(int i=-15;i<=15;i++)
		{
			double k=(45*(PI*1.0/180*i-1)+39);
			int x=maxh/2-k,y=i*2+maxw/2;
			printf("%d   %d\n",x,y);
			if(x>=0&&x<=22&&y>=0&&y<=78)
				map[x][y]='+';
		}
	}
	void CS_Print()
	{
			int i,j;
		for(i=0;i<maxh;i++)
		{
			for(j=0;j<maxw;j++)
				printf("%c",map[i][j]);
			printf("\n");
		}
	}
};
int main()
{
	CosAndStraight c=CosAndStraight();
	c.CS_Drow();
	c.CS_Print();
	return 0;
}