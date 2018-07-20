#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
typedef struct node {
	int loc;
	int dir;//0:turn;1:r;-1:l,2:fell off
	int number;
}node;
bool cmp_loc(node a,node b)
{
	return a.loc<b.loc;
}
bool cmp_number(node a,node b)
{
	return a.number<b.number;
}
int main()
{
	int L,T,n;
	int k,K;
	scanf("%d",&K);getchar();
	for(k=1;k<=K;k++)
	{
		//读入数据并稍微处理 
		scanf("%d%d%d",&L,&T,&n);getchar();
		node *array=(node *)malloc(sizeof(node)*(n+5));
		node *id=(node *)malloc(sizeof(node)*(n+5));
		for(int i=0;i<n;i++)
		{
			char ch;
			scanf("%d",&array[i].loc);getchar();ch=getchar();getchar();
			array[i].dir=ch=='R'?1:-1;
			array[i].number=i;
			id[i].loc=array[i].loc;
			id[i].number=i;
			array[i].loc+=array[i].dir*T;
		}
		
		//对原始数据排序，得出顺序
			
		//对于各点的状态判断 
		sort(array,array+n,cmp_loc);
		sort(id,id+n,cmp_loc);
		for(int i=0;i<n;i++)
		{
			if(array[i].loc<0||array[i].loc>L)
			{array[i].dir=2;continue;}
			if(i!=0&&array[i].loc==array[i-1].loc)
			{array[i].dir=0;array[i-1].dir=0;continue;}
			array[i].number=id[i].number;
		}
		
		//回复原来的排序，输出
		sort(array,array+n,cmp_number);
		printf("Case #%d:\n",k);
		for(int i=0;i<n;i++)
		{
			if(array[i].dir==2)
				printf("Fell off\n");
			else if(array[i].dir==0)
				printf("%d Turning\n",array[i].loc);
			else if(array[i].dir==1)
				printf("%d R\n",array[i].loc);
			else if(array[i].dir==-1)
				printf("%d L\n",array[i].loc);
		} 
		printf("\n");
	}
	return 0;
}
