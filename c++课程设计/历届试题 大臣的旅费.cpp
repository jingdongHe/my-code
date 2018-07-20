/*问题描述
很久以前，T王国空前繁荣。为了更好地管理国家，王国修建了大量的快速路，用于连接首都和王国内的各大城市。
为节省经费，T国的大臣们经过思考，制定了一套优秀的修建方案，使得任何一个大城市都能从首都直接或者通过其他大城市间接到达。同时，如果不重复经过大城市，从首都到达每个大城市的方案都是唯一的。
J是T国重要大臣，他巡查于各大城市之间，体察民情。所以，从一个城市马不停蹄地到另一个城市成了J最常做的事情。他有一个钱袋，用于存放往来城市间的路费。
聪明的J发现，如果不在某个城市停下来修整，在连续行进过程中，他所花的路费与他已走过的距离有关，在走第x千米到第x+1千米这一千米中（x是整数），他花费的路费是x+10这么多。也就是说走1千米花费11，走2千米要花费23。
J大臣想知道：他从某一个城市出发，中间不休息，到达另一个城市，所有可能花费的路费中最多是多少呢？ 
输入格式
输入的第一行包含一个整数n，表示包括首都在内的T王国的城市数
城市从1开始依次编号，1号城市为首都。
接下来n-1行，描述T国的高速路（T国的高速路一定是n-1条）
每行三个整数Pi, Qi, Di，表示城市Pi和城市Qi之间有一条高速路，长度为Di千米。
输出格式
输出一个整数，表示大臣J最多花费的路费是多少。
样例输入1
5
1 2 2
1 3 1
2 4 5
2 5 4
样例输出1
135
输出格式
大臣J从城市4到城市5要花费135的路费。
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const INF=999999;
class result {
private:
	int n,*array;
public:
	result()
	{
		scanf("%d",&n);
		array=(int *)malloc(sizeof(int)*n*(n+1));
	}
	int change(int a)
	{
		int d=0;
		d+=a*10;
		d+=((1+a)*a)/2;
		return d;
	}
	void insert()
	{
		int i;
		int a,b,dis;
		for(i=0;i<n*n;i++)
		{
			array[i]=INF;
		}
		for(i=0;i<n;i++)
			array[i*n+i]=0;
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d%d",&a,&b,&dis);
			a--;b--;
			array[a*n+b]=array[b*n+a]=dis;
		}
	}
	void floyd()
	{
		int i,j,k;
		for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					int d=array[i*n+k]+array[k*n+j];
					if(d<array[i*n+j])
						array[i*n+j]=d;
				}
			}
		}
	}
	int find()
	{
		int i,j;
		int k=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(array[i*n+j]!=INF&&array[i*n+j]>k)
					k=array[i*n+j];
			}
		}
		return k;
	}
};
int main()
{
	result r;
	r.insert();
	r.floyd();
	printf("%d\n",r.change(r.find()));
	return 0;
}
