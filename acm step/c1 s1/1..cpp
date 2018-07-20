#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	int number[100000+10];
	while(scanf("%d",&n)!=EOF)
	{
	for(int i=0;i<n;i++)
		scanf("%d",&number[i]);
	sort(number,number+n);
	printf("%d\n",number[n/2]);
	}
	return 0;
}
