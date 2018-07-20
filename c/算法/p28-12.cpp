#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int n,b,M=0;//b为金额上限，n为配件数目,m为种类数量
typedef struct node {
	int price,qualit;
	char typ[20];
	int type;
}acc;
acc A[1000];
bool com1(acc x,acc y)//品质增排
{
	return x.qualit<y.qualit;
}
int full(int a[])
{
	int i;
	for(i=0;i<M;i++)
	{
		if(a[i]==0)
			return 0;
	}
	return 1;
}
int ok(int i)
{
	int sum=0;
	int a[1000]={0};
	for(;i<n;i++)
	{
		if(a[A[i].type]==0||(a[A[i].type]!=0&&A[i].price<a[A[i].type]))
		{
			//printf("%d   %d......",A[i].type,A[i].price);
			sum-=a[A[i].type];
			sum+=A[i].price;
			a[A[i].type]=A[i].price;
		}
	}
	/*if(full(a))
		printf("F   ");
	else
		printf("N   ");
	printf("%d\n",sum);*/
	if(sum<=b&&full(a))
		return 1;
	return 0;
}
int main()
{
	int i,j,max;
	scanf("%d%d",&n,&b);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%s",&A[i].price,&A[i].qualit,&A[i].typ);//录入信息
		max=-1;
		for(j=0;j<i;j++)
		{
			if(strcmp(A[i].typ,A[j].typ)==0)
			{
				A[i].type=A[j].type;
				max=-2;
				break;
			}
			if(A[j].type>max)
				max=A[j].type;
		}
		if(max!=-2)
		{
			A[i].type=max+1;
			M=max+1;
		}
	}
	M++;
	sort(A,A+n,com1);
	/*printf("%d   %d\n",n,b);
	for(i=0;i<n;i++)
		printf("%d  %d  %s  %d\n",A[i].price,A[i].qualit,A[i].typ,A[i].type);*/
	for(i=0;i<n;i++)
	{
		if(!ok(i))
			break;
	}
	printf("%d\n",A[i-1].qualit);
	return 0;
}

