/*1．横向绘制余弦曲线
    在屏幕上用'*'横向显示0～360度的cos(x)曲线。此题关键在于余弦曲线在0～360度的范围内，
	一行要显示两个点。考虑到cos的对称性，将屏幕的行方向定义为x，列方向定义为y，
	则0～180度的图形是左右对称的。若将图形的总宽度定义为62列，计算出x行0～180度时y点的坐标m，
	那么在同一行与之对称的180～360度的y点的坐标就应为62－m。程序中利用反余弦函数acos计算坐标(x，y)的对应关系。
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