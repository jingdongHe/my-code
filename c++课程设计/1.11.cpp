/*　　　11．地图着色
　　　地图上有不同国家（不同区域），每个国家都与其他一些国家邻接。现要求对地图着色，使所有的国家与它的邻接的国家有不同的颜色。
通常由四种颜色就已足够。
　　　提示：可采取试探的方法逐步逼近最后解，即按某种模式生成一个部分解，检查它是否合格。
如为合格，在扩展这个部分解向最后解逼近，否则为不合格，不管如何扩展这个部分解都不会得到最后解。
这时必须放弃已生成的部分解中的某些结果，“回朔”到先前的部分解，在生成一个部分解，直到获得最后解。
这种算法称为回朔算法。以着色一个六个区域的地图为例。*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int maxn=4;
class result{
private:
	int n;
	bool *array;
	int *contry;
public:
	void insert(int a,int b)
	{
		array[a*n+b]=true;
		array[b*n+a]=true;
	}
	result()
	{
		scanf("%d",&n);
		array=(bool *)malloc(sizeof(bool)*n*n);
		contry=(int *)malloc(sizeof(int)*n*n);
		int i;int a,b;
		for(i=0;i<n*n;i++)
			array[i]=false;
		for(i=0;i<n;i++)
			contry[i]=-1;
		printf("请输入点对，以-1，-1结束\n");
		scanf("%d%d",&a,&b);
		while(a!=-1&&b!=-1)
		{	a--;b--;
			insert(a,b);
			scanf("%d%d",&a,&b);
		}
	}
	void huishuo(int k)
	{
		int i,j;
		if(k>=n)
		{
			for(i=0;i<=n;i++)
			{
				if(contry[i]==0) printf("红 ");
				if(contry[i]==1) printf("蓝 ");
				if(contry[i]==2) printf("绿 ");
				if(contry[i]==3) printf("黄 ");
			}
			printf("\n");
			return;
		}
		int f;
		for(i=0;i<maxn;i++)
		{
			f=0;
			for(j=0;j<n;j++)
			{
				if(array[k*n+j]==true&&contry[j]==i)
				{f=1;break;}
			}
			if(f) continue;
			contry[k]=i;
			huishuo(k+1);
		}
	}
};
int main()
{
	result r;
	r.huishuo(0);
	return 0;
}