#include<stdio.h>
const int maxn=1000+5;
int main()
{
	int s[maxn],f[maxn],m[maxn];
	s[1]=1;s[2]=2;
	f[2]=1;m[2]=1;
	for(int i=3;i<=1000;i++)
	{
		m[i]=s[i-1];
		f[i]=f[i-1]+1;
		s[i]=m[i]+f[i];
	}
	int n;
	while(scanf("%d",&n)!=EOF)
		printf("%d\n",s[n]);
	return 0;
}
