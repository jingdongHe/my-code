#include<stdio.h>
#include<time.h> 
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn=52;
bool used[maxn];
bool cmp(int a,int b)
{
	int k=maxn/4;
	if(a/k==b/k)
		return a%k<b%k;
	return a/k<b/k;
}
void Sort(int pai[])
{
	int k=maxn/4;
	sort(pai,pai+k,cmp);
	sort(pai+k,pai+2*k,cmp);
	sort(pai+2*k,pai+3*k,cmp);
	sort(pai+3*k,pai+4*k,cmp);
}
void Print(int pai[])
{
	int i,k=maxn/4;
	for(i=0;i<maxn;i++)
	{
		if(pai[i]/k==0)
			printf("ºÚÌÒ");
		if(pai[i]/k==1)
			printf("ºìÐÄ");
		if(pai[i]/k==2)
			printf("Ã·»¨");
		if(pai[i]/k==3)
			printf("·½¿é");
		int d=pai[i]%k;
		if(d+1==11)
			printf("J ");
		if(d+1==12)
			printf("Q ");
		if(d+1==13)
			printf("K ");
		if(d+1<=10)
			printf("%d ",d+1);
		if(i!=0&&(i+1)%k==0)
			printf("\n--------------------------------------\n");
	}
}
void Deal()
{
	int pai[maxn];
	memset(used,false,sizeof(used));
	srand((unsigned) time(NULL)); 
	int k=0;
	while(k<maxn)
	{
		int d=rand()%maxn;
		if(!used[d])
			pai[k++]=d;
		used[d]=true;
	}
	Sort(pai);
	Print(pai);
}
int main()
{
	Deal();
	return 0;
}