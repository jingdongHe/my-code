#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
const int maxn=500000+5;
bool cmp(int a,int b)
{
	return abs(a)<abs(b);
}
int main()
{
	int n;
	int number[maxn];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&number[i]);
	sort(number,number+n,cmp);
	int k=1;
	if(number[0]>0)
	{
		for(int i=1;i<n;i++)
		{
			if(k&1&&number[i]<0)
				k++;
			if(k&1==0&&number[i]>0)
				k++;
		}
	}
	if(number[0]<0)
	{
		for(int i=1;i<n;i++)
		{
			if(k&1&&number[i]>0)
				k++;
			if(k&1==0&&number[i]<0)
				k++;
		}
	}
	printf("%d\n",k);
	return 0;
}
