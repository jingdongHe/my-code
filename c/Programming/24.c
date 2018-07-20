/*题目24：两个字符串S和T，称按照字典序S > T, 
如果T是S的前缀，或者存在整数i，使对于j < i有S[j]=T[j],
 但S[i] > T[i]。例如字符串"abcd" >"abc" >"abbd"。
 请编写程序，输入一个任意的字符串，输出它的按照字典序最大的子串
 。这里对子串的理解见题目13，例如输入字符串dcbadcbbd, 
 应输出dcbbd；输入abbasd, 应输出sd。（本题为2011年ACM大赛题目。）
提示：本题属于比较容易，直接解法是检查所有子串，但显然可以优先考虑较大字符引起的字符串。*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#define n 20
int sp(char a[],char b[])
{
	int k1,k2,k,i,d=0;
	k1=strlen(a);
	k2=strlen(b);
	k=k1>k2?k1:k2;
	for(i=0;i<k;i++)
	{
		if(a[i]<b[i])
			return -1;
		if(a[i]==b[i])
			d++;
	}
	if(d==k)
		return 0;
	return 1;
}
void output(char a[])
{
	int k,i;
	k=strlen(a);
	for(i=0;i<k;i++)
		printf("%c",a[i]);
	printf("\n");
}
void Break(char a[])
{
	char b[n]={'\0'},c[n];
	int i,j,k,r,f;
	k=strlen(a);
	memset(c,'\0',sizeof(c));
	for(i=1;i<=k;i++)//子串长度为i
	{
		//printf("22222\n");
		for(j=0;j<k-i+1;j++)//子串起始位置为j
		{
			for(r=0;r<i;r++)
			{b[r]=a[j+r];}
			//output(b);
			if(sp(b,c)>0)//c小于b
			{
				memset(c,'\0',sizeof(c));
				strcpy(c,b);
			}
		}
	}
	puts(c);
}
void main()
{
	char a[n]={'\0'};
	printf("请输入字符串\n");
	scanf("%s",&a);getchar();
	Break(a);
}